//
// Created by wewan on 21/02/2023.
//

#ifndef ACTIVITYTRACKER_TESTREGISTER_H
#define ACTIVITYTRACKER_TESTREGISTER_H

#include <QTest>
#include"Register.h"


class TestRegister : public QObject {
    Q_OBJECT

private slots:
    void testConstructor();
    void testAddActivity();
    void testRemoveActivity();
    void testRemoveNonExistingActivity();
};


#endif //ACTIVITYTRACKER_TESTREGISTER_H
