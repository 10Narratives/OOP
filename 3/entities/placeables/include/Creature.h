//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_CREATURE_H
#define LAB3_CREATURE_H

#include <atomic>
#include "Placeable.h"

struct Primary {
    int power = 0,
        ability = 0,
        endurance = 0,
        health_limit = 0,
        health = 0;

    Primary operator+(const Primary& other) const;
    Primary operator-(const Primary& other) const;

    bool operator==(const Primary &other) const;

    void be_loaded(json data);
    [[nodiscard]] json be_saved() const;
};

struct Secondary {
    int bonus_damage = 0,
        bonus_defence = 0,
        unlocking = 0,
        consumable_limit = 0;
};

class Creature : public  Placeable {
protected:
    Primary primary;
    Primary influence;
    Secondary secondary;
    int exp{};
    void compute_secondary();

public:
    Creature() = default;
    explicit Creature(std::pair<int, int> coords);
    ~Creature() override = default;

    [[nodiscard]] Primary get_primary() const;

    void set_primary(Primary new_primary);

    [[nodiscard]] Primary get_influence() const;

    [[nodiscard]] Secondary get_secondary() const;

    [[nodiscard]] int get_exp() const;

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    void get_damage(int damage_amount);

    virtual int deal_damage() = 0;

    virtual int resist() = 0;

    void hit(Creature& who);
};

#endif //LAB3_CREATURE_H
