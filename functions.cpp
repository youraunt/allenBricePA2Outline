/*
 *  Name: Brice Allen
 *  Date: 10/02/2019
 *  Class: CSCI 1410-003
 *  Description: RA2 A program that acts as an eight-ball
 *  allowing users to ask a questions and get a response.
 *  Status: Compiles and runs on Clion
 * */

#include "functions.h"

std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    exit(EXIT_SUCCESS);
}

/// @brief function to define sizeLimit
/// @return specified sizeLimit
int sizeLimit() {
    return 100;
};

/// @brief Handles unusable input
void unknownInput() {
    std::cout << "Error?! Please, try again: " << std::endl;
}

/// @brief Displays error and exits program
void fileNotFound() {
    std::cerr << "File not found! \nExiting Program!" << std::endl;
    exit(EXIT_FAILURE);
}

/// @brief Helper function to sort alphabetically by phrase
/// @param lhs
/// @param rhs
/// @return
bool compare(const struct Response &lhs, const struct Response &rhs) { return lhs.phrase < rhs.phrase; }// bool compare

//*********************************************************************************************************
// Requirement A
//*********************************************************************************************************
/// @brief Function to read responses in from file
/// @param response The storage container being read into.
/// @param currentSize The current size of the array
/// @return
void readResponses(Response *response, int responseMax, int &currentSize) {
    // initiate file stream
    std::ifstream infile;
    // open file
    infile.open("data.txt");
    /* check that file exists and is valid else display
     * error and exit program with error
     */
    if (!infile || infile.fail()) { fileNotFound(); }
    if (currentSize < responseMax) {
        for (int i = 0; i < 20; ++i) {
            // grab lines from file
            getline(infile, response[i].phrase);
            getline(infile, response[i].type);
            currentSize++;
        }
    }//while
    // let user know that file was read successfully
    std::cout << "Responses successfully uploaded!" << std::endl;
    infile.close();
}//readResponses

//*********************************************************************************************************
// Requirement B
// function playMagic8 to ask the ball questions and get responses
//*********************************************************************************************************
/// @brief
/// @param response
/// @param currentSize
void playMagic8(Response *response,int responseMax, int &currentSize) {

    // @todo Implement a if statement to open file if has
    //      not already been opened by step a
   /* readResponses(response, responseMax, currentSize);*/

    // declare local variable
    std::string question;
    // prompt user to enter a question
    std::cout << "\nEnter your question: " << std::endl;
    std::cin.ignore();

    do {
        // ignore blank input
        /*std::cin.clear();*/
        // get user input store string variable question
        getline(std::cin, question);
        if(question == "f"){break;}
        question[0]=toupper(question[0]);
        // create object for seeding
        std::random_device randomDevice;
        // create engine and seed it
        std::mt19937 engine{randomDevice()};
        // distribution in range [1, currentSize+0] I don't know why it like the + 0 but it works
        std::uniform_int_distribution<std::mt19937::result_type> dist20(0, currentSize + 0);
        // assign random number to int type variable named randomNumber
        int randomNumber = dist20(engine);
        // display users question with punctuation
        std::cout << question << " ?" << std::endl;
        // display random phrase and type
        std::cout << response[randomNumber].phrase << std::endl;
        std::cout << response[randomNumber].type << std::endl;
        std::cout << "\nEnter a question to play again." << std::endl
                  << "Enter f to exit the game." << std::endl;

    } while (question != "f");

}//playMagic8

//*********************************************************************************************************
// Requirement C
//*********************************************************************************************************
/// @brief
/// @param response
/// @param responseMax
/// @param currentSize
void printResponsesAndCategories(Response *response, int responseMax, int &currentSize) {
    sort(response + 0, response + currentSize, compare);
    std::cout << "\nPhrase, Type:" << std::endl;
    if (currentSize > responseMax) {
        unknownInput();
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < currentSize; i++) {
        std::cout << i << ": "
                  << response[i].phrase << " "
                  << response[i].type << std::endl;
    }//if
}//printResponseAndCategories

//*********************************************************************************************************
// Requirement D
//*********************************************************************************************************
/// @brief
/// @param response
/// @param currentSize
void writeResponsesToFile(Response *response, int &currentSize) {
    // initialize ofstream
    std::ofstream outfile;
    // open or create output.txt file
    outfile.open("output.txt");
    // iterate through data
    for (int i = 0; i < currentSize; ++i) {
        sort(response, response + currentSize, compare);
        // store to output.txt
        outfile << i << ". "
                << response[i].phrase << " "
                << response[i].type << std::endl;
    }//for
    // let user know of successful file output
    std::cout << "\nSuccessfully stored to file!" << std::endl;
}// writeResponseToFile

//*********************************************************************************************************
// Extra credit
//*********************************************************************************************************
/// @brief Function to delete an element by user supplied index number
/// @param response
/// @param currentSize
void deleteResponse(Response *response, int &currentSize) {
    int index;
    std::cout << "What index do you want to delete? 0 - " << (currentSize - 1) << std::endl;
    do {
        std::cin >> index;
        if(index == -1){break;}
        while (std::cin.fail() || index >= currentSize) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            unknownInput();
            std::cin >> index;
        }//while
        std::string deletedIndex = response[index].phrase;
        /// @brief The memmove() function copies len bytes from string src to string dst.
        //     The two strings may overlap; the copy is always done in a non-destructive
        //     manner.
        //  @param dst: destination Pointer to the destination array where the content is to be copied,
        //      type-casted to a pointer of type void*.
        //  @param src: source Pointer to the source of data to be copied,
        //      type-casted to a pointer of type const void*
        //  @return The memmove() function returns the original value of dst.
        memmove(response + index, response + (index + 1), (currentSize - index - 1) * sizeof(Response));
        currentSize = (currentSize - 1);
        std::cout << "Deleted index " << index << ", " << "\"" << deletedIndex << "\"" << " successfully!" << std::endl;
        std::cout << "\nEnter an index to delete another entry." << std::endl
                  << "Enter -1 to exit." << std::endl;
    } while (index!=-1);
}// deleteResponse

/// @brief bool function to handle menu
/// @param response
/// @param responseMax
/// @param currentSize
/// @return true until user wants to exit program
bool menu(Response *response, int responseMax, int &currentSize) {
    std::cout << "\n\n-----------------------------" << std::endl
              << "\t\t\tMenu"
              << "\n-----------------------------" << std::endl
              << "A. Read responses from a file" << std::endl
              << "B. Play Magic Eight Ball" << std::endl
              << "C. Print out responses and categories alphabetically" << std::endl
              << "D. Write responses to a file" << std::endl
              << "E. Delete Response" << std::endl
              << "F. Exit" << std::endl
              << "Enter your choice: " << std::endl;

    char choice;
    std::cin >> choice;
    choice = toupper(choice);
    switch (choice) {
        case 'A':
            readResponses(response, responseMax, currentSize);
            break;
        case 'B':
            playMagic8(response, responseMax, currentSize);
            break;
        case 'C':
            printResponsesAndCategories(response, responseMax, currentSize);
            break;
        case 'D':
            writeResponsesToFile(response, currentSize);
            break;
        case 'E':
            deleteResponse(response, currentSize);
            break;
        case 'F':
            return false;
        default:
            unknownInput();
    }// switch
    std::cout << std::endl;
    return true;
}// bool menu