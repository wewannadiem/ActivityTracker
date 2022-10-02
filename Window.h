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
    void changeTable(Window *window, QComboBox *mainDropDown, QTableWidget *mainTable);

signals:

    //void counterReached();
private slots:
    void slotInfoButtonClicked(bool checked);
    void updateTable(bool checked, Window *window, QComboBox *mainDropDown, QTableWidget *mainTable);

private:
    //QPushButton *m_button;
    QPushButton *buttonInfo;
    //QPushButton *buttonQuit;
    QLabel *label;
    QFont fontBig;
    QFont fontSmall;

    QStringList registerNameList;
    std::vector<Register*> registerList;


};


#endif //ACTIVITYTRACKER_WINDOW_H
