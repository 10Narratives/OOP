//
// Created by vanish2 on 10.12.23.
//

#include "Key.h"

int Key::get_amount() const {
    return this->amount_;
}

void Key::be_loaded(json data) {
    Object::be_loaded(data);
    this->amount_ = data["amount"].get<unsigned>();
}

json Key::be_saved() const {
    json save_object =  Object::be_saved();
    save_object["amount"] = this->amount_;
    return save_object;
}


