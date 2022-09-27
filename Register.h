//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include "vector"


class Register {
public:
    Register();

    ~Register();

    void addActivity(Activity &act);


private:
    std::vector<Activity*> list;
};


#endif //ACTIVITYTRACKER_REGISTER_H
