//
// Created by wewan on 21/02/2023.
//

#include "TestActivity.h"

void TestActivity::testConstructor() {
    const QString n = QString("Nome");
    const QTime s = QTime(12,00);
    const QTime e = QTime(14,00);

    auto a = Activity(n , s, e);

    QVERIFY(a.getName() == n);
    QVERIFY(a.getStartingTime() == s);
    QVERIFY(a.getEndingTime() == e);
}
