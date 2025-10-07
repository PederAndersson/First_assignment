#include "util.h"


int Util::fail_safe() { // checks the input to make sure it is an integer not a letter
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

int Util::input_sensor_values() { // inputs a new value while checking that it's a number
    std::cout << "Please input your value :";
    int value = fail_safe();
    return value;
}

bool Util::YesNo(){ // functions for if you want to go again
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

double Util::variance_value (const std::vector<double>& data) { // calculates the variance of the stored data

    if (data.empty()) return 0;

    double sum = 0.0;
    for (double x : data) {
        sum += x;
    }

    double mean = sum/data.size();

    double squarediff = 0.0;
    for (double x : data) {
        double diff = x - mean;
        squarediff += diff*diff;
    }

    return squarediff / data.size();
}

int Util::min_value(const std::vector<double>& store_value) { // checks for the smallest value in the stored data
    int min = store_value[0];
    for (int x : store_value) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}

int Util::max_value(const std::vector<double>& store_value) { // checks for the largest value in the stored data
    int max = store_value[0];
    for (int x : store_value) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

double Util::vector_sum(const std::vector<double>& store_value) { //calculates the sum of the stored data
    double sum = 0;
    for (double x : store_value) {
        sum += x;
    }
    return sum;
}

void Util::print_menu() { //prints the main menu
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Check statistics.\n";
    std::cout << "3. Find value.\n";
    std::cout << "4. Sort values.\n";
    std::cout << "5. Exit.\n";
}