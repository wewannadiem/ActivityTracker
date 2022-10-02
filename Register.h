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

    void addActivity(Activity &act);

    const QString &getName() const;
    void setName(const QString &name);

    const std::vector<Activity *> &getListActivities() const;

private:
    QString name;
    std::vector<Activity*> listActivities;
};


#endif //ACTIVITYTRACKER_REGISTER_H