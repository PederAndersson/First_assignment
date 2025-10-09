#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <iomanip>
#include "functions.h"




int input_sensor_value();

double variance_value(const std::vector<double>& data);

int min_value(const std::vector<double>& store_value);
int max_value(const std::vector<double>& store_value);
double vector_sum(const std::vector<double>& store_value) ;

struct Statistics {
    int number_entries = {};
    double sum = {};
    double mean = {};
    double value_min = {};
    double value_max = {};
    double variance = {};
    double standard_dev = {};

    static Statistics calculate(const std::vector<double> &);
};

Statistics Statistics::calculate(const std::vector<double> &store_value){
    Statistics stats;
    double sum = vector_sum(store_value);
    stats.number_entries = static_cast<int>(store_value.size());
    stats.sum = sum;
    stats.mean = stats.sum/static_cast<double>(store_value.size());
    stats.value_min = min_value(store_value);
    stats.value_max = max_value(store_value);
    stats.variance = variance_value(store_value);
    stats.standard_dev = sqrt(stats.variance);
    return stats;
}

bool go_again();

bool sort_desc(int a, int b) {
    return a > b;
}


int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_values = {2, 5, 3, 3, 5, 6, 9};
    Statistics stats = Statistics::calculate(store_values);

    while (true) {
        Functions::print_menu();
        int input;
        std::cout << "What would you like to do : ";
        switch (Functions::valid_input()) {
            case 1:
                do {
                std::cout << "Here you can input data.\n";
                input = input_sensor_value();
                store_values.push_back(input);
                }while (go_again() == true);
                stats = Statistics::calculate(store_values);
                break;

            case 2:
                Statistics::calculate(store_values);
                std::cout << "Here you can see all the statistics.\n";
                std::cout << "Number of entries :" << stats.number_entries << "\n";
                std::cout << "Sum :" << stats.sum << "\n";
                std::cout << "The average value :" << stats.mean << "\n";
                std::cout << "The highest value :" << stats.value_max << "\t the lowest value :" << stats.value_min << "\n";
                std::cout << "The variance :" << stats.variance << "\n";
                std::cout << "The standard deviation :" << stats.standard_dev << "\n";
                break;

            case 3:
                std::cout << "Here we can find a specific value.\n";

                break;

            case 4:
                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                switch (Functions::valid_input()) {
                    case 1:
                        std::cout << "Ascending order.\n";
                        std::stable_sort(store_values.begin(),store_values.end());
                        for (int s : store_values)
                            std::cout << s << " ";
                        break;
                    case 2:
                        std::cout << "Descending order.\n";
                        std::stable_sort(store_values.begin(),store_values.end(),sort_desc);
                        for (int s : store_values)
                            std::cout << s << " ";
                        break;
                    default:
                        std::cout << "wrong stupid!";
                }

            case 5:

                break;
            default:
                std::cout << "Have a good day.";
                return 0;
        }
    }
}