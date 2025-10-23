//
// Created by peder on 2025-10-04.
//

#include "calculations.h"

double Calculations::varianceValue(const std::vector<double>& data) { //calculates the variance of all the numbers in vector

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

int Calculations::minValue(const std::vector<double>& store_value) {
    double min = store_value[0];
    for (double x : store_value) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}

int Calculations::maxValue(const std::vector<double>& store_value) {
    double max = store_value[0];
    for (double x : store_value) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

double Calculations::vectorSum(const std::vector<double>& store_value) {
    double sum = 0;
    for (double x : store_value) {
        sum += x;
    }
    return sum;
}
