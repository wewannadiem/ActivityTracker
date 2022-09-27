//
// Created by wewan on 16/06/2022.
//

#include "Register.h"

Register::Register() {

}

Register::~Register() {

}


void Register::addActivity(Activity &act) {
    list.push_back(&act);
}
