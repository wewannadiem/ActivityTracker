#include <iostream>
#include "Register.h"
#include "Activity.h"
#include "Window.h"
#include <QApplication>
#include <QPushButton>


// Registro di attività che memorizza cosa si è fatto durante una giornata. Classe che rappresenta attività con descrizione,
// tempo inizio e fine, Classe registro che colleziona attività su base del giorno. Interfaccia semplice per mostrare il
// registro sulla base di un giorno fatta con QT.

int main(int argc, char **argv) {

    QApplication app (argc, argv);

    Window window;
    window.show();

    Register monday;
    Activity jogging("jogging", QTime(8,30,0), QTime(9, 0,0));
    monday.addActivity(jogging);

    return app.exec();


}
