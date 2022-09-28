//
// Created by wewan on 21/09/2022.
//

#include "Window.h"
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QLabel>

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

    buttonQuit = new QPushButton("QUIT", this);
    buttonQuit->setGeometry(200, 150, 100, 50);
    buttonQuit->setCheckable(true);
    buttonQuit->setFont(fontBig);

    //Create and position a label
    label = new QLabel("Activity Tracker", this);
    label->setGeometry(130, 10, 500,50);
    label->setFont(fontBig);


    //TODO QComboBox Class, dropdown menu

    // Make the connection
    //connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    //connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));
    connect(buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    connect(buttonQuit, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(quit()));
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