//
// Created by vanish2 on 06.12.23.
//

#ifndef LAB3_POTION_H
#define LAB3_POTION_H


#include "Object.h"
#include "Drinkable.h"

class Potion : public Object, public Drinkable{
private:
    Primary potion_effect;

public:
    Potion() = default;
    Potion(const std::string& name, Primary new_potion_effect);
    ~Potion() override = default;

    /**
     * @brief Getter for potion effect
     * @return Potion effect
     */
    [[nodiscard]] Primary get_potion_effect() const;

    /**
     * @breif Setter for potion effect
     * @param new_potion_effect Future potion effect
     */
    void set_potion_effect(Primary new_potion_effect);

    /**
     * @brief Loads data about Potion about JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;

    /**
     * @breif Saves data into JSON object
     * @return JSON object
     */
    [[nodiscard]] json be_saved() const override;

    /**
     * @brief Realization of be_drunk
     * @return Potion effect
     */
    Primary be_drunk() override;
};


#endif //LAB3_POTION_H
