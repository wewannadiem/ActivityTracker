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
    auto b = Activity(QString("Name1"), QTime(13,00), QTime(15,00));
    auto c = Activity(QString("Name2"), QTime(13,30), QTime(15,30));
    auto r = Register(QString("NameReg"));

    //check if the dimension of the list is updated after each addActivity
    QVERIFY(r.getLengthListActivities()==0);

    r.addActivity(a);
    QVERIFY(r.getLengthListActivities()==1);

    r.addActivity(b);
    QVERIFY(r.getLengthListActivities()==2);

    r.addActivity(c);
    QVERIFY(r.getLengthListActivities()==3);

    //check if the added activities are in their position and have been successfully added
    QVERIFY(r.getActivity(0)->isEqual(a));
    QVERIFY(r.getActivity(1)->isEqual(b));
    QVERIFY(r.getActivity(2)->isEqual(c));

}

void TestRegister::testRemoveActivity() {
    auto a = Activity(QString("NameA"), QTime(12,00), QTime(13,00));
    auto b = Activity(QString("Name1"), QTime(13,00), QTime(15,00));
    auto c = Activity(QString("Name2"), QTime(13,30), QTime(15,30));
    auto r = Register(QString("NameR"));

    //add one, remove one
    r.addActivity(a);
    QVERIFY(r.getLengthListActivities()==1);
    r.removeActivity(0);
    QVERIFY(r.getLengthListActivities()==0);

    //add two, check if they are two, remove from the end
    r.addActivity(b);
    r.addActivity(c);
    QVERIFY(r.getLengthListActivities()==2);
    r.removeActivity(1);
    r.removeActivity(0);
    QVERIFY(r.getLengthListActivities()==0);

    //add three, check if they are three, remove from the beginning
    r.addActivity(a);
    r.addActivity(b);
    r.addActivity(c);
    QVERIFY(r.getLengthListActivities()==3);
    r.removeActivity(0);
    r.removeActivity(0);
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
