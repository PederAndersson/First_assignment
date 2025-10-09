//
// Created by peder on 2025-10-04.
//

#ifndef FIRST_ASSIGNMENT_CALCULATIONS_H
#define FIRST_ASSIGNMENT_CALCULATIONS_H
#include <vector>

class Calculations {

    public:
    static double variance_value (const std::vector<double>&);
    static int min_value(const std::vector<double>& store_value);
    static int max_value(const std::vector<double>& store_value);
    static double vector_sum(const std::vector<double>& store_value);
};


#endif //FIRST_ASSIGNMENT_CALCULATIONS_H