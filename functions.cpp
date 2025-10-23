


#include "functions.h"
#include <algorithm>
#include <fstream>
#include <sstream>




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
    std::cout << "8. Read/write on database.\n";
    std::cout << "9. Exit.\n";
    std::cout << "What would you like to do: ";
}

void Functions::generate_numbers(std::vector<double>& vec, std::vector<std::string>& vec2) {
    const int choice = Functions::valid_input();
    std::random_device rd; //using this random generator as a seed.
    std::mt19937 mt(rd()); //generating random numbers with the mersenne twister seeded with random_device.
    std::uniform_int_distribution uniform (1, 50); // set the range for the highest and lowest number generated, while handling the statistical spread of numbers

    for (int i = 0; i < choice; i++) {
        vec.push_back(uniform(mt)); // for loop to push the random numbers to the vector.
        std::string timestamp = Functions::generate_timestamp();
        vec2.push_back(timestamp);
    }
    Functions::counter();
    std::cout << "Data has been downloaded.\n";
    std::cout << std::endl;
}

std::string Functions::generate_timestamp() { //function to generate random timestamps
    std::string timestamp;
    std::random_device rd; //using this random generator as a seed.
    std::mt19937 mt(rd()); //generating random numbers with the mersenne twister seeded with random_device.
    std::uniform_int_distribution<int> hour_dist(0, 23);
    std::uniform_int_distribution<int> minute_dist(0, 59);
    std::uniform_int_distribution<int> second_dist(0, 59);

    int hour = hour_dist(mt);
    int minute = minute_dist(mt);
    int second = second_dist(mt);

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << minute << ":"
        << std::setfill('0') << std::setw(2) << second;
     return oss.str();
}

void Functions::print_storage_usage(const std::vector<double>& vec) { //function to simulate to see how much space is occupied
    constexpr float storage_size = 500; //simulated size of storage space on the sensor module.
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

void Functions::data_sorter(const std::vector<std::pair<std::string,double>>& vec,const int x) { //function to sort the data either ascending or descending also checks if it's empty
    std::vector<std::pair<std::string,double>> temp = {};
    for (const auto& y : vec) {
        temp.push_back(y);
    }
    if (vec.empty()) {
        std::cout << "The data storage is empty.\n";
    }else if (x == 1) {
        std::cout << "Ascending order.\n";
        std::stable_sort(temp.begin(), temp.end(),
                         [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
                             return a.second < b.second;
                         });
        for (const auto& y : temp) {
            std::cout << y.second << " - " << y.first << std::endl;
        }
        std::cout << std::endl;

    }else {
        std::cout << "Descending order.\n";
        std::stable_sort(temp.begin(),temp.end(),[](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
                             return a.second > b.second;
                         });
        for (const auto& y : temp) {
            std::cout << y.second << " - " << y.first << std::endl;;
        }
    }
    std::cout << std::endl;
}

void Functions::data_finder(const std::vector<std::pair<std::string,double>>& vec, double x) { //check if there is a certain number in the vector
    bool check = false;
    for (const auto& y : vec) {
        if (y.second == x) {
            std::cout << "The value " << y.second << " was registered at the time " << y.first << std::endl;
            check = true;
        }
    }
        if (check == false){
            std::cout << "The value was not found." << std::endl;
        }
}

void Functions::Threshold_detection(const std::vector<std::pair<std::string,double>>& vec, int set_value) { //checks if any number in the vector exceeds a certain value
    int warnings = 0;
    for (auto& y : vec) {
        if (y.second > set_value) {
            warnings++;
            std::cout << "Value : " << y.second << " at the time :" << y.first << std::endl;
        }
    }
    std::cout << "The threshold value has been breached " << warnings << " number of times.\n";
}

void Functions::combine_value_timestamp(const std::vector<double>& store_value, const std::vector<std::string>& store_timestamp, std::vector<std::pair<std::string,double>>& combine) {
    if (store_value.size() == store_timestamp.size()) {
        for (size_t i = 0; i < store_value.size(); i++) {
            auto c = std::make_pair(store_timestamp[i],store_value[i]);
            combine.push_back(c);
        }
    }
}

void Functions::writeToDatabase(const std::string& filename, const std::vector<std::pair<std::string,double>>& vec) {

    std::fstream myFile;
    myFile.open(filename,std::ios::app);
    if (!myFile.is_open()) {
        std::cerr << "Error file not found";
        return;
    }
    if (myFile.tellp() == 0) {
        myFile << "Timestamp" << "," << "value" << "\n";
    }
    if (!vec.empty()) {
        for (const auto& x : vec) {

            myFile << x.first << "," << x.second << "\n";
        }
    } else {
        std::cout << "Sensor data is empty" << "\n";
    }

    myFile.close();
    std::cout << "Data saved to database\n";
}

void Functions::readFromDatabase(const std::string& filename, std::vector<std::string>& timestamp,std::vector<double>& value) {
    std::fstream myFile;
    myFile.open(filename, std::ios::in);
    if (!myFile.is_open()) {
        std::cerr << "File not found.\n";
        return;
    }
    if (myFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "File is empty.\n";
        return;
    }
    std::string line;

    std::getline(myFile, line);

    while (std::getline(myFile,line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string timestr;
        std::getline(ss, timestr, ',');

        std::string valstr;
        std::getline(ss, valstr, ',');
        try {
            double val = std::stod(valstr);
            value.push_back(val);
            timestamp.push_back(timestr);
        } catch (const std::invalid_argument& ) {
            std::cerr << "Unauthorized value on line :" << line << "\n";
        }

    }

    myFile.close();
    std::cout << "Data retrieved.\n";
}
