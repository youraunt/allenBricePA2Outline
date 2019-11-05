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
    unsigned int responseSize = MAXSIZE();
    unsigned int responseCount = 0;
    auto *response = (Response*) malloc(sizeof(Response)
    *responseSize);
    while (menu(response));
    cout << "Goodbye!" << endl;
    exit(EXIT_SUCCESS);
}// main
#undef MAXSIZE