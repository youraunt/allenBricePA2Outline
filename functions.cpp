//
// Created by BK Allen on 10/2/19.
//

#include "functions.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#include <cstring>

#include <string>

#include <ctime>
#include <set>

#define MAXSIZE 100
//*********************************************************************************************************
struct Response : public bernoulli_distribution {
  string phrase;
  string type;
} Response[MAXSIZE];

//*********************************************************************************************************
// helper function to sort by compare
bool aCompare(const struct Response & lhs,struct Response & rhs){return lhs.phrase<rhs.phrase;}

//*********************************************************************************************************
// Requirement A
int readResponses() {
  ifstream infile;
  infile.open("data.txt");
  if (!infile|| infile.fail()) {
    cerr << "File not found!" << endl;
    exit(EXIT_FAILURE);
  }
  for (auto &response : Response) {

    getline(infile, response.phrase);
    getline(infile, response.type);
  }
  cout << "Responses successfully uploaded!" << endl;
  return 0;
}
//*********************************************************************************************************
// Requirement B
void playMagic8() {

  cout << "play ball" << endl;
  string question;
  cout << "\n\nEnter your question: " << endl;
  cin.ignore();
  getline(cin, question);
  random_device randomDevice;     // create object for seeding
  mt19937 engine{randomDevice()}; // create engine and seed it
  uniform_int_distribution<mt19937::result_type> dist20(
      1, 20); // distribution in range [1, 20]
  int randomNumber = dist20(engine);
  cout << question << "?" << endl;
  cout << Response[randomNumber].phrase << endl;
  cout << Response[randomNumber].type << endl;
}
//*********************************************************************************************************
// Requirement C
void printResponsesAndCategories() {
  sort(Response, Response +20,aCompare);
  cout << "\nPhrase, Type:"<< endl;
  for (int i = 0; i < 20; ++i) {
    cout << Response[i].phrase << ", "
         << Response[i].type << endl;
  }
}
//*********************************************************************************************************
// Requirement D
void writeResponsesToFile() { cout << "write response" << endl; }
//*********************************************************************************************************
// Extra credit
void deleteResponse() { cout << "delete response" << endl; }
//*********************************************************************************************************
// Helpers (optional) - you are welcome to add as many helper functions as you
// need
//*********************************************************************************************************
void menu() {
  char choice;

  string question;

  do {

    cout << "\n\n--------------------------------" << endl;
    cout << "\tMenu";
    cout << "\n--------------------------------" << endl;

    cout << "A. Read responses from a file" << endl;
    cout << "B. Play Magic Eight Ball" << endl;
    cout << "C. Print out responses and categories alphabetically" << endl;
    cout << "D. Write responses to a file" << endl;
    cout << "E. Delete response" << endl;
    cout << "F. Exit" << endl;
    cout << "Enter your choice: " << endl;

    cin >> choice;

    switch (choice) {

    case 'a':
    case 'A':
      readResponses();
      break;

    case 'b':
    case 'B':
      playMagic8();
      break;

    case 'c':
    case 'C':
      printResponsesAndCategories();
      break;

    case 'd':
    case 'D':
      writeResponsesToFile();
      break;

    case 'e':
    case 'E':
      deleteResponse();
      break;

    case 'f':
    case 'F':
      exit(EXIT_SUCCESS);

    default:

      cout << "\nInvalid choice\n\n\n" << endl;
      break;
    }
  } while (choice != 'F');
}
