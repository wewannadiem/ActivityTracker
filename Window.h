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

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    void addRegister(Register* reg);

    const QStringList &getRegisterNameList() const;
    const std::vector<Register *> &getRegisterList() const;
    QComboBox *getMainDropDown() const;

    void changeTable(QString newText);

private slots:
    void slotInfoButtonClicked(bool checked);
    void updateTable(QString newText);

private:
    QPushButton *buttonInfo;
    QTableWidget *mainTable;
    QComboBox *mainDropDown;
    QLabel *label;
    QFont fontBig;
    QFont fontSmall;

    QStringList registerNameList;
    std::vector<Register*> registerList;


};


#endif //ACTIVITYTRACKER_WINDOW_H
