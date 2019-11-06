//
// Created by BK Allen on 10/2/19.
//

#include <iostream>

#include <string>

#include "functions.h"

using namespace std;


/// @brief main method compilation begins and ends here
/// @return 0 implied
int main() {
     int responseMax = sizeLimit();
     int currentSize = 0;
    auto *response = (Response *) malloc(sizeof(Response)
                                         * responseMax);
    while (menu(response, responseMax, currentSize));
    cout << "Exiting program!" << endl;
    exit(EXIT_SUCCESS);
}// main
