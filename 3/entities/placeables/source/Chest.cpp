//
// Created by vanish2 on 10.12.23.
//

#include "Chest.h"
#include "Potion.h"
#include "Key.h"

int Chest::get_level() const {
    return this->level_;
}

std::shared_ptr<Object> &Chest::get_inner_object() {
    return this->inner_object;
}

void Chest::be_loaded(json data) {
    Placeable::be_loaded(data);
    this->level_ = data["container"]["level"].get<int>();
    if(data["container"]["type"].get<std::string>() == "potion") {
        this->inner_object = std::make_shared<Potion>();
        this->inner_object->be_loaded(data["container"]["data"]);
    }
    if(data["container"]["type"].get<std::string>() == "key") {
        this->inner_object = std::make_shared<Key>();
        this->inner_object->be_loaded(data["container"]["data"]);
    }
}

/*json Chest::be_saved() const {
    json save_object =  Placeable::be_saved();

}*/


