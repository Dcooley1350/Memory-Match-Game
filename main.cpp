
#include <iostream>
#include "matchingGame.hpp"

int main() {
    // Greet user and display instructions
    displayInstructions();

    // Start game loop
    do {
        std::cout << "New Game initializing!" << std::endl;

        // Initialize all game data points
        const Cell ** gameBoard = createBoard();
        Move flip1{}, flip2{};
        int turnCount = 0;

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

            // Update board with turn results
            updateBoard(flip1, flip2, gameBoard);

        } while (checkEndGame(gameBoard));

        showBoard(flip1, flip2, gameBoard);
        // Notify of game end and results
        std::cout << "Game Over! You win!" << std::endl
        << "It took you " << turnCount << " turns to finish the game! Nice work!" << std::endl;

    } while(yesOrNo(PLAY_AGAIN));

    std::cout << "Thank you for playing memory match! BYE!" << std::endl;

    return 0;
}
