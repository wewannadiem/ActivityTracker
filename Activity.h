//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>
#include "vector"
#include "QDateTime"

class Activity {
public:

    Activity(QDateTime start, QDateTime end);

    ~Activity();

    // getters and setters
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    const QDateTime &getStartingDate() const;
    void setStartingDate(const QDateTime &startingDate);
    const QDateTime &getEndingDate() const;
    void setEndingDate(const QDateTime &endingDate);


private:
    std::string description;
    QDateTime startingDate;
    QDateTime endingDate;


};


#endif //ACTIVITYTRACKER_ACTIVITY_H
