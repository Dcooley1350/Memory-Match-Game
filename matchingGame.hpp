
#include <string>

using std::string;

#ifndef WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP
#define WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP

// Constants
const char
    GAME_PIECES [8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' },
    YES_NO [2] = { 'Y', 'N' },        // For use in input validation
    GAME_SPACES [4] = { ' ', 'X' };

const int
    BOARD_SIZE = 16,
    MIN_FLIP_NUM = 1,                  // For use in input validation
    MAX_SPACE_NUM = 4;

const string PLAY_AGAIN = "Would you like to play again?";

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
bool yesOrNo(string);
bool isThere(const Move&);
int getIndex(const Move&);
bool validateCharacterInput(const char, const char *,const int);
void resetStream();

// Game function prototypes
void displayInstructions();
const Cell ** createBoard();
void shuffle(const Cell **);
void getMove(Move&, const Cell**);
void getMove(Move&, Move&, const Cell**);
void showBoard(const Cell**);
void showBoard(const Move&, const Cell**);
void showBoard(const Move&, const Move&,  const Cell**);
bool checkMatch(const Move&, const Move&);
void updateBoard(const Move&, const Move&, const Cell**);
bool checkEndGame(const Cell**);

#endif //WK5LABPARTBDCOOLEY_MATCHINGGAME_HPP
