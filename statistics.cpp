//
// Created by peder on 2025-10-07.
//

#include "statistics.h"

void statistics::read_value() {
    do {
        std::cout << "Here you can input data.\n";
        const int input = Util::input_sensor_values();
        this->store.push_back(input);
    } while (Util::YesNo() == true);
}

void statistics::recalculate() {
    this->number_entries = static_cast<int>(this->store.size());
    this->sum = static_cast<int>(Util::vector_sum(this->store));
    this->mean = static_cast<double>(this->sum)/static_cast<double>(this->store.size());
    this->value_min = Util::min_value(this->store);
    this->value_max = Util::max_value(this->store);
    this->variance = Util::variance_value(this->store);
    this->standard_dev = sqrt(this->variance);
}

void statistics::print() const {
    std::cout << "Here you can see all the statistics.\n";
    std::cout << "Number of entries :" << this->number_entries << "\n";
    std::cout << "Sum :" << this->sum << "\n";
    std::cout << "The average value :" << this->mean << "\n";
    std::cout << "The highest value :" << this->value_max << "\t the lowest value :" << this->value_min << "\n";
    std::cout << "The variance :" << this->variance << "\n";
    std::cout << "The standard deviation :" << this->standard_dev << "\n";
}