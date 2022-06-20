//
// Created by wewan on 16/06/2022.
//

#include "Activity.h"

Activity::Activity(std::string &description, int starting_time_min, int starting_time_hour, int ending_time_min, int ending_time_hour, short day, short month, short year): year(year) {
    //control on hour format
    if (starting_time_min > 59 || starting_time_min < 0)
        this->starting_time_min = 9999;
    if (starting_time_hour > 23 || starting_time_hour < 0)
        this->starting_time_hour = 9999;
    if (ending_time_min > 59 || ending_time_min < 0)
        this->ending_time_min = 9999;
    if (ending_time_hour > 23 || ending_time_hour < 0)
        this->ending_time_hour = 9999;

    //control on date
    if (month > 12 || month < 0)
        this->month = 9999;

    if (month == 2) {
        if (year%4 == 0) {
            if (day > 29 || day < 0)
                this->day = 9999;
        }
        else
        if (day > 28 || day < 0)
            this->day = 9999;
    }

    if(month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day < 0)
            this->day = 9999;
    }
    else if (day>31 || day<0)
        this->day = 9999;



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

void Activity::setDate(short day, short month, short year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

