#include <iostream>
#include "Register.h"
#include "Activity.h"
#include "Window.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>


// Registro di attività che memorizza cosa si è fatto durante una giornata. Classe che rappresenta attività con descrizione,
// tempo inizio e fine, Classe registro che colleziona attività su base del giorno. Interfaccia semplice per mostrare il
// registro sulla base di un giorno fatta con QT.

int main(int argc, char **argv) {

    QApplication app (argc, argv);

    Window window;
    window.show();

    Register april;
    Activity jogging(QTime(8,30,0), QTime(9, 0,0));
    april.addActivity(jogging);

    return app.exec();


}
