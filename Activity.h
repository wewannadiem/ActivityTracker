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

    Activity(QTime start, QTime end);
    ~Activity();

    // getters and setters
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    const QTime &getStartingTime() const;
    void setStartingTime(const QTime &startingTime);
    const QTime &getEndingTime() const;
    void setEndingTime(const QTime &endingTime);


private:
    std::string description;
    QTime startingTime;
    QTime endingTime;


};


#endif //ACTIVITYTRACKER_ACTIVITY_H
