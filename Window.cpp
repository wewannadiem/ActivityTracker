//
// Created by wewan on 21/09/2022.
//

#include "Window.h"
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QLabel>
#include <QStringList>
#include <QTableWidget>
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

    //std::shared_ptr<QPushButton> buttonInfo(new QPushButton("INFO", this)) ;
    //this->buttonInfo = std::move(buttonInfo);
    buttonInfo = new QPushButton("INFO", this);
    buttonInfo->setGeometry(10, 410, 480, 80);
    buttonInfo->setCheckable(true);
    buttonInfo->setFont(fontBig);

    //Create and position a label
    label = new QLabel("Activity Tracker", this);
    label->setGeometry(130, 10, 500,50);
    label->setFont(fontBig);

    //Create DropDown menu
    mainDropDown = new QComboBox(this);
    mainDropDown->setGeometry(15, 100, 100, 40);

    //Create Table of contents
    mainTable = new QTableWidget(5,3, this);
    mainTable->setGeometry(130, 100,360,300);
    mainTable->setColumnWidth(0,140);
    QStringList headers;
    headers.push_back("Description");
    headers.push_back("Beginning");
    headers.push_back("Ending");
    mainTable->setHorizontalHeaderLabels(headers);


    // Make the connection
    //connect(*buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    connect(buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    connect(mainDropDown, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changeTable(const QString &)));
}

const QStringList &Window::getRegisterNameList() const {
    return registerNameList;
}
QComboBox *Window::getMainDropDown() const {
    return mainDropDown;
}

void Window::addRegister(Register* reg) {
    registerList.push_back(reg);
    registerNameList.push_back(reg->getName());
}

void Window::changeTable(QString currentText) {
    mainTable->clearContents();

    //Control which Text from the menu has been selected
    for (int j = 0; j < registerList.size(); ++j) {
        if (currentText == registerList[j]->getName()){

            //The Table is as long as it needs to be
            mainTable->setRowCount(registerList[j]->countActivity());

            //Set the data
            for (int i = 0; i < registerList[j]->countActivity(); ++i) {
                QString *string1 = new QString(registerList[j]->getActivity(i)->getName());
                QTableWidgetItem *item1 = new QTableWidgetItem(*string1);
                mainTable->setItem(i,0, item1);

                QString *string2 = new QString(registerList[j]->getActivity(i)->getStartingTime().toString("h:mm"));
                QTableWidgetItem *item2 = new QTableWidgetItem(*string2);
                mainTable->setItem(i,1,item2);

                QString *string3 = new QString(registerList[j]->getActivity(i)->getEndingTime().toString("h:mm"));
                QTableWidgetItem *item3 = new QTableWidgetItem(*string3);
                mainTable->setItem(i,2,item3);

                if (registerList[j]->getActivity(i)->getStartingTime() > registerList[j]->getActivity(i)->getEndingTime()) {
                    //mainTable->item(i, 1)->setText("Error");
                    //mainTable->item(i, 2)->setText("Error");
                    mainTable->item(i, 1)->setBackgroundColor("red");
                    mainTable->item(i, 2)->setBackgroundColor("red");
                }
            }

            for (int i = 1; i < registerList[j]->countActivity()-1; ++i){
                //Control if Activities overlaps
                if (registerList[j]->getActivity(i)->getEndingTime() > registerList[j]->getActivity(i+1)->getStartingTime()){
                    mainTable->item(i, 2)->setBackgroundColor("orange");
                    mainTable->item((i+1), 1)->setBackgroundColor("orange");
                }
                if (registerList[j]->getActivity(i)->getStartingTime() < registerList[j]->getActivity(i-1)->getEndingTime()){
                    mainTable->item(i, 1)->setBackgroundColor("orange");
                    mainTable->item((i-1), 2)->setBackgroundColor("orange");
                    std::cout << registerList[j]->getName().toStdString()
                              << ": "<< registerList[j]->getActivity(i)->getName().toStdString() <<
                              " and " << registerList[j]->getActivity(i-1)->getName().toStdString() <<
                              " overlap" << std::endl;
                }
            }
        }
    }
}

void Window::slotInfoButtonClicked(bool checked) {
    if(checked) {
        buttonInfo->setFont(fontSmall);
        buttonInfo->setText("Cristian Sician's project");
    } else {
        buttonInfo->setFont(fontBig);
        buttonInfo->setText("INFO");
    }
}

//Done, kinda 1. remove raw pointers
//Done 2. implement methods Search, Add, Remove, Count for Activity and Register, in order to adapt to the new structures
//Done 3. grant that Activity has ending time later than starting time in constructor, show error.
//Done 4. grant that Activities do not overlap in a register
//TODO 5. QT Unit Testing, for Register only.