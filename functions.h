#ifndef FIRST_ASSIGNMENT_FUNCTIONS_H
#define FIRST_ASSIGNMENT_FUNCTIONS_H
#include <vector>
#include <random>

class Functions {

public:
   static int validInput();
   static void printMenu();
   static int inputSensorValue();
   static bool runAgain();
   static void generateData(std::vector<double>& vec,std::vector<std::string>& vec2);
   static std::string generateTimestamp();
   static void printStorageUsage(const std::vector<double>&  vec);
   static void counter();
   static void dataSorter(const std::vector<std::pair<std::string,double>>& vec, int x);
   static void dataFinder(const std::vector<std::pair<std::string,double>>& vec, double x);
   static void ThresholdDetection(const std::vector<std::pair<std::string,double>>& vec, int set_value);
   static void combineValueTimestamp(const std::vector<double>& store_value, const std::vector<std::string>& store_timestamp, std::vector<std::pair<std::string,double>>& combine);
   static void writeToDatabase(const std::string& filename, const std::vector<std::pair<std::string,double>>& vec);
   static void readFromDatabase(const std::string& filename, std::vector<std::string>& timestamp,std::vector<double>& value);
   static void clearDatabase(const std::string& filename);

};
#endif //FIRST_ASSIGNMENT_FUNCTIONS_H