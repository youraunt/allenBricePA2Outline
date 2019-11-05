//
// Created by BK Allen on 10/2/19.
//

#include "functions.h"
/**
 * @brief Prints an error message for when a users input is invalid
 */

void unknownInput() {
    cout << "Error?! Please, try again: " << endl;
}


//*********************************************************************************************************
// helper function to sort alphabetically by phrase
//*********************************************************************************************************
/// @brief
/// @param lhs
/// @param rhs
/// @return
bool compare(const struct Response &lhs, struct Response &rhs) {
    return lhs.phrase < rhs.phrase;
}// bool compare

//*********************************************************************************************************
// Requirement A
//*********************************************************************************************************
/// @brief
/// @return
int readResponses(Response* response) {
    int currentSize = 0;
    // initiate file stream
    ifstream infile;
    // open file
    infile.open("data.txt");
    /* check that file exists and is valid else display
     * error and exit program with error
     * */
    if (!infile || infile.fail()) {
        cerr << "File not found!" << endl;
        exit(EXIT_FAILURE);
    }
    // range based loop to iterate through struct
    for (int i =0; i<MAXSIZE(); ++i) {

        // grab lines from file
        getline(infile, response->phrase);
        getline(infile, response->type);
        currentSize++;
    }
    // let user know that file was read successfully
    cout << "Responses successfully uploaded!" << endl;
    return currentSize;
}
//*********************************************************************************************************
// Requirement B
// function playMagic8 to ask the ball questions and get responses
//*********************************************************************************************************
/// @brief
/// @return
int playMagic8(Response* response) {
    // declare local variable
    string question;
    // prompt user to enter a question
    cout << "\n\nEnter your question: " << endl;
    // ignore blank input
    cin.ignore();
    // get user input store string variable question
    getline(cin, question);
    // create object for seeding
    random_device randomDevice;
    // create engine and seed it
    mt19937 engine{randomDevice()};
    // distribution in range [1, 20]
    uniform_int_distribution<mt19937::result_type> dist20(1, 20);
    // assign random number to int type variable named randomNumber
    int randomNumber = dist20(engine);
    // display users question with punctuation
    cout << "\n" << question << "?" << endl;
    // display random phrase and type
    cout << response[randomNumber].phrase << endl;
    cout << response[randomNumber].type << endl;
    return randomNumber;
}

//*********************************************************************************************************
// Requirement C
//*********************************************************************************************************
/// @brief
void printResponsesAndCategories(Response* response) {
    sort(response, response + 20, compare);
    cout << "\nPhrase, Type:" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << response[i].phrase << ", "
             << response[i].type << endl;
    }
}

//*********************************************************************************************************
// Requirement D
//*********************************************************************************************************
/// @brief
void writeResponsesToFile(Response *response) {
    // initialize ofstream
    ofstream outfile;
    // open or create output.txt file
    outfile.open("output.txt");
    // iterate through data
    for (int i =0; i<MAXSIZE(); ++i) {
        sort(response, response + 20, compare);
        // store to output.txt
        outfile << response[i].phrase << "\n"
                << response[i].type << endl;
    }
    // let user know of successful file output
    cout << "\nSuccessfully stored to file!" << endl;
}

//*********************************************************************************************************
// Extra credit
//*********************************************************************************************************
/// @brief
void deleteResponse(Response *response) {
    //TODO Delete a Response
     int index;
    cout << "What index do you want to delete?" << endl;
    cin >> index;
    while (index >= MAXSIZE()) {
        cout << "Out of bounds!" << endl
             << "Try Again!" << endl;
        cin >> index;
    }

    memmove(response + index, response + (index + 1), (MAXSIZE()-index - 1) * sizeof(Response));

    cout << "Deleted " << index << " successfully!" << endl;
}

/// @brief  bool function to handle menu
/// @return true unless user want to exit program
bool menu(Response *response) {
    cout << "\n\n--------------------------------" << endl;
    cout << "\t\t\tMenu";
    cout << "\n--------------------------------" << endl;
    cout << "A. Read responses from a file" << endl;
    cout << "B. Play Magic Eight Ball" << endl;
    cout << "C. Print out responses and categories alphabetically" << endl;
    cout << "D. Write responses to a file" << endl;
    cout << "E. Delete Response" << endl;
    cout << "F. Exit" << endl;
    cout << "Enter your choice: " << endl;

    char choice;
    cin >> choice;

    switch (choice) {
        case 'a':
        case 'A':
            readResponses(response);
            break;
        case 'b':
        case 'B':
            playMagic8(response);
            break;
        case 'c':
        case 'C':
            printResponsesAndCategories(response);
            break;
        case 'd':
        case 'D':
            writeResponsesToFile(response);
            break;
        case 'e':
        case 'E':;
            deleteResponse(response);
            break;
        case 'f':
        case 'F':
            return false;
        default:
            unknownInput();
    }// switch
    cout << endl;
    return true;
}// bool menu