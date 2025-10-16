This repo will contain the code for Inlämningsuppgift 1 in the future.

Assignment 1: Data Collector and Analysis Tool for Measurements
(This assignment description is also available as a separate PDF.)

Background:
In an IoT system, we often collect measurement values from sensors, such as temperature, humidity, and pressure. To be able to understand and use these values, we need to analyze them.

Task:
Develop a C/C++ program that manages a list of measurement values (for example, temperature).
Your program code should be stored in a GitHub repository, and your work and solution should be documented in the repository’s README file. (A tutorial/guide for Git/GitHub will be provided.)

Requirements Specification:

Data Input
a. The user must be able to manually enter a number of measurement values.
b. The program must handle invalid input in a robust way.
c. (Challenge: allow both integer and decimal numbers.)

Data Processing
a. The program must calculate and display:
i. Number of values
ii. Sum
iii. Mean (average)
iv. Minimum and maximum value
v. Variance and standard deviation

Menu Interface (UI)
a. The user must be able to choose what to do through a menu:
i. Add new measurement values
ii. Display statistics
iii. Search for a specific value
iv. Sort the list of measurement values (optional: ascending/descending)
v. Exit the program

Structure and Quality
a. The program must be divided into several functions (or methods if you prefer to use C++).
b. The code must be well commented and documented.
c. The program must handle errors (for example, if the list is empty during analysis).

#IOT assignment 1.
The program simulates a datacollector for somw kind of sensor that will gather and collect data while performing some statistical data calculations, manual input of data, simulation of data.

##Project structure.
main.cpp         #main program handles the menu and statistics struct
functions.cpp    #header-file handles the various functions related to verifying inputs printing text 
                  and generating the simulated data.
calculations.cpp  #header-file handles the purely mathematical functions.
readme.md          #info about the project.

##Git
clone the repo with this link.
https://github.com/PederAndersson/First_assignment.git

##Use
At the start of the program you should see the menu in the terminal. like this

Hello, welcome to our sensor input/output program!, what would you like to do?
1. Input values.
2. Download sensor data.
3. Check statistics.
4. Find value.
5. Sort values.
6. Storage usage.
7. Threshold detector.
8. Exit.
What would you like to do :

for the menu i choose a switch() because i'm still new to coding and it's easy to work with and to read the code instead of a else/if chain.
To store data i used a vector due to not having to manually set a size limit, but thinking about it now an array might have been better when working in IoT due to memory constraints.
For the statistics i use a struct which is a good way to store variables of different kinds together i then used to function in the struct to create an object that stores all the calculated values using the data from the vector.
To check for bad input i made a function to check if the input was an integer not a char, an use that everytime i want to input any kind of number. To guard against en empty vector i use a simple if(vec.empty())
to check the vector.
i use const qualifier in all the functions that interact with the vector that only reads or calculates the values in it, so we reduce the risk of unwanted changes in the data, and references to check the intended vector.
For the datageneration i used the Mersenne twister algorithm seeded with the std::random_device() to generate the data. it's a efficient way to generate random numbers close to true random.

##Functionality

input values  |  inputs value and checks that it i's a correct value pushes it to the vector
calculates statistics  |  takes the stored values calculates them and stores in a struct object.
sort value  |  to sort the numbers i used the std::stable_sort() to sort both ascending/descending.
find value  |  to search the vector i used std::find() so you can input what you are looking for.
storage useage  |  simulated a set size for the storage which checks how many elements are in the vector and                    gives you a % of how much space is allocated.
threshold detector  |  allows you to input a value and see how many times it has been exceeded.

##Testing
to test the program i have input known values that i know the results from to check if all my math is correct.
i have also tried to make the wrong input to see if my safeguards work.

##Challenges and lessons learnd.
since i'm new to coding it's all new and i'm learning stuff all the time and i'm realising how much there is to learn and since i'm new to it the syntax is alot to remember and if i don't use something for a short while it's easy to forget. something i need to work on is how i name different variables/functions etc.  have a tendency to just pick any name for a variable but that gets really difficult to to keep track of when writing a larger program. Plan the code better from the start, this time i hade to almost start over after getting about half-way due to the code getting difficult to read, but i have learnd alot since stating the project and have had to update the code after learing new things.

##extra challenges
sensor-simulation:
i used the mersennetwister algoritm to generate the number std::mt19937() since it's one of the better ones to generate large batches of numbers without repeating itself. To seed it so i don't get the same series of numbers everytime i used the std::random_device i think it a simple way to get a good set of data and it's close to random.
i used std::uniform_int_distrebution()  to set the interval for the numbers generated while handling the statistc spread.
Threshold detector:
a simple for-loop to check for a value input by the user and everytime the number is found it is registerd, makes for a simple warningsystem if a certain value is exceeded.
Visual representaions of a progressbar:
a for-loop that prints out 0-100% with increments of 10 using a std::this_thread::sleep_for(std::chrono::milliseconds(500)) which makes each iteration pause for 0.5 seconds.
