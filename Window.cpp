//
// Created by wewan on 21/09/2022.
//

#include "Window.h" //
#include <QApplication> //
#include <QPushButton> //
#include <iostream> //
#include <QLabel>
#include <QStringList>
#include <QTableWidgetItem>
#include "Register.h"

Window::Window(QWidget *parent) :
        QWidget(parent) {
    //set size of the window
    setFixedSize(500, 500);

    //Create a font
    fontBig.setPointSize(25);
    fontBig.setBold(true);

    fontSmall.setPointSize(15);

    //Create and position the buttons

    buttonInfo = new QPushButton("INFO", this);
    buttonInfo->setGeometry(10, 410, 480, 80);
    buttonInfo->setCheckable(true);
    buttonInfo->setFont(fontBig);

    /*
    buttonQuit = new QPushButton("QUIT", this);
    buttonQuit->setGeometry(200, 200, 100, 50);
    buttonQuit->setCheckable(true);
    buttonQuit->setFont(fontBig);
    */

    //Create and position a label
    label = new QLabel("Activity Tracker", this);
    label->setGeometry(130, 10, 500,50);
    label->setFont(fontBig);

    //Create DropDown menu



    // Make the connection
    //connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    //connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));

    connect(buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    //connect(buttonQuit, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(quit()));
}

void Window::slotInfoButtonClicked(bool checked) {
    if(checked) {
        buttonInfo->setFont(fontSmall);
        buttonInfo->setText("QT is pronounced CUTE, not CU - TEEH");
        //buttonInfo->setGeometry(50, 50, 200,50);
    } else {
        buttonInfo->setFont(fontBig);
        buttonInfo->setText("INFO");
        //buttonInfo->setGeometry(100, 50, 100, 50);
    }
}

const QStringList &Window::getRegisterNameList() const {
    return registerNameList;
}

void Window::addRegister(Register* reg) {
    registerList.push_back(reg);
    registerNameList.push_back(reg->getName());
}

const std::vector<Register *> &Window::getRegisterList() const {
    return registerList;
}

void Window::changeTable(Window *window, QComboBox *mainDropDown, QTableWidget *mainTable) {
    for (int j = 0; j < window->getRegisterList().size(); ++j) {
        if (mainDropDown->currentText() == window->getRegisterList()[j]->getName()){
            for (int i = 0; i < window->getRegisterList()[j]->getListActivities().size(); ++i) {
                QString *string1 = new QString(window->getRegisterList()[j]->getListActivities()[i]->getName());
                QTableWidgetItem *item1 = new QTableWidgetItem(*string1);
                mainTable->setItem(i,0, item1);

                QString *string2 = new QString(window->getRegisterList()[j]->getListActivities()[i]->getStartingTime().toString("h:mm"));
                QTableWidgetItem *item2 = new QTableWidgetItem(*string2);
                mainTable->setItem(i,1,item2);

                QString *string3 = new QString(window->getRegisterList()[j]->getListActivities()[i]->getEndingTime().toString("h:mm"));
                QTableWidgetItem *item3 = new QTableWidgetItem(*string3);
                mainTable->setItem(i,2,item3);
            }
        }
    }
}

void Window::updateTable(bool checked, Window *window, QComboBox *mainDropDown, QTableWidget *mainTable) {
    if(checked)
        Window::changeTable(window, mainDropDown, mainTable);

}
