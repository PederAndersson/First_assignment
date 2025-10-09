

#include "functions.h"


int Functions::valid_input() { // function to validate that your input is a number not a letter
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

int Functions::input_sensor_value() { // function to input a new value.
    std::cout << "Please input your value :";
    int value = Functions::valid_input();
    return value;
}

bool Functions::run_again(){ // function to check if you want to run again.
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
    std::cout << "5. Number of errors.\n";
    std::cout << "6. Exit.\n";
}
