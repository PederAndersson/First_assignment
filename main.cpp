
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

void print_statistics(const Statistics& stats){
    std::cout << "Here you can see all the statistics.\n";
    std::cout << "Number of entries :" << stats.number_entries << "\n";
    std::cout << "Sum :" << stats.sum << "\n";
    std::cout << "The average value :" << stats.mean << "\n";
    std::cout << "The highest value :" << stats.value_max << "\t the lowest value :" << stats.value_min << "\n";
    std::cout << "The variance :" << stats.variance << "\n";
    std::cout << "The standard deviation :" << stats.standard_dev << "\n";
    std::cout << std::endl;

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
                Functions::counter();
                Functions::generate_numbers(store_values);
                break;
            case 3:
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
                print_statistics(stats);
                break;

            case 4:{
                std::cout << "Here we can find a specific value between 1-50.\n";
                std::cout << "input value you want to search for :";
                Functions::data_finder(store_values,Functions::valid_input());
                break;
            }

            case 5:

                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                Functions::data_sorter(store_values,Functions::valid_input());
                break;


            case 6: {
                std::cout << "Storage usage.\n";
                Functions::print_storage_usage(store_values);

                break;

            }
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