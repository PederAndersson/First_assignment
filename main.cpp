#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <iomanip>

int fail_safe();
void print_menu() {
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Check statistics.\n";
    std::cout << "3. Find value.\n";
    std::cout << "4. Sort values.\n";
    std::cout << "5. Exit.\n";
}

int input_sensor_values();

double variance_value(const std::vector<double>& data);

int min_value(const std::vector<double>& store_value);
int max_value(const std::vector<double>& store_value);
double vector_sum(const std::vector<double>& store_value) ;

struct Statistc_values {
    int number_entries;
    int sum;
    double mean;
    int value_min, value_max;
    double variance, standard_dev;

};
bool YesNo();


int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_value = {2, 5, 3, 3, 5, 6, 9};
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
        int input;

        int choice;
        std::cout << "What would you like to do : ";
        choice = fail_safe();
        switch (choice) {
            case 1:
                do {
                std::cout << "Here you can input data.\n";
                input = input_sensor_values();
                store_value.push_back(input);
                YesNo();
                }while (YesNo() == true);
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