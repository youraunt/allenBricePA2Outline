//
// Created by BK Allen on 10/2/19.
//

#include <iostream>

#include <string>

#include "functions.h"



/// @brief main method compilation begins and ends here
/// @return 0 implied
int main() {
     int responseMax = sizeLimit();
     int currentSize = 0;
     // i used malloc here to allocate directly on the stack and free
     // up automatically when out of scope
    auto *response = (Response *) malloc(sizeof(Response)* responseMax);
    while (menu(response, responseMax, currentSize));
    std::cout << "Exiting program!" << std::endl;
    exit(EXIT_SUCCESS);
}// main
