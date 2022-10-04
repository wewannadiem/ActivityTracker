//
// Created by wewan on 21/09/2022.
//

#include "Window.h" //
#include <QApplication> //
#include <QPushButton> //
#include <iostream> //
#include <QLabel>
#include <QStringList>

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
    connect(buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    connect(mainDropDown, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changeTable(const QString &)));
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

void Window::changeTable(QString currentText) {
    mainTable->clearContents();

    //Control which Text from the menu has been selected
    for (int j = 0; j < this->getRegisterList().size(); ++j) {
        if (currentText == this->getRegisterList()[j]->getName()){

            //The Table is as long as it needs to be
            mainTable->setRowCount(this->getRegisterList()[j]->getListActivities().size());

            //Set the data
            for (int i = 0; i < this->getRegisterList()[j]->getListActivities().size(); ++i) {
                QString *string1 = new QString(this->getRegisterList()[j]->getListActivities()[i]->getName());
                QTableWidgetItem *item1 = new QTableWidgetItem(*string1);
                mainTable->setItem(i,0, item1);

                QString *string2 = new QString(this->getRegisterList()[j]->getListActivities()[i]->getStartingTime().toString("h:mm"));
                QTableWidgetItem *item2 = new QTableWidgetItem(*string2);
                mainTable->setItem(i,1,item2);

                QString *string3 = new QString(this->getRegisterList()[j]->getListActivities()[i]->getEndingTime().toString("h:mm"));
                QTableWidgetItem *item3 = new QTableWidgetItem(*string3);
                mainTable->setItem(i,2,item3);
            }
        }
    }
}


QComboBox *Window::getMainDropDown() const {
    return mainDropDown;
}
