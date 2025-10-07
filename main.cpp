
#include <iostream>
#include <iomanip>
#include "util.h"
#include "statistics.h"


int main() {
    std::cout << std::fixed << std::setprecision(2);
    statistics statistics = {};
    while (true) {
        Util::print_menu();
        std::cout << "What would you like to do : ";
        switch (Util::fail_safe()) {
            case 1:
                statistics.read_value();
                break;
            case 2:
                statistics.recalculate();
                statistics.print();
                break;
            case 3:
                std::cout << "Here we can find a specific value.\n";
                break;
            case 4:
                std::cout << "Here we can sort the value.\n";
                break;
            default:
                std::cout << "Have a good day.";
                return 0;
        }
    }
}