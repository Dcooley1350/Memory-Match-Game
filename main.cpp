
#include <iostream>
#include "matchingGame.hpp"

int main() {
    // Greet user and display instructions
    displayInstructions();

    // Create game-board and moves, create here because we can reuse for multiple rounds
    Cell ** gameBoard = createBoard();
    Move flip1{}, flip2{};
    // Start game loop
    do {


        do {

        } while (checkEndGame(gameBoard));

    } while(yesOrNo(PLAY_AGAIN));
    std::cout << "Thank you for playing memory match! BYE!" << std::endl;
    return 0;
}
