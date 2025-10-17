//
// Created by peder on 2025-10-04.
//

#include "calculations.h"

double Calculations::variance_value(const std::vector<double>& data) { //calculates the variance of all the numbers in vector

    if (data.empty()) return 0.0;

    double sum = 0.0;
    for (double x : data) {
        sum += x;
    }

    double mean = sum/data.size();

    double squarediff = 0.0;
    for (double x : data) {
        double diff = x - mean;
        squarediff += diff*diff;
    }

    return squarediff / data.size();
}

int Calculations::min_value(const std::vector<double>& store_value) {
    int min = store_value[0];
    for (int x : store_value) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}

int Calculations::max_value(const std::vector<double>& store_value) {
    int max = store_value[0];
    for (int x : store_value) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

double Calculations::vector_sum(const std::vector<double>& store_value) {
    double sum = 0;
    for (double x : store_value) {
        sum += x;
    }
    return sum;
}
