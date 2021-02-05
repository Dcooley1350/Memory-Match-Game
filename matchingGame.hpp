
#include <string>

using std::string;

#ifndef WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP
#define WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP

// Constants
const int
    BOARD_DIMENSION = 4,
    BOARD_SIZE = BOARD_DIMENSION * BOARD_DIMENSION,
    MIN_CELL_NUM = 1,                  // For use in input validation
    MAX_CELL_NUM = 4,
    NUM_GAME_PIECES = 8;

const char
    GAME_PIECES [8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' },
    YES_NO [2] = { 'Y', 'N' },        // For use in input validation
    GAME_SPACES [2] = { ' ', 'X' };



const string
    PLAY_AGAIN = "Would you like to play again?",
    ENTER_ROW = "Enter the row coordinate of the card you would like to flip (y-axis)(1-4)",
    ENTER_COLUMN = "Enter the column coordinate of the card you would like to flip (x-axis)(1-4)",
    INVALID_MOVE = "Invalid flip detected! Please make sure the cell exists and is not the same as the first flip!";

// Structs
struct Move {
    int row;
    int column;
};

struct Cell {
    bool found;
    char value;
};

// Helper function prototypes
int getInteger(const int, const int);
bool yesOrNo(const string&);
bool isThere(const Move&, Cell**);
int getIndex(const Move&);
void collectCoordinates(Move&);
bool movesEquivalent(const Move&, const Move&);
bool validateCharacterInput(const char, const char *,const int);
void resetStream();

// Game function prototypes
void displayInstructions();
Cell ** createBoard();
void shuffle( Cell **);
void getMove(Move&, Cell**);
void getMove(const Move&, Move&, Cell**);
void showBoard(Cell**);
void showBoard(const Move&, Cell**);
void showBoard(const Move&, const Move&, Cell**);
bool checkMatch(const Move&, const Move&, Cell**);
void updateBoard(const Move&, const Move&, Cell**);
bool checkEndGame(Cell**);

#endif //WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP
