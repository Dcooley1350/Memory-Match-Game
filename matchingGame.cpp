
#include <iomanip>
#include <iostream>
#include <limits>
#include "matchingGame.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Helper function definitions
int getInteger(const int min, const int max)
{
    int userInput, validatedInput;
    bool validInput;
    do {
        cin >> userInput;
        // Validate input
        if( !cin.fail() && userInput >= min && userInput <= max ) {
            validInput = true;
            validatedInput = userInput;
            resetStream();
        }
        else {
            validInput = false;
            cout << "Invalid input detected. Try again" << endl;
        }
    } while(!validInput);

    return validatedInput;
}

bool yesOrNo(string question)
{
    char userInput;
    bool playAgain, validInput;
    cout << question << endl;
    do {
        cin >> userInput;
        // Uppercase the input to allow lower and uppercase entries
        userInput = static_cast<char>(toupper(userInput));
        if(validateCharacterInput(userInput, YES_NO, 2)){
            validInput = true;
        }
        else {
            cout << "Invalid input detected. Enter Y/N." << endl;
            resetStream();
            validInput = false;
        }
    } while(!validInput);
    if(userInput == 'Y'){
        playAgain = true;
    }
    else {
        playAgain = false;
    }
    return playAgain;
}

bool isThere(const Move &)
{
    return false;
}

int getIndex(const Move &)
{
    return 0;
}

bool validateCharacterInput(const char input, const char *validInputs, const int validInputsLength)
{
    bool validInput = false;
    for (int i = 0; i < validInputsLength; ++i) {
        if(validInputs[i] == input) {
            validInput = true;
        }
    }
    return validInput;
}

void displayInstructions()
{
    cout << "Welcome to Memory match!" << endl
    << "You will flip pairs of cards. If they match, they will be removed from the game-board" << endl
    << "If the pair does not match, they will be flipped back face-down" << endl
    << "Your goal is to empty the board in as few flips as possible" << endl
    << "Good Luck!" << endl;
}

void resetStream()
{
    const long large = std::numeric_limits<std::streamsize>::max();
    const char endLine = '\n';
    // Clear input and errors
    cin.clear();
    // Flush the buffer
    cin.ignore(large,endLine);
}

// Game function definitions
Cell **createBoard()
{
    return nullptr;
}

void shuffle(const Cell **)
{

}

void getMove(Move &, const Cell **)
{

}

void getMove(Move &, Move &, const Cell **)
{

}

void showBoard(const Cell **)
{

}

void showBoard(const Move &, const Cell **)
{

}

void showBoard(const Move &, const Move &, const Cell **)
{

}

bool checkMatch(const Move &, const Move &)
{
    return false;
}

void updateBoard(const Move &, const Move &, const Cell **)
{

}

bool checkEndGame(Cell **)
{

}


