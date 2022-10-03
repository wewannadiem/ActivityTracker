//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

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





