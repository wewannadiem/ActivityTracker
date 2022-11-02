//
// Created by wewan on 21/09/2022.
//

#ifndef ACTIVITYTRACKER_WINDOW_H
#define ACTIVITYTRACKER_WINDOW_H

#include <Register.h>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <memory>

class QPushButton;
class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void addRegister(Register* reg);

    const QStringList &getRegisterNameList() const;
    QComboBox *getMainDropDown() const;

private slots:

    void changeTable(QString newText);
    void slotInfoButtonClicked(bool checked);

private:
    QPushButton *buttonInfo;
    QTableWidget *mainTable;
    QComboBox *mainDropDown;
    QLabel *label;
    QFont fontBig;
    QFont fontSmall;

    QStringList registerNameList;
    std::vector<Register*> registerList;
    //togli raw pointer

};


#endif //ACTIVITYTRACKER_WINDOW_H
