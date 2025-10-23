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