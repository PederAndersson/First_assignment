

#include "functions.h"




int Functions::valid_input() { // function to validate that your input is a number not a letter
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

int Functions::input_sensor_value() { // function to input a new value.
    while (true) {
        std::cout << "Please input your value between 1 and 50:";

        int value = Functions::valid_input();

        if (value < 1 || value >50) {
            std::cout << "Value is not with the specified range. try again.\n";
        } else {
            return value;
        }
    }
}

bool Functions::run_again(){ // function to check if you want to run again.
    char answer;

    while (true) {
        std::cout << "Would you like to go again? (y/n) ";
        std::cin >> answer;
       char ch = answer;
       char lowercase = std::tolower(ch);
        if (std::isdigit(ch)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Only letters, Y or N." << std::endl;
        }else if (lowercase == 'n') {
            return false;
        }else if (lowercase == 'y') {
            return true;
        }else {
            std::cout << "Try again only Y or N." << std::endl;
        }
    }
}

void Functions::print_menu() {
    std::cout << "Hello, welcome to our sensor input/output program!, what would you like to do?\n";
    std::cout << "1. Input values.\n";
    std::cout << "2. Download sensor data.\n";
    std::cout << "3. Check statistics.\n";
    std::cout << "4. Find value.\n";
    std::cout << "5. Sort values.\n";
    std::cout << "6. Storage usage.\n";
    std::cout << "7. Threshold detector.\n";
    std::cout << "8. Exit.\n";
}

void Functions::generate_numbers(std::vector<double>& vec) {
    std::random_device rd; //using this random generator as a seed.
    std::mt19937 mt(rd()); //generating random numbers with the mersenne twister seeded with random_device.
    std::uniform_int_distribution uniform (1, 50); // set the range for the highest and lowest number generated, while handling the statistical spread of numbers
    for (int i = 0; i < 25; i++) {
        vec.push_back(uniform(mt)); // for loop to push the random numbers to the vector.
    }
    std::cout << "Data has been downloaded.\n";
    std::cout << std::endl;
}

void Functions::print_storage_usage(const std::vector<double>& vec) {
    constexpr float storage_size = 500; //simulated size storage space on the sensor module.
    float percentage = 0;
    percentage = (vec.size() / storage_size) * 100;

    std::cout << "The storage space is " << percentage << "% full.\n";
    std::cout << std::endl;
}

void Functions::counter() { //a counter to simulate a progressbar.
    int x = 0;
    for (int i = 0; i < 10; i++) {
        std::cout << x << " %" << " ";
        x += 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sets a slight pause in the loop.
    }
    std::cout << "100% done!" << std::endl;
}

void Functions::data_sorter(const std::vector<double>& vec, int x) {
    std::vector<double> temp = vec;
    if (temp.empty()) {
        std::cout << "The data storage is empty.\n";
    }else if (x == 1) {
        std::cout << "Ascending order.\n";
        std::stable_sort(temp.begin(),temp.end());
        for (int y : temp) {
            std::cout << static_cast<int>(y) << " ";
        }
        std::cout << std::endl;

    }else {
        std::cout << "Descending order.\n";
        std::stable_sort(temp.begin(),temp.end(),std::greater<int>());
        for (int y : temp) {
            std::cout << static_cast<int>(y) << " ";
        }
    }
    std::cout << std::endl;
}

void Functions::data_finder(const std::vector<double> &vec, int x) {

    int search_number = x;
    if ( std::find(vec.begin(), vec.end(), search_number ) !=vec.end()) {
        std::cout << search_number << " is here.\n";
    }else {
        std::cout << search_number << " is not here.\n";
    }
    std::cout << std::endl;
}

void Functions::Threshold_detection(const std::vector<double> &vec, int set_value) {
    int warnings = 0;
    for (int y : vec) {
        if (y > set_value) {
            warnings++;
        }
    }
    std::cout << "The threshold value has been breached " << warnings << " number of times.\n";
}

