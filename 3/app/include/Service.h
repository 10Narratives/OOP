//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_SERVICE_H
#define LAB3_SERVICE_H

#include <memory>
#include <utility>

#include "State.h"

enum Parameters : int {
    Power,
    Ability,
    Endurance
};

class Service {
private:
    std::shared_ptr<State> state = std::make_shared<State>();

public:
    Service() = default;
    explicit Service(const std::shared_ptr<State>& state);

    void upgrade_parameter(int num_of_parameter);

    void take_ground(std::pair<int, int> direction);
    void move_player(std::pair<int, int> direction);
    void unlock(std::pair<int, int> coords);

    void try_take();
    void try_throw();
    void drink();
    void select(std::pair<int, int> mouse_touch);

    void update_all_enemies();
    /*void update_thread(std::vector<Enemy>::iterator first,
                       std::vector<Enemy>::iterator last, std::vector<Enemy>::iterator first_out);*/
    int sum_damage(std::vector<Enemy>::iterator first, std::vector<Enemy>::iterator last);
    int update_enemy(Enemy& enemy);

};

#endif //LAB3_SERVICE_H
