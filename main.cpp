
#include <iomanip>
#include <iostream>

#include "functions.h"
#include "statistics.h"






int main() {
    const std::string filename = "Sensor_database.csv";
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> store_values = {};
    std::vector<std::string> store_timestamps = {};
    std::vector<std::pair<std::string,double>> combine_value_timestamp = {};

    while (true) {
        Functions::printMenu();
        switch (Functions::validInput()) {
            case 1: {
                int entries = 0;

                do {
                    std::cout << "Here you can input data.\n";
                    std::cout << "how many values would you like input?";
                    entries = Functions::validInput();
                    for (int i = 0; i < entries; i++) {
                        store_values.push_back(Functions::inputSensorValue());
                        store_timestamps.push_back(Functions::generateTimestamp());
                    }
                }while (Functions::runAgain() == true);
                Functions::combineValueTimestamp(store_values,store_timestamps,combine_value_timestamp);
                std::cout << std::endl;
                break;
            }
            case 2: {

                std::cout << "please input the the amount of data to generate: ";
                Functions::generateData(store_values,store_timestamps);
                Functions::combineValueTimestamp(store_values,store_timestamps,combine_value_timestamp);

                break;
            }

            case 3: {

                if (store_values.empty()) {
                    std::cout << "The datastorage is empty.\n\n";
                    break;
                }
                Statistics stats = Statistics::calculateStatistics(store_values);
                Statistics::printStatistics(stats);
                break;
            }

            case 4: {

                std::cout << "Here we can find a specific value between 1-50.\n";
                std::cout << "input value you want to search for :";
                Functions::dataFinder(combine_value_timestamp,Functions::validInput());
                break;
            }


            case 5: {
                std::cout << "Here we can sort the value in ascending or descending order.\n";
                std::cout << "1. Ascending. \n" << "2. Descending\n";
                std::cout << "what would you like to do :";
                Functions::dataSorter(combine_value_timestamp,Functions::validInput());
                break;
            }


            case 6: {
                std::cout << "Storage usage.\n";
                Functions::printStorageUsage(store_values);
                break;
            }

            case 7: {
                std::cout << "Here you can check if any of the sensor measurements has gone above a certain value.\n";
                std::cout << "what value would you like to check? (between 1-50) :";
                Functions::ThresholdDetection(combine_value_timestamp,Functions::validInput());
                break;
            }

            case 8: {
                std::cout << "Do you want to write to the database or get data?\n";
                std::cout << "1.Write to database.\t 2.Get data from database. \t 3.Clear database : ";
               switch (Functions::validInput()) {
                    case 1: {
                        Functions::writeToDatabase(filename,combine_value_timestamp);
                        break;
                    }
                    case 2: {
                        Functions::readFromDatabase(filename,store_timestamps,store_values);
                        Functions::combineValueTimestamp(store_values,store_timestamps,combine_value_timestamp);
                        break;
                    }
                    case 3: {
                        Functions::clearDatabase(filename);
                        break;
                    }
                    default: {
                        std::cout << "I said 1-3 you donkey...\n";
                    }
               }
            break;
            }

            default:
            std::cout << "Have a good day.";
                return 0;
        }
    }
}