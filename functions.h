
#ifndef FIRST_ASSIGNMENT_FUNCTIONS_H
#define FIRST_ASSIGNMENT_FUNCTIONS_H
#include <iostream>
#include <limits>
#include <vector>
#include <random>

class Functions {

public:
   static int valid_input();
   static void print_menu();
   static int input_sensor_value();
   static bool run_again();
   static void generate_numbers(std::vector<double>& vec);

};
#endif //FIRST_ASSIGNMENT_FUNCTIONS_H