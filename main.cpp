//
// Created by BK Allen on 10/2/19.
//

#include <iostream>

#include <string>

#include "functions.h"

using namespace std;

int main()

{
    char choice;

    string question;

    do {

        cout << "\n\n--------------------------------" << endl;
        cout << "\t\t\tMenu";
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
            case 'E':;
                //@TODO implement deleteResponse();
                deleteResponse();
                break;

            case 'f':
            case 'F':
                exit(EXIT_SUCCESS);

            default:

                cout << "\nInvalid choice\n\n\n" << endl;
                break;
        }// switch
    } while (choice != 'F');// do while
}// main
#undef MAXSIZE