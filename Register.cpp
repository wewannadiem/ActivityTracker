//
// Created by wewan on 16/06/2022.
//

#include "Register.h"

Register::Register() {

}

Register::~Register() {

}

void Register::setDate(short day, short month, short year) {
    this->day = day;
    this->month = month;
    this->year = year;
}
