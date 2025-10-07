//
// Created by peder on 2025-10-07.
//

#ifndef FIRST_ASSIGNMENT_STATISTICS_H
#define FIRST_ASSIGNMENT_STATISTICS_H


#include <vector>
#include <cmath>
#include "util.h"

class statistics {
    int number_entries = 0;
    int sum = 0;
    double mean = 0.0;
    int value_min = 0, value_max = 0;
    double variance = 0.0, standard_dev = 0.0;
    std::vector<double> store;

public:
    void read_value();
    void recalculate();
    void print() const;
};


#endif //FIRST_ASSIGNMENT_STATISTICS_H