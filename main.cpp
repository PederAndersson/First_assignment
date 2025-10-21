
#include <iomanip>
#include "functions.h"
#include "statistics.h"








int main() {
    Statistics stats;
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_values = {};
    std::vector<std::string> store_timestamps = {};
    std::vector<std::pair<std::string,double>> combine = {};





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
                std::cout << "please input the the amount of data to generate: ";
                Functions::generate_numbers(store_values,store_timestamps);
                break;

            case 3:
                if (store_values.empty()) {
                    std::cout << "The datastorage is empty.\n\n";
                    break;
                }
                stats = Statistics::calculate(store_values);
                Statistics::print_statistics(stats);

                break;

            case 4:
                std::cout << "Here we can find a specific value between 1-50.\n";
                std::cout << "input value you want to search for :";
                Functions::data_finder(store_values,Functions::valid_input());
                break;


            case 5:

                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                Functions::data_sorter(store_values,Functions::valid_input());
                break;


            case 6:
                std::cout << "Storage usage.\n";
                Functions::print_storage_usage(store_values);

                break;

            case 7:
                std::cout << "Here you can check if any of the sensor measurements has gone above a certain value.\n";
                std::cout << "what value would you like to check? (between 1-50) :";
                Functions::Threshold_detection(store_values,Functions::valid_input());
                break;

            default:
            std::cout << "Have a good day.";
            return 0;
        }
    }
}