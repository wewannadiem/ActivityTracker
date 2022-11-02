//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>
#include "vector"
#include "QTime"

class Activity {
public:

    Activity(QString name,QTime start, QTime end);
    ~Activity();

    // getters only. No need to set them after construction
    const QTime &getStartingTime() const;
    const QTime &getEndingTime() const;
    const QString &getName() const;
    bool isEqual(Activity &act);

private:
    QString name;
    QTime startingTime;
    QTime endingTime;


};


#endif //ACTIVITYTRACKER_ACTIVITY_H
