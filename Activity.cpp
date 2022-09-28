//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

Activity::Activity(QString name,QTime start, QTime end): name(name), startingTime(start), endingTime(end){
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

const QString &Activity::getName() const {
    return name;
}

void Activity::setName(const QString &name) {
    Activity::name = name;
}




