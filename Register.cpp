//
// Created by wewan on 16/06/2022.
//

#include "Register.h"
#include "Window.h"
#include <iostream>

Register::Register(QString nameRegister): name(nameRegister) {

}
Register::~Register() {

}

void Register::addActivity(Activity &act) {
    int i = 0;
    bool found = false;
    while (i < listActivities.size() && !found){
        if (listActivities[i].getStartingTime() >= act.getStartingTime()){
            found = true;
        } else ++i;
    }
    listActivities.insert(listActivities.begin()+i, act);

    if (act.getStartingTime() > act.getEndingTime()){
        std::cout <<
                  name.toStdString() << ": " <<
                  act.getName().toStdString() <<
                  ": Cannot start after it ends" << std::endl;
    }
}

const QString &Register::getName() const {
    return name;
}

bool Register::searchActivity(Activity &act) {
    int i = 0;
    bool found = false;
    while (i < countActivity() && !found){
        if (&act == getActivity(i)){
            found = true;
        } else i++;
    }
    return found;
}

Activity *Register::getActivity(int i) {
    return &listActivities[i];
}

void Register::removeActivity(int i) {
    if (i < countActivity()) {
        listActivities.erase(listActivities.begin() + i);
    }
}

int Register::countActivity() {
    return listActivities.size();
}

int Register::getLengthListActivities() {
    return listActivities.size();
}
