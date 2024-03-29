//
// Created by wewan on 16/06/2022.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include "vector"


class Register {
public:

    explicit Register(QString nameRegister);
    ~Register();

    //getters only. No need to set them after construction
    const QString &getName() const;

    //cercare, aggiungere e togliere, contarle

    bool searchActivity(Activity &act);
    Activity* getActivity(int i);
    void addActivity(Activity &act);
    void removeActivity(int i);
    int countActivity();
    int getLengthListActivities();


private:
    QString name;
    std::vector<Activity> listActivities;


    //Done 1. remove raw pointers
    //Done 2. implement methods Search, Add, Remove, Count for Register, in order to adapt to the new structures
    //Done 3. grant that Activity has ending time later than starting time in constructor, show error.
    //Done 4. grant that Activities do not overlap in a register
    //Done 5. QT Unit Testing, for Register only.
};


#endif //ACTIVITYTRACKER_REGISTER_H