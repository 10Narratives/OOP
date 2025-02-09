//
// Created by vanish2 on 05.12.23.
//

#include "PlayerInfoView.h"

constexpr float big_space_value = 50;
constexpr float space_value = 20;
constexpr int font_size = 15;

void PlayerInfoView::be_loaded(const std::string &file_path) {
    this->font.loadFromFile(file_path);
}

void PlayerInfoView::set_position(std::pair<float, float> new_position) {
    this->position = new_position;
}

void PlayerInfoView::draw(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    sf::Text health(
            std::string("Heat points:\t") + std::to_string(player.get_primary().health)
            + std::string("/") + std::to_string(player.get_primary().health_limit),
            this->font,
            font_size);

    sf::Text exp(
            std::string("Exp:\t") + std::to_string(player.get_exp())
            + std::string("/") + std::to_string(player.get_max_exp()),
            this->font,
            font_size);

    sf::Text level(
            std::string("Level:\t") + std::to_string(player.get_level()),
            this->font,
            font_size);

    sf::Text upgrade_points(
            std::string("Upgrade points:\t") + std::to_string(player.get_upgrade_points()),
            this->font,
            font_size);


    sf::Text primary_parameters(
            std::string("Primary parameters"),
            this->font,
            font_size
            );

    sf::Text power(
            std::string("Power:\t") + std::to_string(player.get_primary().power) + std::string(" + ")
            + std::to_string(player.get_influence().power),
            this->font,
            font_size);

    sf::Text ability(
            std::string("Ability:  \t") + std::to_string(player.get_primary().ability) + std::string(" + ")
            + std::to_string(player.get_influence().ability),
            this->font,
            font_size);

    sf::Text endurance(
            std::string("Endurance: \t") + std::to_string(player.get_primary().endurance)  + std::string(" + ")
            + std::to_string(player.get_influence().endurance),
            this->font,
            font_size);

    sf::Text computed_parameters(
            std::string("Computed parameters"),
            this->font,
            font_size
    );

    sf::Text bonus_damage(
            std::string("Damage: \t") + std::to_string(player.get_secondary().bonus_damage),
            this->font,
            font_size);

    sf::Text bonus_defence(
            std::string("Defence: \t") + std::to_string(player.get_secondary().bonus_defence),
            this->font,
            font_size);

    sf::Text unlocking(
            std::string("Unlocking: \t") + std::to_string(player.get_secondary().unlocking),
            this->font,
            font_size);

    sf::Text consumable_limit(
            std::string("Potions: \t") + std::to_string(player.get_potions().size())
            + std::string("/") + std::to_string(player.get_secondary().consumable_limit),
            this->font,
            font_size);

    sf::Text key_amount(
            std::string("Keys: \t") + std::to_string(player.get_key_amount()),
            this->font,
            font_size
            );

    health.setPosition(this->position.first + space_value, this->position.second + space_value);
    window->draw(health);

    exp.setPosition(this->position.first + space_value, this->position.second + 2 * space_value);
    window->draw(exp);

    level.setPosition(this->position.first + space_value, this->position.second + 3 * space_value);
    window->draw(level);

    upgrade_points.setPosition(this->position.first + space_value, this->position.second + 4 * space_value);
    window->draw(upgrade_points);

    primary_parameters.setPosition(
            this->position.first + space_value, this->position.second + 4 * space_value + big_space_value);
    window->draw(primary_parameters);

    power.setPosition(this->position.first + space_value, this->position.second + 5 * space_value + big_space_value);
    window->draw(power);

    ability.setPosition(this->position.first + space_value, this->position.second + 6 * space_value + big_space_value);
    window->draw(ability);

    endurance.setPosition(this->position.first + space_value, this->position.second + 7 * space_value + big_space_value);
    window->draw(endurance);

    computed_parameters.setPosition(this->position.first + space_value,
                                    this->position.second + 7 * space_value + 2 * big_space_value);
    window->draw(computed_parameters);

    bonus_damage.setPosition(this->position.first + space_value,
                             this->position.second + 8 * space_value + 2 * big_space_value);
    window->draw(bonus_damage);

    bonus_defence.setPosition(this->position.first + space_value,
                              this->position.second + 9 * space_value + 2 * big_space_value);
    window->draw(bonus_defence);

    unlocking.setPosition(this->position.first + space_value,
                          this->position.second + 10 * space_value + 2 * big_space_value);
    window->draw(unlocking);

    consumable_limit.setPosition(this->position.first + space_value,
                                 this->position.second + 11 * space_value + 2 * big_space_value);
    window->draw(consumable_limit);

    key_amount.setPosition(this->position.first + space_value,
                                 this->position.second + 12 * space_value + 2 * big_space_value);
    window->draw(key_amount);
}


