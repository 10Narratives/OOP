//
// Created by vanish2 on 04.12.23.
//
#include <iostream>
#include "Service.h"
#include <thread>
#include <random>
#include <algorithm>

Service::Service(const std::shared_ptr<State>& state) : state(state) {}

int get_chest_index(const std::vector<Chest>& chests, std::pair<int, int> coords) {
    int index = -1;

    for(unsigned i = 0; i < chests.size(); i++) {
        if(chests[i].get_position() == coords) {
            index = int(i);
            break;
        }
    }

    return index;
}

int get_enemy_index(const std::vector<Enemy>& enemies, std::pair<int, int> coords) {
    int index = -1;

    for(unsigned i = 0; i < enemies.size(); i++) {
        if(enemies[i].get_position() == coords) {
            index = int(i);
            break;
        }
    }

    return index;
}

void Service::take_ground(std::pair<int, int> direction) {
    std::pair<int, int> future_position = this->state->get_player().get_position() + direction;

    if(get_chest_index(this->state->get_chests(), future_position) != -1) {
        if(this->state->get_player().get_key_amount() < 1)
            return;
        this->unlock(future_position);
        this->state->get_player().reduce_key_amount();
    }

    auto enemy_index = get_enemy_index(this->state->get_enemies(), future_position);
    if(enemy_index != -1) {
        auto& enemy = this->state->get_enemies()[enemy_index];
        this->state->get_player().hit(enemy);
        if(enemy.get_primary().health <= 0) {
            this->state->get_enemies().erase(this->state->get_enemies().begin() + enemy_index,
                                            this->state->get_enemies().begin() + enemy_index + 1);
        }
        return;
    }

    if(!this->state->get_map().get_cells()[future_position.second][future_position.first]) {
        this->move_player(future_position);
    }
}

void Service::move_player(std::pair<int, int> future_position) {
    this->state->get_player().be_moved(future_position);
}

void Service::upgrade_parameter(int num_of_parameter) {
    if(this->state->get_player().get_upgrade_points()  < 1)
        return;
    Primary upgrade_struct;
    if(num_of_parameter == Parameters::Power) { // upgrade power
        upgrade_struct.power = 1;
    } else if(num_of_parameter == Parameters::Ability) { // upgrade ability
        upgrade_struct.ability = 1;
    } else if(num_of_parameter == Parameters::Endurance) { // upgrade endurance
        upgrade_struct.endurance = 1;
    }
    this->state->get_player().upgrade_primary(upgrade_struct);
}

void Service::try_take() {
    auto player_x = this->state->get_player().get_x();
    auto player_y = this->state->get_player().get_y();
    auto curr_floor = this->state->get_map().get_cells()[player_y][player_x];
    if(curr_floor.get_inner_object() == nullptr)
        return;
    std::shared_ptr<Potion> read_potion = std::dynamic_pointer_cast<Potion>(curr_floor.get_inner_object());
    if(read_potion) {
        unsigned max_potions_size = this->state->get_player().get_secondary().consumable_limit;
        unsigned curr_potions_size = this->state->get_player().get_potions().size();
        if(curr_potions_size < max_potions_size) {
            this->state->get_player().take_potion(std::move(read_potion));
            this->state->get_map().get_cells()[player_y][player_x].set_inner_object(nullptr);
        }
    }
    std::shared_ptr<Key> read_key = std::dynamic_pointer_cast<Key>(curr_floor.get_inner_object());
    if(read_key) {
        this->state->get_player().inc_key_amount(read_key->get_amount());
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(nullptr);
    }
    std::shared_ptr<Weapon> read_weapon = std::dynamic_pointer_cast<Weapon>(curr_floor.get_inner_object());
    if(read_weapon) {
        auto tmp = this->state->get_player().throw_weapon();
        this->state->get_player().take_weapon(std::move(read_weapon));
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(tmp);
    }
    std::shared_ptr<Equipment> read_equipment = std::dynamic_pointer_cast<Equipment>(curr_floor.get_inner_object());
    if(read_equipment) {
        auto f_eq = this->state->get_player().get_equipments().find(read_equipment->get_placement());
        if(f_eq == this->state->get_player().get_equipments().end() || f_eq->second.second == nullptr) {
            this->state->get_player().take_equipment(std::move(read_equipment));
            this->state->get_map().get_cells()[player_y][player_x].set_inner_object(nullptr);
        } else {
            auto tmp = this->state->get_player().throw_equipment(read_equipment->get_placement());
            this->state->get_player().take_equipment(std::move(read_equipment));
            this->state->get_map().get_cells()[player_y][player_x].set_inner_object(tmp);
        }

    }
}

bool was_potion_selected(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions){
    for(const auto& p : potions) {
        if(p.first) {
            return true;
        }
    }
    return false;
}

bool was_weapon_selected(const std::pair<bool, std::shared_ptr<Weapon>>& weapon) {
    return weapon.first;
}

bool was_equipment_selected(const std::map<std::string, std::pair<bool, std::shared_ptr<Equipment>>>& equipments) {
    for(const auto & e : equipments) {
        if(e.second.first) {
            return true;
        }
    }
    return false;
}

bool was_something_selected(Player& player) {
    return was_potion_selected(player.get_potions()) || was_weapon_selected(player.get_weapon()) ||
            was_equipment_selected(player.get_equipments());
}

unsigned get_selected_potion_index(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions) {
    unsigned index = 0;
    for(unsigned i = 0; i < potions.size(); i++) {
        if(potions[i].first) {
            index = i;
            break;
        }
    }
    return index;
}

std::string
get_selected_equipment_placement(const std::map<std::string, std::pair<bool, std::shared_ptr<Equipment>>>& eqs) {
    std::string res;
    for(const auto & eq :eqs) {
        if(eq.second.first) {
            res = eq.first;
            break;
        }
    }
    return res;
}

void Service::try_throw() {
    auto player_x = this->state->get_player().get_x();
    auto player_y = this->state->get_player().get_y();
    auto curr_floor = this->state->get_map().get_cells()[player_y][player_x];
    if(curr_floor.get_inner_object() != nullptr)
        return;

    if(!was_something_selected(this->state->get_player())) return;

    if(was_potion_selected(this->state->get_player().get_potions())) {
        unsigned index = get_selected_potion_index(this->state->get_player().get_potions());
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
                this->state->get_player().throw_potion(index));
        return;
    }

    if(this->state->get_player().get_weapon().first) {
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
                this->state->get_player().throw_weapon());
        return;
    }

    if(was_equipment_selected(this->state->get_player().get_equipments())) {
        auto placement = get_selected_equipment_placement(this->state->get_player().get_equipments());
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
                this->state->get_player().throw_equipment(placement));
        return;
    }
}

void Service::select(std::pair<int, int> mouse_touch) {
    if(mouse_touch.second >= 400 + 24 && mouse_touch.second <= 432 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            unsigned index = (mouse_touch.first - 1290) / 32;
            auto potions_data = this->state->get_player().get_potions();

            if(potions_data.empty()) return;
            if(index >= potions_data.size()) index = potions_data.size() - 1;

            if(!potions_data.at(index).first) {
                if(!was_potion_selected(potions_data)) {
                    this->state->get_player().get_potions().at(index).first = true;
                }
            } else {
                this->state->get_player().get_potions().at(index).first = false;
            }
        }
    }
    if(mouse_touch.second >= 432 + 24 && mouse_touch.second <= 464 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            if(!this->state->get_player().get_weapon().first) {
                this->state->get_player().get_weapon().first = true;
            } else {
                this->state->get_player().get_weapon().first = false;
            };
        }
    }
    if(mouse_touch.second >= 464 + 24 && mouse_touch.second <= 496 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            auto find_record = this->state->get_player().get_equipments().find("head");
            if(find_record == this->state->get_player().get_equipments().end())
                return;

            if(this->state->get_player().get_equipments()["head"].first) {
                this->state->get_player().get_equipments()["head"].first = false;
            } else {
                this->state->get_player().get_equipments()["head"].first = true;
            }
        }
    }
    if(mouse_touch.second >= 496 + 24 && mouse_touch.second <= 528 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            auto find_record = this->state->get_player().get_equipments().find("body");
            if(find_record == this->state->get_player().get_equipments().end())
                return;

            if(this->state->get_player().get_equipments()["body"].first) {
                this->state->get_player().get_equipments()["body"].first = false;
            } else {
                this->state->get_player().get_equipments()["body"].first = true;
            }
        }
    }
    if(mouse_touch.second >= 528 + 24 && mouse_touch.second <= 560 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            auto find_record = this->state->get_player().get_equipments().find("legs");
            if(find_record == this->state->get_player().get_equipments().end())
                return;

            if(this->state->get_player().get_equipments()["legs"].first) {
                this->state->get_player().get_equipments()["legs"].first = false;
            } else {
                this->state->get_player().get_equipments()["legs"].first = true;
            }
        }
    }
    if(mouse_touch.second >= 560 + 24 && mouse_touch.second <= 592 + 24) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            auto find_record = this->state->get_player().get_equipments().find("hands");
            if(find_record == this->state->get_player().get_equipments().end())
                return;

            if(this->state->get_player().get_equipments()["hands"].first) {
                this->state->get_player().get_equipments()["hands"].first = false;
            } else {
                this->state->get_player().get_equipments()["hands"].first = true;
            }
        }
    }
}

void Service::drink() {
    if(!was_potion_selected(this->state->get_player().get_potions()))
        return;

    unsigned index = get_selected_potion_index(this->state->get_player().get_potions());
    this->state->get_player().drink(index);
}

void Service::unlock(std::pair<int, int> coords) {
    int index = get_chest_index(this->state->get_chests(), coords);
    if(index == -1) return;

    int resist_points = this->state->get_chests().at(index).get_level() * 5;
    int unlocking_points = this->state->get_player().get_secondary().unlocking * 3 + 10;
    if(resist_points > unlocking_points) {
        this->state->get_player().reduce_key_amount();
    } else {
        this->state->get_map().get_cells()[coords.first][coords.second].set_inner_object(
                this->state->get_chests()[index].get_inner_object()
                );
        this->state->get_chests().erase(this->state->get_chests().begin() + index,
                                        this->state->get_chests().begin() + index + 1);
    }
}

int Service::update_enemy(Enemy &enemy) {
    auto player = this->state->get_player();
    std::pair<int, int> p_pos = player.get_position();
    std::pair<int, int> e_pos = enemy.get_position();

    bool player_is_near = false;

    if(e_pos.first - 1 == p_pos.first && e_pos.second == p_pos.second)
        player_is_near = true;
    if(e_pos.first + 1 == p_pos.first && e_pos.second == p_pos.second)
        player_is_near = true;
    if(e_pos.first == p_pos.first && e_pos.second - 1 == p_pos.second)
        player_is_near = true;
    if(e_pos.first == p_pos.first && e_pos.second + 1 == p_pos.second)
        player_is_near = true;

    int damage = 0;
    if(player_is_near) {
        damage += enemy.deal_damage();
    }
    return damage;
}

int Service::sum_damage(std::vector<Enemy>::iterator first, std::vector<Enemy>::iterator last) {
    int res = 0;
    for(; first != last; ++first) {
        res += update_enemy(*first);
    }
    return res;
}

void Service::update_all_enemies() {
    auto thread_number = std::thread::hardware_concurrency();
    auto elements = std::distance(this->state->get_enemies().begin(), this->state->get_enemies().end());
    std::vector<int> results(thread_number);
    std::vector<std::thread> threads(thread_number);
    for(size_t i = 0; i < thread_number; i++) {
        size_t start_i = i * elements / thread_number;
        size_t end_i = (i + 1) * elements / thread_number;
        auto start = std::next(this->state->get_enemies().begin(), start_i);
        auto end = std::next(this->state->get_enemies().begin(), end_i);
        threads[i] = std::thread([=, &results](){
            results[i] = sum_damage(start, end);
        });
    }
    for(auto& th : threads) {
        th.join();
    }
    int all_damage = std::accumulate(results.begin(), results.end(), 0);
    this->state->get_player().get_damage(all_damage);
}





