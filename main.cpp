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

    //Create Register and add it to the list of Registers for the DropDown menu
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
    //Monday
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

    //Tuesday
    Activity tuesdayStudies("Studying Math", QTime(9,30), QTime(12,30));
    second.addActivity(tuesdayStudies);
    Activity tuesdayLunch("Lunch at home", QTime(13,0), QTime(14,30));
    second.addActivity(tuesdayLunch);
    Activity tuesdayStudiesBis("Studying Science", QTime(15,00), QTime(20,20));
    second.addActivity(tuesdayStudiesBis);
    Activity tuesdayDinner("Dinner with my grandma", QTime(20,30), QTime(23,45));
    second.addActivity(tuesdayDinner);

    //Wednesday
    Activity wednesday_breakfast("Breakfast", QTime(8,00), QTime(8, 15));
    third.addActivity(wednesday_breakfast);
    Activity wednesday_laundry("Laundry", QTime(8,30), QTime(9, 15));
    third.addActivity(wednesday_laundry);
    Activity wednesday_cleaning("Cleaning the house", QTime(9,15), QTime(12, 00));
    third.addActivity(wednesday_cleaning);
    Activity wednesday_cooking("Cooking both lunch and dinner", QTime(12,00), QTime(14, 15));
    third.addActivity(wednesday_cooking);
    Activity wednesday_reading1("Reading Dostoevskij", QTime(14,30), QTime(16, 30));
    third.addActivity(wednesday_reading1);
    Activity wednesday_reading2("Reading Tolstoj", QTime(16,30), QTime(18, 30));
    third.addActivity(wednesday_reading2);
    Activity wednesday_reading3("Reading Pasternak", QTime(18,30), QTime(20, 30));
    third.addActivity(wednesday_reading3);
    Activity wednesday_bath("Long bath", QTime(20,30), QTime(21, 30));
    third.addActivity(wednesday_bath);
    Activity wednesday_nerding("Gaming", QTime(21,30), QTime(00, 00));
    third.addActivity(wednesday_nerding);

    //Thursday
    Activity thursday_brunch("Brunch", QTime(11,00), QTime(13, 30));
    fourth.addActivity(thursday_brunch);
    Activity thursday_barber("Barber", QTime(14,00), QTime(14, 30));
    fourth.addActivity(thursday_barber);
    Activity thursday_groceries("Grocery", QTime(14,45), QTime(17, 0));
    fourth.addActivity(thursday_groceries);
    Activity thursday_football("Football", QTime(17,15), QTime(19, 30));
    fourth.addActivity(thursday_football);
    Activity thursday_dinnerTeam("Dinner with the team", QTime(20,00), QTime(23, 30));
    fourth.addActivity(thursday_dinnerTeam);

    //Friday
    Activity friday_shower("Morning Shower", QTime(8,00), QTime(8, 30));
    fifth.addActivity(friday_shower);
    Activity friday_preparation("Luggage preparation", QTime(8,30), QTime(11, 30));
    fifth.addActivity(friday_preparation);
    Activity friday_train("Train to Milan", QTime(14,00), QTime(17, 30));
    fifth.addActivity(friday_train);
    Activity friday_concert("Concert Imagine Dragons", QTime(19,00), QTime(23, 30));
    fifth.addActivity(friday_concert);


    //Add the list of Register (with all the activities inside) in the DropDown menu
    window.getMainDropDown()->addItems(window.getRegisterNameList());

    window.show();
    return app.exec();


}