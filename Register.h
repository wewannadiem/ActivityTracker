//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"

class Register {
public:
    Register();

    ~Register();

    void setDate(short day, short month, short year);


private:
    short int day;
    short int month;
    short int year;

};


#endif //ACTIVITYTRACKER_REGISTER_H
