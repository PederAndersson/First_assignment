//
// Created by peder on 2025-10-21.
//

#ifndef FIRST_ASSIGNMENT_STATISTICS_H
#define FIRST_ASSIGNMENT_STATISTICS_H
#include <vector>
#include <iostream>
#include <cmath>

struct Statistics {
    int number_entries = {};
    double sum = {};
    double mean = {};
    double value_min = {};
    double value_max = {};
    double variance = {};
    double standard_dev = {};

    static Statistics calculate(const std::vector<double> &);
    static void print_statistics(const Statistics& stats);
}; //struct to store all the statistics data.

#endif //FIRST_ASSIGNMENT_STATISTICS_H