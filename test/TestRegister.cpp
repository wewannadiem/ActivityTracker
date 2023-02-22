//
// Created by wewan on 21/02/2023.
//

#include "TestRegister.h"

void TestRegister::testConstructor() {
    const auto n = QString("Name");

    auto r = Register(n);

    QVERIFY(r.getName() == n);
}

void TestRegister::testAddActivity() {
    auto a = Activity(QString("Name"), QTime(12,00), QTime(14,00));
    auto r = Register(QString("NameReg"));

    r.addActivity(a);

    QVERIFY(r.getActivity(0)->isEqual(a));

}

void TestRegister::testRemoveActivity() {
    auto a = Activity(QString("NameA"), QTime(12,00), QTime(13,00));
    auto r = Register(QString("NameR"));

    r.addActivity(a);
    r.removeActivity(0);

    QVERIFY(r.getLengthListActivities()==0);
}

void TestRegister::testRemoveNonExistingActivity() {
    auto a = Activity(QString("NameA"), QTime(12,00), QTime(13,00));
    auto r = Register(QString("NameR"));

    r.addActivity(a);
    r.removeActivity(4);

    QVERIFY(r.getLengthListActivities()==1);
}
