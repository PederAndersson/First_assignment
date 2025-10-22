
#include <iomanip>
#include <fstream>
#include <sstream>
#include "functions.h"
#include "statistics.h"

void writeToDatabase(const std::string& filename, const std::vector<std::pair<std::string,double>>& vec) {

    std::fstream myFile;
    myFile.open(filename,std::ios::app);
    if (!myFile.is_open()) {
        std::cerr << "Error file not found";
        return;
    }
    if (myFile.tellp() == 0) {
    myFile << "Timestamp" << "," << "value" << "\n";
    }
    if (!vec.empty()) {
        for (const auto& x : vec) {

            myFile << x.first << "," << x.second << "\n";
        }
    } else {
        std::cout << "Sensor data is empty" << "\n";
    }

    myFile.close();
    std::cout << "Data saved to database\n";
}

void readFromDatabase(const std::string& filename, std::vector<std::string>& timestamp,std::vector<double>& value) {
    std::fstream myFile;
    myFile.open(filename, std::ios::in);
    if (!myFile.is_open()) {
        std::cerr << "File not found.\n";
        return;
    }
    if (myFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "File is empty.\n";
        return;
    }
    std::string line;

    std::getline(myFile, line);

    while (std::getline(myFile,line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string timestr;
        std::getline(ss, timestr, ',');

        std::string valstr;
        std::getline(ss, valstr, ',');
        try {
            double val = std::stod(valstr);
            value.push_back(val);
            timestamp.push_back(timestr);
        } catch (const std::invalid_argument& ) {
            std::cerr << "Unauthorized value on line :" << line << "\n";
        }

    }

    myFile.close();
    std::cout << "Data retrieved.\n";
}



int main() {
    Statistics stats;
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
                Functions::combine_data_timestamp(store_values,store_timestamps,combine_value_timestamp);
                std::cout << std::endl;
                break;
            }
            case 2: {

                std::cout << "please input the the amount of data to generate: ";
                Functions::generate_numbers(store_values,store_timestamps);
                Functions::combine_data_timestamp(store_values,store_timestamps,combine_value_timestamp);

                break;
            }

            case 3: {

                if (store_values.empty()) {
                    std::cout << "The datastorage is empty.\n\n";
                    break;
                }
                stats = Statistics::calculate(store_values);
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
                writeToDatabase(filename,combine_value_timestamp);
                } else if (choice == 2) {
                readFromDatabase(filename,store_timestamps,store_values);
                Functions::combine_data_timestamp(store_values,store_timestamps,combine_value_timestamp);
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