//
// Created by wewan on 21/09/2022.
//

#ifndef ACTIVITYTRACKER_WINDOW_H
#define ACTIVITYTRACKER_WINDOW_H


#include <QWidget>

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
    //int m_counter;
    //QPushButton *m_button;
    QPushButton *buttonInfo;
    QPushButton *buttonQuit;
};


#endif //ACTIVITYTRACKER_WINDOW_H
