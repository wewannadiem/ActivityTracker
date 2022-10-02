#include <iostream>
#include "Register.h"
#include "Activity.h"
#include "Window.h"
#include <QApplication>
#include <QPushButton>
#include <QComboBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QLabel>
#include <QStringList>

// Registro di attività che memorizza cosa si è fatto durante una giornata. Classe che rappresenta attività con descrizione,
// tempo inizio e fine, Classe registro che colleziona attività su base del giorno. Interfaccia semplice per mostrare il
// registro sulla base di un giorno fatta con QT.

int main(int argc, char **argv) {

    QApplication app (argc, argv);
    Window window;

    //Create Register and add it to the DropDown Menu
    Register first("Monday");
    window.addRegister(&first);
    Register second("Tuesday");
    window.addRegister(&second);
    Register third("Wednesday");
    window.addRegister(&third);
    Register fourth("Thursday");
    window.addRegister(&fourth);
    Register fifth("Friday");
    window.addRegister(&fifth);
    Register sixth("Saturday");
    window.addRegister(&sixth);

    //Create Activity and add it to its Register
    Activity jogging("Jogging", QTime(8,30), QTime(9, 0));
    first.addActivity(jogging);
    Activity mondayStudies("Studying Economics", QTime(10,0), QTime(13,0));
    first.addActivity(mondayStudies);
    Activity mondayLunch("Lunch at the canteen", QTime(13,30), QTime(15,0));
    first.addActivity(mondayLunch);
    Activity mondayStudiesBis("Studying Biology", QTime(15,15), QTime(19,40));
    first.addActivity(mondayStudiesBis);
    Activity mondayDinner("Dinner with my friends", QTime(21,0), QTime(23,0));
    first.addActivity(mondayDinner);

    //DropDown menu
    QComboBox *mainDropDown;
    mainDropDown = new QComboBox(&window);
    mainDropDown->setGeometry(20, 100, 100, 40);
    mainDropDown->addItems(window.getRegisterNameList());

    //Table of content with Description, Starting Time and Ending Time
    QTableWidget *mainTable;
    mainTable = new QTableWidget(9,3, &window);
    mainTable->setGeometry(140, 100,350,300);
    mainTable->setColumnWidth(0,140);
    QStringList headers;
    headers.push_back("Description");
    headers.push_back("Beginning");
    headers.push_back("Ending");
    mainTable->setHorizontalHeaderLabels(headers);
    mainTable->setShowGrid(true);



    connect(mainDropDown, SIGNAL());

    //This if is easily done through a database where you can check the titles by scrolling an iterator
    //But I don't know how to do a Database... should I do a map? Having an index that can be iterated
    //and then check each "name" section

    /* while (i<n && found==false) {
     *      if ( [i].name == currentText() ){
     *          [...]
     *      }
     * }
    */

    /*
     * for (int j = 0; j < window.getRegisterList().size(); ++j) {
        if (mainDropDown->currentText() == window.getRegisterList()[j]->getName()){
            for (int i = 0; i < window.getRegisterList()[j]->getListActivities().size(); ++i) {
                QString *string1 = new QString(window.getRegisterList()[j]->getListActivities()[i]->getName());
                QTableWidgetItem *item1 = new QTableWidgetItem(*string1);
                mainTable->setItem(i,0, item1);

                QString *string2 = new QString(window.getRegisterList()[j]->getListActivities()[i]->getStartingTime().toString("h:mm"));
                QTableWidgetItem *item2 = new QTableWidgetItem(*string2);
                mainTable->setItem(i,1,item2);

                QString *string3 = new QString(window.getRegisterList()[j]->getListActivities()[i]->getEndingTime().toString("h:mm"));
                QTableWidgetItem *item3 = new QTableWidgetItem(*string3);
                mainTable->setItem(i,2,item3);
            }
        }
    }
     */

    /*
    if (mainDropDown->currentText() == first.getName()){
        mainTable->setItem(0,0,QTableWidgetItem(QString(first.getListActivities()[0]->getName())));
    }
     */
    window.show();
    return app.exec();


}
