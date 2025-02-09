//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ENCHANTED_H
#define LAB3_ENCHANTED_H

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Enchanted{
private:
    std::string target_trait_;
    std::string avoid_trait_;
    int best_{1};
    int worst_{1};

public:
    Enchanted() = default;
    virtual ~Enchanted() = default;

    /**
     * @brief Getter for target trait
     * @return Target trait of Enchanted
     */
     [[nodiscard]] std::string get_target_trait() const;

     /**
      * @breif Getter for avoid trait
      * @return Avoid trait of Enchanted
      */
     [[nodiscard]] std::string get_avoid_trait() const;

     /**
      * @brief Getter for best
      * @return Factor in the best case
      */
     [[nodiscard]] int get_best() const;

     /**
      * @brief Setter for worst
      * @return Factor in the worst case
      */
     [[nodiscard]] int get_worst() const;

     /**
      * @breif Computes factor by gotten trait
      *
      * If gotten trait == target trait. Result - best factor
      * If gotten trait == avoid trait. Result - worst factor
      *  Else result - 1
      * @param trait Analyzing trait
      * @return Result of computing
      */
     int get_factor(const std::string& trait);

     /**
      * @breif Loads data about Enchanted from JSON object
      * @param data JSON object
      */
     void be_loaded(json data);
};


#endif //LAB3_ENCHANTED_H
