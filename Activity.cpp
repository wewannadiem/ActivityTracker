//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

Activity::Activity() : description(), starting_time(0000), ending_time(0000), day(1), month(1), year(2000) {

}

Activity::~Activity() {

}

// getters and setters

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

int Activity::getStartingTime() const {
    return starting_time;
}

void Activity::setStartingTime(int startingTime) {
    starting_time = startingTime;
}

int Activity::getEndingTime() const {
    return ending_time;
}

void Activity::setEndingTime(int endingTime) {
    ending_time = endingTime;
}

void Activity::setDate(short day, short month, short year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

