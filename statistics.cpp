//
// Created by peder on 2025-10-21.
//

#include "statistics.h"
#include "calculations.h"
Statistics Statistics::calculate(const std::vector<double> &store_value){

    Statistics stats;

    stats.number_entries = static_cast<int>(store_value.size());
    stats.sum = Calculations::vector_sum(store_value);
    stats.mean = stats.sum/static_cast<double>(store_value.size());
    stats.value_min = Calculations::min_value(store_value);
    stats.value_max = Calculations::max_value(store_value);
    stats.variance = Calculations::variance_value(store_value);
    stats.standard_dev = sqrt(stats.variance);
    return stats;
}

void Statistics::print_statistics(const Statistics& stats){

    std::cout << "Here you can see all the statistics.\n";
    std::cout << "Number of entries :\t" << stats.number_entries << "\n";
    std::cout << "Sum :\t\t\t" << stats.sum << "\n";
    std::cout << "The average value :\t" << stats.mean << "\n";
    std::cout << "The highest value :\t" << stats.value_max << "\n";
    std::cout << "the lowest value :\t" << stats.value_min << "\n";
    std::cout << "The variance :\t\t" << stats.variance << "\n";
    std::cout << "The standard deviation : " << stats.standard_dev << "\n";
    std::cout << std::endl;
}

