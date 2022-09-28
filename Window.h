//
// Created by wewan on 21/09/2022.
//

#ifndef ACTIVITYTRACKER_WINDOW_H
#define ACTIVITYTRACKER_WINDOW_H

#include <Register.h>
#include <QWidget>
#include <QLabel>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

    signals:
    //void counterReached();

private slots:
    void slotInfoButtonClicked(bool checked);
private:
    //QPushButton *m_button;
    QPushButton *buttonInfo;
    QPushButton *buttonQuit;
    QLabel *label;
    QFont fontBig;
    QFont fontSmall;

    QList<Register> dropDownMenu;
};


#endif //ACTIVITYTRACKER_WINDOW_H
