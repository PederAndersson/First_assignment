
#include <iostream>
#include <limits>
#include "functions.h"


int Functions::valid_input() {
    int y;
    while (true) {
        if (!(std::cin >> y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Please input a number instead.\n";
        } else {
            return y;
        }
    }
}

int input_sensor_value() {
    std::cout << "Please input your value :";
    int value = Functions::valid_input();
    return value;
}

bool go_again(){ // funktion för om man vill köra om programmet
    char answer;

    while (true) {
        std::cout << "Would you like to go again? (y/n) ";
        std::cin >> answer;
        char ch = answer;
        char lowercase = std::tolower(ch);
        if (std::isdigit(ch)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Only letters, Y or N." << std::endl;
        }else if (lowercase == 'n') {
            return false;
        }else if (lowercase == 'y') {
            return true;
        }else {
            std::cout << "Try again only Y or N." << std::endl;
        }
    }
}
void Functions::print_menu() {
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Check statistics.\n";
    std::cout << "3. Find value.\n";
    std::cout << "4. Sort values.\n";
    std::cout << "6. Exit.\n";
}

void Functions::print_stats(const & stats) {
    std::cout << "Here you can see all the statistics.\n";
    std::cout << "Number of entries :" << stats.number_entries << "\n";
    std::cout << "Sum :" << stats.sum << "\n";
    std::cout << "The average value :" << stats.mean << "\n";
    std::cout << "The highest value :" << stats.value_max << "\t the lowest value :" << stats.value_min << "\n";
    std::cout << "The variance :" << stats.variance << "\n";
    std::cout << "The standard deviation :" << stats.standard_dev << "\n";
}
