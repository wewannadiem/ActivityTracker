//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>
#include "vector"

class Activity {
public:

    Activity(std::string &description, int starting_time_min, int starting_time_hour, int ending_time_min, int ending_time_hour, short int day, short int month, short int year);

    ~Activity();

    // getters and setters
    const std::string &getDescription() const;
    void setDescription(const std::string &description);

    void setDate(short day, short month, short year);

private:
    std::string description;


    int starting_time_hour;
    int starting_time_min;

    int ending_time_min;
    int ending_time_hour;

    short int day;
    short int month;
    short int year;

};


#endif //ACTIVITYTRACKER_ACTIVITY_H
