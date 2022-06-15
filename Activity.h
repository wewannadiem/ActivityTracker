//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>

class Activity {
public:

    Activity();

    ~Activity();

    // getters and setters
    const std::string &getDescription() const;
    void setDescription(const std::string &description);

    int getStartingTime() const;
    void setStartingTime(int startingTime);

    int getEndingTime() const;
    void setEndingTime(int endingTime);

    void setDate(short day, short month, short year);

private:
    std::string description;

// TODO think of a better type for the time

    int starting_time;
    int ending_time;
    short int day;
    short int month;
    short int year;

};


#endif //ACTIVITYTRACKER_ACTIVITY_H
