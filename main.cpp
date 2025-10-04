#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

int fail_safe() {
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
void print_menu() {
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Check statistics.\n";
    std::cout << "3. Find value.\n";
    std::cout << "4. Sort values.\n";
    std::cout << "5. Exit.\n";
}

int menu_choice () {
    while (true) {
        print_menu();

        int choice;
        std::cout << "What would you like to do : ";
        choice = fail_safe();

        switch (choice) {
            case 1:
                std::cout << "Here you can input data.\n";
                std::cout << "Input :";
                break;
            case 2:
                std::cout << "Here you can see all the statistics.\n";
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


int input_sensor_values() {
    std::cout << "Please input your value :";
    int value = fail_safe();
    return value;
}
double variance_value (const std::vector<double>& data) {

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



int main() {
    menu_choice();


    return 0;
}