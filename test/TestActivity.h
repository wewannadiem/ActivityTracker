//
// Created by wewan on 21/02/2023.
//

#ifndef ACTIVITYTRACKER_TESTACTIVITY_H
#define ACTIVITYTRACKER_TESTACTIVITY_H

#include <QTest>
#include "Activity.h"

class TestActivity : public QObject{
    Q_OBJECT

private slots:
    void testConstructor();
};


#endif //ACTIVITYTRACKER_TESTACTIVITY_H
