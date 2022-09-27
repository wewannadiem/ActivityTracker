//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

Activity::Activity(QTime start, QTime end): startingTime(start), endingTime(end){
}

Activity::~Activity() {}

// getters and setters

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const QTime &Activity::getStartingTime() const {
    return startingTime;
}

void Activity::setStartingTime(const QTime &startingTime) {
    Activity::startingTime = startingTime;
}

const QTime &Activity::getEndingTime() const {
    return endingTime;
}

void Activity::setEndingTime(const QTime &endingTime) {
    Activity::endingTime = endingTime;
}




