/*
 *  Name: Brice Allen
 *  Date: 10/02/2019
 *  Class: CSCI 1410-003
 *  Description: RA2 A program that acts as an eight-ball
 *  allowing users to ask a questions and get a response.
 *  Status: Compiles and runs on Clion
 * */
//
// Created by Henok on 3/5/2019.
//

#ifndef ALLENBRICEPA2OUTLINE_FUNCTIONS_H
#define ALLENBRICEPA2OUTLINE_FUNCTIONS_H

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <algorithm>



//using namespace std;
//*********************************************************************************************************
// inherit from bernoulli_distribution to generate more randomness in number than rand
//*********************************************************************************************************
struct Response : public std::bernoulli_distribution {
    std::string phrase;
    std::string type;
};

/// @brief Requirement A
/// @param response
/// @param responseMax
/// @param currentSize
/// @return
void readResponses(Response *response, int responseMax, int &currentSize);
/// @brief Requirment B
/// @param response
/// @param currentSize
void playMagic8(Response *response, int responseMax, int &currentSize);
/// @brief Requirment C
/// @param response
/// @param responseMax
/// @param currentSize
void printResponsesAndCategories(Response *response, int responseMax, int &currentSize);
/// @brief Requirement D
/// @param response
/// @param currentSize
void writeResponsesToFile(Response *response, int &currentSize);
// @brief Extra credit
void deleteResponse(Response *response, int &currentSize);
/// @brief Helpers (optional) - you are welcome to add as many helper functions as you need
bool menu(Response *response, int responseMax, int &currentSize);
/// @brief helper
void unknownInput();
/// @brief establish max size
/// @return sizeLimit
int sizeLimit();
bool menu(Response *response, int responseMax, int &currentSize, char &choice);
std::string exitProgram();

#endif //ALLENBRICEPA2OUTLINE_FUNCTIONS_H
