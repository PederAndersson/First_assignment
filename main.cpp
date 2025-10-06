#include <algorithm>
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
int min_value(const std::vector<double>& y) {
    int min = y[0];
    for (int x : y) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}
int max_value(const std::vector<double>& y) {
    int max = y[0];
    for (int x : y) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}
double vector_sum(const std::vector<double>& y) {
    double sum = 0;
    for (double x : y) {
        sum += x;
    }
    return sum;
}

struct Statistc_values {
    int number_entries;
    int sum;
    float mean;
    int value_min, value_max;
    double variance, standard_dev;

};



int main() {
    std::vector<double> store_value = {4, 6, 9, 5, 7, 6, 5};
    Statistc_values statistics;
    double sum = vector_sum(store_value);
    statistics.number_entries = store_value.size();
    statistics.sum = sum;
    statistics.mean = statistics.sum/store_value.size();
    statistics.value_min = min_value(store_value);
    statistics.value_max = max_value(store_value);
    statistics.variance = variance_value(store_value);
    statistics.standard_dev = sqrt(statistics.variance);
    while (true) {
        print_menu();


        int choice;
        std::cout << "What would you like to do : ";
        choice = fail_safe();

        switch (choice) {
            case 1:

                std::cout << "Here you can input data.\n";
                do {
                store_value.push_back(input_sensor_values());

                }while ();
                break;
            case 2:
                std::cout << "Here you can see all the statistics.\n";
                std::cout << "Number of entries :" << statistics.number_entries << "\n";
                std::cout << "Sum :" << statistics.sum << "\n";
                std::cout << "The average value :" << statistics.mean << "\n";
                std::cout << "The highest value :" << statistics.value_max << "\t the lowest value :" << statistics.value_min << "\n";
                std::cout << "The variance :" << statistics.variance << "\n";
                std::cout << "The standard deviation :" << statistics.standard_dev << "\n";

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