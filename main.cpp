
#include <iomanip>

#include "functions.h"
#include "statistics.h"






int main() {
    const std::string filename = "Sensor_database.csv";
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_values = {};
    std::vector<std::string> store_timestamps = {};
    std::vector<std::pair<std::string,double>> combine_value_timestamp = {};

    while (true) {
        int entries = 0;
        Functions::print_menu();
        switch (Functions::valid_input()) {
            case 1: {

                do {
                    std::cout << "Here you can input data.\n";
                    std::cout << "how many values would you like input?";
                    entries = Functions::valid_input();
                    for (int i = 0; i < entries; i++) {
                        store_values.push_back(Functions::input_sensor_value());
                        store_timestamps.push_back(Functions::generate_timestamp());
                    }
                }while (Functions::run_again() == true);
                Functions::combine_value_timestamp(store_values,store_timestamps,combine_value_timestamp);
                std::cout << std::endl;
                break;
            }
            case 2: {

                std::cout << "please input the the amount of data to generate: ";
                Functions::generate_numbers(store_values,store_timestamps);
                Functions::combine_value_timestamp(store_values,store_timestamps,combine_value_timestamp);

                break;
            }

            case 3: {

                if (store_values.empty()) {
                    std::cout << "The datastorage is empty.\n\n";
                    break;
                }
                Statistics stats = Statistics::calculate(store_values);
                Statistics::print_statistics(stats);
                for (auto& x : combine_value_timestamp) {
                    std::cout << x.first << " - " << x.second << "\n";
                }
                break;
            }

            case 4: {

                std::cout << "Here we can find a specific value between 1-50.\n";
                std::cout << "input value you want to search for :";
                Functions::data_finder(combine_value_timestamp,Functions::valid_input());
                break;
            }


            case 5: {


                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                Functions::data_sorter(combine_value_timestamp,Functions::valid_input());
                break;
            }


            case 6: {

                std::cout << "Storage usage.\n";
                Functions::print_storage_usage(store_values);

                break;
            }

            case 7: {

                std::cout << "Here you can check if any of the sensor measurements has gone above a certain value.\n";
                std::cout << "what value would you like to check? (between 1-50) :";
                Functions::Threshold_detection(combine_value_timestamp,Functions::valid_input());
                break;
            }

            case 8: {
                std::cout << "Do you want to write to the database or get data?\n";
                std::cout << "1.Write to database.\t 2.Get data from database : ";
                int choice = Functions::valid_input();
                if (choice == 1) {
                Functions::writeToDatabase(filename,combine_value_timestamp);
                } else if (choice == 2) {
                Functions::readFromDatabase(filename,store_timestamps,store_values);
                Functions::combine_value_timestamp(store_values,store_timestamps,combine_value_timestamp);
                } else {
                    std::cout << "Learn to read donkey... 1 or 2.\n";
                }
            break;
            }

            default:
            std::cout << "Have a good day.";
                return 0;
        }
    }
}