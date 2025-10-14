
#ifndef FIRST_ASSIGNMENT_FUNCTIONS_H
#define FIRST_ASSIGNMENT_FUNCTIONS_H
#include <iostream>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>


class Functions {

public:
   static int valid_input();
   static void print_menu();
   static int input_sensor_value();
   static bool run_again();
   static void generate_numbers(std::vector<double>& vec);
   static void print_storage_usage(const std::vector<double>&  vec);
   static void counter();
   static void data_sorter(const std::vector<double>& vec, int x);
   static void data_finder(const std::vector<double>& vec, int x);
   static void Threshold_detection(const std::vector<double>& vec, int set_value);

};
#endif //FIRST_ASSIGNMENT_FUNCTIONS_H