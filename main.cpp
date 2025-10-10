#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "calculations.h"
#include "functions.h"



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

    stats.number_entries = static_cast<int>(store_value.size());
    stats.sum = Calculations::vector_sum(store_value);
    stats.mean = stats.sum/static_cast<double>(store_value.size());
    stats.value_min = Calculations::min_value(store_value);
    stats.value_max = Calculations::max_value(store_value);
    stats.variance = Calculations::variance_value(store_value);
    stats.standard_dev = sqrt(stats.variance);
    return stats;
}

bool sort_desc(double a, double b) {
    return a > b;
}


int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_values = {};
    Statistics stats;

    while (true) {
        int entries = 0;
        Functions::print_menu();
        std::cout << "What would you like to do : ";
        switch (Functions::valid_input()) {
            case 1:
                do {
                std::cout << "Here you can input data.\n";
                    std::cout << "how many values would you like input?";
                    entries = Functions::valid_input();
                    for (int i = 0; i < entries; i++) {
                        store_values.push_back(Functions::input_sensor_value());
                    }
                }while (Functions::run_again() == true);
                std::cout << std::endl;
                break;

            case 2:
                    if (store_values.empty()) {
                        std::cout << "The datastorage is empty, please input your findings\n";

                        std::cout << "how many values would you like input?";
                        entries = Functions::valid_input();
                        for (int i = 0; i < entries; i++) {
                            store_values.push_back(Functions::input_sensor_value());
                        }
                        break;
                    }
                    stats = Statistics::calculate(store_values);
                    std::cout << "Here you can see all the statistics.\n";
                    std::cout << "Number of entries :" << stats.number_entries << "\n";
                    std::cout << "Sum :" << stats.sum << "\n";
                    std::cout << "The average value :" << stats.mean << "\n";
                    std::cout << "The highest value :" << stats.value_max << "\t the lowest value :" << stats.value_min << "\n";
                    std::cout << "The variance :" << stats.variance << "\n";
                    std::cout << "The standard deviation :" << stats.standard_dev << "\n";
                    std::cout << std::endl;

                break;

            case 3:{
                std::cout << "Here we can find a specific value.\n";
                std::cout << "input value you want to search for :";
                double search_number = Functions::valid_input();
                if ( std::find(store_values.begin(), store_values.end(), search_number ) !=store_values.end()) {
                    std::cout << search_number << " is here.\n";
                }else {
                    std::cout << search_number << " is not here.\n";
                }
                std::cout << std::endl;
                break;
            }

            case 4:
                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                switch (Functions::valid_input()) {
                    case 1:
                        std::cout << "Ascending order.\n";
                        std::stable_sort(store_values.begin(),store_values.end());
                        for (double s : store_values) {
                            std::cout << s << " ";
                        }
                        break;
                    case 2:
                        std::cout << "Descending order.\n";
                        std::stable_sort(store_values.begin(),store_values.end(),sort_desc);
                        for (double s : store_values) {
                            std::cout << s << " ";
                        }
                        std::cout << std::endl;
                        break;
                    default:
                        std::cout << "wrong stupid!";
                        std::cout << std::endl;
                        break;
                }
                std::cout << std::endl;
                break;


            case 5: {
                    std::cout << "Number of warnings detected!\n";
                    int warning = 0;
                    for (double s : store_values) {
                        if (s > 10) {
                            warning++;
                        }
                    }
                    std::cout << "The sensor have pinged " << warning << " number of warnings\n";
                }
                std::cout << std::endl;
                break;
            default:
                std::cout << "Have a good day.";
                return 0;
        }

    }
}