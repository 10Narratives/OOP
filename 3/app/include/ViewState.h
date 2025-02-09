//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_VIEWSTATE_H
#define LAB3_VIEWSTATE_H

#include <memory>
#include "PlayerView.h"
#include "CellView.h"
#include "State.h"
#include "MapView.h"
#include "PlayerInfoView.h"
#include "PlayerInvView.h"
#include "AllChestsView.h"
#include "AllEnemiesView.h"

#include <SFML/Graphics.hpp>

class ViewState {
private:
    PlayerView player_view{};
    MapView map_view{};
    PlayerInfoView player_info_view{};
    PlayerInvView player_inv_view{};
    AllChestsView all_chests_view{};
    AllEnemiesView all_enemies_view{};

    std::shared_ptr<State> state_;

public:
    ViewState() = default;

    void set_state(const std::shared_ptr<State>& state);

    void redraw(std::shared_ptr<sf::RenderWindow>& window);

    void load(const std::string& file_path);
};

#endif //LAB3_VIEWSTATE_H
