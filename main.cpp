#include <iostream>
#include "Register.h"
#include "Activity.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Register dayOne;
    dayOne.setDate(8, 2, 2001);
    return 0;
}
