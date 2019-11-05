//
// Used by BK Allen on 10/2/19.
//
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

using namespace std;
//*********************************************************************************************************
// inherit from bernoulli_distribution to generate more randomness in number than rand
//*********************************************************************************************************

struct Response : public bernoulli_distribution {
    string phrase;
    string type;
};

//#define MAXSIZE 100
int  MAXSIZE(){
return 100;
};

//Requirement A

int readResponses(Response *response);

//B
int playMagic8(Response *response);

//C
void printResponsesAndCategories(Response *response);

//D
void writeResponsesToFile(Response *response);

//Extra credit
void deleteResponse(Response *response);


//Helpers (optional) - you are welcome to add as many helper functions as you need
bool menu(Response *response);




#endif //ALLENBRICEPA2OUTLINE_FUNCTIONS_H
