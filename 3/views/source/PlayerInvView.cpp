//
// Created by vanish2 on 09.12.23.
//

#include "PlayerInvView.h"
#include "PotionView.h"
#include "WeaponView.h"
#include "EquipmentView.h"

constexpr int font_size =  14;

#define LEFT_CORNER_X 1290
#define LEFT_CORNER_Y 400

void PlayerInvView::draw(std::shared_ptr<sf::RenderWindow> &window, Player& player) {
    sf::Text logo(
            "Inventory",
            this->font,
            font_size
    );
    logo.setPosition(LEFT_CORNER_X, LEFT_CORNER_Y);
    window->draw(logo);

    this->draw_potions(window, player);
    this->draw_weapon(window, player);
    this->draw_equipment(window, player);
}

void PlayerInvView::load_potions_asset(const std::string &file_path) {
    this->potions_asset.loadFromFile(file_path);
}

void PlayerInvView::load_font(const std::string &file_path) {
    this->font.loadFromFile(file_path);
}

void PlayerInvView::draw_potions(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    PotionView potion_view;
    auto potions = player.get_potions();
    for(unsigned i = 0; i < potions.size(); i++) {
        potion_view.set_sprite(this->potions_asset, potions[i].second);
        sf::Sprite potion_sprite = potion_view.get_sprite();
        float x_position = LEFT_CORNER_X + i * 32;
        float y_position = LEFT_CORNER_Y + 24;

        sf::RectangleShape layout;
        layout.setSize({32, 32});
        if(potions[i].first) {
            layout.setFillColor(sf::Color::Green);
        } else {
            layout.setFillColor(sf::Color::Black);
        }
        layout.setPosition({x_position, y_position});

        potion_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(layout);
        window->draw(potion_sprite);
    }
}

void PlayerInvView::draw_weapon(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    if(player.get_weapon().second == nullptr)
        return;
    WeaponView weapon_view;
    weapon_view.set_sprite(this->weapon_asset, player.get_weapon().second);
    sf::Sprite weapon_sprite = weapon_view.get_sprite();

    float x_position = LEFT_CORNER_X;
    float y_position = LEFT_CORNER_Y + 32 + 24;

    sf::RectangleShape layout;
    layout.setSize({32, 32});
    if(player.get_weapon().first) {
        layout.setFillColor(sf::Color::Green);
    } else {
        layout.setFillColor(sf::Color::Black);
    }
    layout.setPosition({x_position, y_position});

    sf::Text damage(
            std::string("Damage: ") + std::to_string(player.get_weapon().second->get_damage()),
            this->font,
            font_size
    );
    damage.setPosition(x_position + 64, y_position + 9);

    weapon_sprite.setPosition(
            x_position,
            y_position
    );
    window->draw(layout);
    window->draw(weapon_sprite);
    window->draw(damage);
}

void PlayerInvView::load_weapon_asset(const std::string &file_path) {
    this->weapon_asset.loadFromFile(file_path);
}

constexpr float eq_position_x = 1290;
constexpr float head_position_y = 464 + 24;
constexpr float body_position_y = 496 + 24;
constexpr float legs_position_y = 528 + 24;
constexpr float arms_position_y = 560 + 24;

void PlayerInvView::draw_element(std::shared_ptr<sf::RenderWindow>& window,
                                 const std::pair<bool, std::shared_ptr<Equipment>>& equipment) {
    EquipmentView equipment_view;
    equipment_view.set_sprite(equipment_asset, equipment.second);
    sf::Sprite sprite = equipment_view.get_sprite();

    sf::Vector2<float> sprite_position{eq_position_x, 0};
    if(equipment.second->get_placement() == "head") {
        sprite_position.y = head_position_y;
    } else if(equipment.second->get_placement() == "body") {
        sprite_position.y = body_position_y;
    } else if(equipment.second->get_placement() == "legs") {
        sprite_position.y = legs_position_y;
    } else if(equipment.second->get_placement() == "hands") {
        sprite_position.y = arms_position_y;
    }
    sprite.setPosition(sprite_position);

    sf::Text defence(
            std::string("Defence: ") + std::to_string(equipment.second->get_defence()),
            this->font,
            font_size
            );
    defence.setPosition(sprite_position.x + 64, sprite_position.y + 9);

    sf::RectangleShape layout;
    layout.setSize({32, 32});
    if(equipment.first) {
        layout.setFillColor(sf::Color::Green);
    } else {
        layout.setFillColor(sf::Color::Black);
    }
    layout.setPosition(sprite_position);

    window->draw(layout);
    window->draw(sprite);
    window->draw(defence);
}

void PlayerInvView::draw_equipment(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    auto equipments = player.get_equipments();
    for(const auto& record : player.get_equipments()) {
        if(record.second.second == nullptr) continue;
        draw_element(window, record.second);
    }
}

void PlayerInvView::load_equipment_asset(const std::string &file_path) {
    this->equipment_asset.loadFromFile(file_path);
}
