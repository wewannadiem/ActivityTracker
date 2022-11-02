//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"
#include <iostream>
#include <QTime>

Activity::Activity(QString name,QTime start, QTime end): name(name), startingTime(start), endingTime(end){

}

Activity::~Activity() {}

// getters only
const QTime &Activity::getStartingTime() const {
    return startingTime;
}
const QTime &Activity::getEndingTime() const {
    return endingTime;
}
const QString &Activity::getName() const {
    return name;
}

bool Activity::isEqual(Activity &act) {
    bool equal;
    if (name == act.getName() && startingTime==act.getStartingTime() && endingTime == act.getEndingTime()){
        equal = true;
    }
    else equal = false;
    return equal;
}