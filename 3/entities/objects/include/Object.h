//
// Created by vanish2 on 06.12.23.
//

#ifndef LAB3_OBJECT_H
#define LAB3_OBJECT_H


#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Object {
protected:
    std::string name;

public:
    Object() = default;
    virtual ~Object() = default;

    explicit Object(const std::string &name);

    /**
     * @brief Getter for name of Object
     * @return Name of Object
     */
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Setter for name of Object
     * @param new_name Future name of Object
     */
    void set_name(const std::string& new_name);

    /**
     * @brief Loads data about Object from JSON object
     * @param data JSON object
     */
    virtual void be_loaded(json data);

    /**
     * @brief Saves data about Object into JSON object
     * @return JSON object
     */
    [[nodiscard]] virtual json be_saved() const;
};


#endif //LAB3_OBJECT_H
