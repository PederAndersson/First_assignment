#ifndef FIRST_ASSIGNMENT_FUNCTIONS_H
#define FIRST_ASSIGNMENT_FUNCTIONS_H
#include <vector>
#include <random>
#include <chrono>


class Functions {

public:
   static int valid_input();
   static void print_menu();
   static int input_sensor_value();
   static bool run_again();
   static void generate_numbers(std::vector<double>& vec,std::vector<std::string>& vec2);
   static std::string generate_timestamp();
   static void print_storage_usage(const std::vector<double>&  vec);
   static void counter();
   static void data_sorter(const std::vector<std::pair<std::string,double>>& vec, int x);
   static void data_finder(const std::vector<std::pair<std::string,double>>& vec, double x);
   static void Threshold_detection(const std::vector<std::pair<std::string,double>>& vec, int set_value);
   static void combine_value_timestamp(const std::vector<double>& store_value, const std::vector<std::string>& store_timestamp, std::vector<std::pair<std::string,double>>& combine);
   static void writeToDatabase(const std::string& filename, const std::vector<std::pair<std::string,double>>& vec);
   static void readFromDatabase(const std::string& filename, std::vector<std::string>& timestamp,std::vector<double>& value);
   static void clearDatabase(const std::string& filename);

};
#endif //FIRST_ASSIGNMENT_FUNCTIONS_H