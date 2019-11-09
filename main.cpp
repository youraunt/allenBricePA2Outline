/*
 *  Name: Brice Allen
 *  Date: 10/02/2019
 *  Class: CSCI 1410-003
 *  Description: RA2 A program that acts as an eight-ball
 *  allowing users to ask a questions and get a response.
 *  Status: Compiles and runs on Clion
 * */

#include <iostream>
#include <string>
#include "functions.h"

/// @brief main method compilation begins and ends here
/// @return 0 implied
int main() {
     int responseMax = sizeLimit();
     int currentSize = 0;
     // I used malloc here to allocate directly on the stack and free
     // up automatically when out of scope
    auto *response = (Response *) malloc(sizeof(Response)* responseMax);
    while (menu(response, responseMax, currentSize));
    exitProgram();
}// main
