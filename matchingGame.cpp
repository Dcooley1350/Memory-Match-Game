
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include <random>
#include <chrono>
#include "matchingGame.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::shuffle;

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

bool yesOrNo(const string &question)
{
    char userInput;
    bool isYes, validInput;
    // Ask user question
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
        isYes = true;
    }
    else {
        isYes = false;
    }
    return isYes;
}

bool isThere(const Move &flip, Cell** gameBoard)
{
    // Check if the Cell at the index of the move if found yet or not
    return !(*(gameBoard + getIndex(flip)))->found;
}

int getIndex(const Move &flip)
{
    // Flatten the array index from the column and row values in a Move
    return (flip.column * BOARD_DIMENSION + flip.row);
}

int getIndex(const int row, const int column)
{
    // Flatten the array index from a row and column coordinate
    return row * BOARD_DIMENSION + column;
}

void collectCoordinates(Move &flip)
{
    cout << ENTER_ROW << endl;
    // Subtract 1 to translate coordinate 1-4 into array value 0-3;
    flip.row = getInteger(MIN_CELL_NUM, MAX_CELL_NUM) - 1;
    cout << ENTER_COLUMN << endl;
    flip.column = getInteger(MIN_CELL_NUM, MAX_CELL_NUM) - 1;
}

bool movesEquivalent(const Move &flip1, const Move &flip2)
{
    // Check if the 2 moves have the same row and column values
    return (flip1.row == flip2.row && flip1.column == flip2.column);
}

bool validateCharacterInput(const char input, const char *validInputs, const int validInputsLength)
{
    // Check if the input value exists in the array of acceptable inputs
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
    << "You will designate the card you want to flip by giving coordinates." << endl
    << "Ex: The bottom right corner in the 4x4 game board is (4,4)" << endl
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

void shuffle(Cell **gameBoard)
{
    // Shuffle all the cells into random order
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(gameBoard, (gameBoard + BOARD_SIZE), std::default_random_engine(seed));
}

void getMove(Move &flip, Cell **gameBoard)
{
    bool invalidMove;
    do {
        // Get coordinates from user
        collectCoordinates(flip);
        // Check to see that the card is still there
        if(isThere(flip,gameBoard))
        {
            invalidMove = false;
        }
        else
        {
            invalidMove = true;
            cout << INVALID_MOVE << endl;
        }
    } while(invalidMove);
}

void getMove(const Move &otherFlip, Move &thisFlip, Cell **gameBoard)
{
    bool invalidMove;
    do {
        // Get coordinates from user
        collectCoordinates(thisFlip);
        // Check to see that the card is still there and that it is not the same spot as the other flip
        if(isThere(thisFlip,gameBoard) && !movesEquivalent(otherFlip, thisFlip))
        {
            invalidMove = false;
        }
        else
        {
            invalidMove = true;
            cout << INVALID_MOVE << endl;
        }
    } while(invalidMove);
}

void showBoard(Cell ** gameBoard)
{
    for (int i = 0; i < BOARD_DIMENSION; ++i) {
        for (int j = 0; j < BOARD_DIMENSION; ++j) {
            cout << setw(STREAM_WIDTH);
            // Show all cells either found or not found
            if((*(gameBoard + (i * BOARD_DIMENSION) + j))->found)
            {
                cout << GAME_SPACES[0];
            }
            else
            {
                cout << GAME_SPACES[1];
            }
        }
        //Output new line at the end of every 'row'
        cout << std::endl;
    }
}

void showBoard(const Move &flip, Cell ** gameBoard)
{
    for (int i = 0; i < BOARD_DIMENSION; ++i) {
        for (int j = 0; j < BOARD_DIMENSION; ++j) {
            cout << setw(STREAM_WIDTH);
            // If the Cell is found, show empty
            if((*(gameBoard + (i * BOARD_DIMENSION) + j))->found)
            {
                cout << GAME_SPACES[0];
            }
            else
            {
                // If cell is at index of move, show value
                if(getIndex(i,j) == getIndex(flip))
                {
                    cout << (*(gameBoard + getIndex(flip)))->value;
                }
                else
                {
                    // Show cell 'X' if cell is not found or flipped
                    cout << GAME_SPACES[1];
                }
            }
        }
        //Output new line at the end of every 'row'
        cout << std::endl;
    }
}

void showBoard(const Move &flip1, const Move &flip2, Cell **gameBoard)
{
    for (int i = 0; i < BOARD_DIMENSION; ++i) {
        for (int j = 0; j < BOARD_DIMENSION; ++j) {
            cout << setw(STREAM_WIDTH);
            // If Move index equals Cell index, show the value of the Cell
            if(getIndex(i,j) == getIndex(flip1))
            {
                cout << (*(gameBoard + getIndex(flip1)))->value;
            }
            else if (getIndex(i,j) == getIndex(flip2))
            {
                cout << (*(gameBoard + getIndex(flip2)))->value;
            }
            else
            {
                // Show default 'X' or ' ' if Cells are not flip
                if((*(gameBoard + (i * BOARD_DIMENSION) + j))->found)
                {
                    cout << GAME_SPACES[0];
                }
                else
                {
                    cout << GAME_SPACES[1];
                }
            }
        }
        //Output new line at the end of every 'row'
        cout << std::endl;
    }
}

bool checkMatch(const Move &flip1, const Move &flip2, Cell **gameBoard)
{
    // Compare value in cells at the index of each move
    return (*(gameBoard + getIndex(flip1)))->value == (*(gameBoard + getIndex(flip2)))->value;
}

void updateBoard(const Move &flip1, const Move &flip2, Cell **gameBoard)
{
    // Set Cells at the move locations to found
    (*(gameBoard + getIndex(flip1)))->found = true;
    (*(gameBoard + getIndex(flip2)))->found = true;
}

bool checkEndGame(Cell **gameBoard)
{
    bool cellsRemaining = false;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        // Check found property in each cell, if all are found, game is over
        if(!(*(gameBoard + i))->found)
        {
            cellsRemaining = true;
        }
    }
    return cellsRemaining;
}


