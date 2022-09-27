//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

Activity::Activity(QDateTime start, QDateTime end): startingDate(start), endingDate(end){
}


Activity::~Activity() {}

// getters and setters

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const QDateTime &Activity::getStartingDate() const {
    return startingDate;
}

void Activity::setStartingDate(const QDateTime &startingDate) {
    Activity::startingDate = startingDate;
}

const QDateTime &Activity::getEndingDate() const {
    return endingDate;
}

void Activity::setEndingDate(const QDateTime &endingDate) {
    Activity::endingDate = endingDate;
}



