
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
    << "You will flip a pair of cards. If they match, they will be removed from the game-board" << endl
    << "If the pair does not match, they will be flipped back face-down" << endl
    << "Your goal is to empty the board in as few turns as possible" << endl
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
Cell ** createBoard()
{
    // Dynamically create gameboard
    Cell ** gameBoard = new Cell*[BOARD_SIZE];

    // Dynamically fill Cells to false and value=empty so we can gen random and check for empty in next loop
    for (int i = 0; i < BOARD_SIZE ; ++i) {
        *(gameBoard + i ) = new Cell{false, GAME_SPACES[0]};
    }

    // Loop through possible cell values and fill each cell
    for (int i = 0; i < NUM_GAME_PIECES; ++i) {
        // Fill 2 Cells with each value
        for (int j = 0; j < 2; ++j) {
            // Keep generating random numbers until empty cell address is found
            bool cellValueEmpty = false;
            do {
                int index = rand() % (BOARD_SIZE - 1);
                if((*(gameBoard + index))->value == GAME_SPACES[0])
                {
                    cellValueEmpty = true;
                    (*(gameBoard + index))->value = *(GAME_PIECES + i);
                }
            } while(!cellValueEmpty);
        }
    }
    return gameBoard;
}

void shuffle(Cell **)
{

}

void getMove(Move &,Cell **)
{

}

void getMove(Move &, Move &, Cell **)
{

}

void showBoard(Cell **)
{

}

void showBoard(const Move &, Cell **)
{

}

void showBoard(const Move &, const Move &, Cell **)
{

}

bool checkMatch(const Move &, const Move &)
{
    return false;
}

void updateBoard(const Move &, const Move &, Cell **)
{

}

bool checkEndGame(Cell **)
{

}


