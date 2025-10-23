//
// Created by peder on 2025-10-04.
//

#ifndef FIRST_ASSIGNMENT_CALCULATIONS_H
#define FIRST_ASSIGNMENT_CALCULATIONS_H
#include <vector>


class Calculations {

    public:
    static double varianceValue (const std::vector<double>&);
    static int minValue(const std::vector<double>& store_value);
    static int maxValue(const std::vector<double>& store_value);
    static double vectorSum(const std::vector<double>& store_value);
};


#endif //FIRST_ASSIGNMENT_CALCULATIONS_H