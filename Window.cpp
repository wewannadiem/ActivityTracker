//
// Created by wewan on 21/09/2022.
//

#include "Window.h"

#include <QApplication>
#include <QPushButton>
#include <iostream>

Window::Window(QWidget *parent) :
        QWidget(parent) {
    //set size of the window
    setFixedSize(300, 300);

    //Create and position the button
    /* m_button = new QPushButton("Kaboom, Riko. Kaboom.", this);
    m_button->setGeometry(350,200,200,50);
    m_button->setCheckable(true);*/

    buttonInfo = new QPushButton("INFO", this);
    buttonInfo->setGeometry(100, 50, 100, 50);
    buttonInfo->setCheckable(true);

    buttonQuit = new QPushButton("QUIT", this);
    buttonQuit->setGeometry(100, 100, 100, 50);
    buttonQuit->setCheckable(true);

    //m_counter = 0;

    // Make the connection
    //connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    //connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));
    connect(buttonInfo, SIGNAL(clicked(bool)), this, SLOT(slotInfoButtonClicked(bool)));
    connect(buttonQuit, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(quit()));
}

void Window::slotInfoButtonClicked(bool checked) {
    if(checked) {
        buttonInfo->setText("QT is pronounced CUTE, not CU - TEEH");
        buttonInfo->setGeometry(50, 50, 200,50);
    } else {
        buttonInfo->setText("INFO");
        buttonInfo->setGeometry(100, 50, 100, 50);
    }
/*
    m_counter++;
    std::cout<< m_counter <<std::endl;
    if (m_counter == 10) {
        emit counterReached();
    }
    */
}