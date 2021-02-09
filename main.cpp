
#include <iostream>
#include "matchingGame.hpp"

int main() {
    // Seed rand
    srand(static_cast<unsigned int>(time(nullptr)));

    // Greet user and display instructions
    displayInstructions();

    // Start game loop
    do {
        std::cout << "New Game initializing!" << std::endl;

        // Initialize all game data points
        Cell ** gameBoard = createBoard();
        Move flip1{}, flip2{};
        int turnCount = 0;
        // Start turn loop
        do {
            // Increment turn counter
            ++turnCount;
            // Show pre-flip game board state
            showBoard(gameBoard);

            // Get first move
            getMove(flip1, gameBoard);

            // Show board with first flip
            showBoard(flip1, gameBoard);

            // Get second move
            getMove(flip1, flip2, gameBoard);

            // Show board with both flips
            showBoard(flip1, flip2, gameBoard);

            // Check match and conditionally update board
            if(checkMatch(flip1, flip2, gameBoard))
            {
                std::cout << "Match! Well done!" << std::endl;
                // Update board with turn results
                updateBoard(flip1, flip2, gameBoard);
            }
            else
            {
                std::cout << "No Match! Try Again!" << std::endl;
            }


        } while (checkEndGame(gameBoard));

        showBoard(flip1, flip2, gameBoard);
        // Notify of game end and results
        std::cout << "Game Over! You win!" << std::endl
        << "It took you " << turnCount << " turns to finish the game! Nice work!" << std::endl;
        // Garbage collect all Cells and pointers to cells.
        for (int i = 0; i < BOARD_SIZE; ++i) {
            delete  *(gameBoard + i);
        }
        delete [] gameBoard;
    } while(yesOrNo(PLAY_AGAIN));

    std::cout << "Thank you for playing memory match! BYE!" << std::endl;

    return 0;
}
