
#include <iomanip>
#include <iostream>
#include <limits>
#include "matchingGame.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
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

bool isThere(const Move &flip, Cell** gameBoard)
{
    return !(*(gameBoard + getIndex(flip)))->found;
}

int getIndex(const Move &flip)
{
    return (flip.column * BOARD_DIMENSION + flip.row);
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
    // Dynamically create game-board
    Cell ** gameBoard = new Cell*[BOARD_SIZE];

    // Dynamically fill Cells
    for (int i = 0; i < NUM_GAME_PIECES; ++i) {
        // Fill 2 Cells with each value
        for (int j = 0; j < 2; ++j) {
            (*(gameBoard + (2 * i) + j )) = new Cell{ false, GAME_PIECES[i]};
        }
    }

    shuffle(gameBoard);
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

void showBoard(Cell ** gameBoard)
{
    const int STREAM_WIDTH = 4;
    for (int i = 0; i < BOARD_DIMENSION; ++i) {
        for (int j = 0; j < BOARD_DIMENSION; ++j) {
            cout << setw(STREAM_WIDTH)<< (*(gameBoard + (i * BOARD_DIMENSION) + j))->value;
        }
        //Output new line at the end of every 'row'
        cout << std::endl;
    }
}

void showBoard(const Move &flip, Cell ** gameBoard)
{
    const int STREAM_WIDTH = 4;
    for (int i = 0; i < BOARD_DIMENSION; ++i) {
        for (int j = 0; j < BOARD_DIMENSION; ++j) {
            cout << setw(STREAM_WIDTH)<< (*(gameBoard + getIndex(flip)))->value;
        }
        //Output new line at the end of every 'row'
        cout << std::endl;
    }
}

void showBoard(const Move &, const Move &, Cell **)
{

}

bool checkMatch(const Move &flip1, const Move &flip2, Cell **gameBoard)
{
    // Compare value in cells at the index of each move
    return (*(gameBoard + getIndex(flip1)))->value == (*(gameBoard + getIndex(flip2)))->value;
}

void updateBoard(const Move &, const Move &, Cell **)
{

}

bool checkEndGame(Cell **gameBoard)
{
    bool cellsRemaining;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        // Check found property in each cell, if all are found, game is over
        if(!(*(gameBoard + i))->found)
        {
            cellsRemaining = true;
        }
    }
    return cellsRemaining;
}


