#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

void print_menu() {
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Check the total sum.\n";
    std::cout << "3. Check the average value.\n";
    std::cout << "4. Highest or lowest value.\n";
    std::cout << "5. Variance and standard deviation.\n";
    std::cout << "6. Exit.\n";
}

int fail_safe() {
    int y;
    while (true) {
        if (!(std::cin >> y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Please input a number instead.\n";
        } else {
            return y;
        }
    }
}

int input_sensor_values() {
    std::cout << "Please input your value :";
    int value = fail_safe();
    return value;
}
double variance_value (const std::vector<double>& data) {

    if (data.empty()) return 0;

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



int main() {
    std::vector<double> sensor_input;
    int value, number_of_input;
    std::cout << "please input the number of values you want to input :";
    number_of_input = fail_safe();

    for (int i = 0; i < number_of_input; i++) {
       value = input_sensor_values();
        sensor_input.push_back(value);
    }
    int sum = 0;
    int min_value = sensor_input[0];
    int max_value = sensor_input[0];
    for (int i = 0; i < number_of_input; i++) {
        std::cout << sensor_input[i] << " ";
        std::cout << "\n";
        sum += sensor_input[i];
        if (sensor_input[i] < min_value) {
            min_value = sensor_input[i];
        }
        if (sensor_input[i] > max_value) {
            max_value = sensor_input[i];
        }
    }
    double variance;
    variance = variance_value(sensor_input);

    int average_value = sum/sensor_input.size();
    std::cout << "the sum is :" << sum << "\n";
    std::cout << "the number of inputs :" << sensor_input.size() << "\n";
    std::cout << "the average value is :" << average_value << "\n";
    std::cout << "the minimum value is :" << min_value << "\n";
    std::cout << "the maximum value is :" << max_value << "\n";
    std::cout << "the variance is :" << variance << "\n";
    std::cout << "the standard deviation is " << sqrt(variance) << "\n";

    //print_menu();
    return 0;
}