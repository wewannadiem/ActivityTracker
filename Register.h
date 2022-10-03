//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include "vector"


class Register {
public:

    explicit Register(QString name);
    ~Register();

    // add Activity to the list of Activities of each day
    void addActivity(Activity &act);

    //getters only. No need to set them after construction
    const QString &getName() const;
    const std::vector<Activity *> &getListActivities() const;

private:
    QString name;
    std::vector<Activity*> listActivities;
};


#endif //ACTIVITYTRACKER_REGISTER_H