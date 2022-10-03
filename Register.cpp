//
// Created by wewan on 16/06/2022.
//

#include "Register.h"
#include "Window.h"

Register::Register(QString name): name(name) {

}

Register::~Register() {

}

//getters only
void Register::addActivity(Activity &act) {
    listActivities.push_back(&act);
}

const QString &Register::getName() const {
    return name;
}

const std::vector<Activity *> &Register::getListActivities() const {
    return listActivities;
}