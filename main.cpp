/* CSCI 261: Final Project
 *
 * Author: Danil Shpurik
 *
 *    This program will create a Tic-Tac-Toe game that you can play with your
 *    friend using the numbers on your keyboard and SFML.
 *    This program itself will utilize almost everything we have learned including
 *    an original class with many functions and private data members.
 *    There are multiple arrays that store sprites and numbers. It also uses
 *    file I/O to store the high score from previous attempts.
 */

#include "Game.h"

#include <iostream>
using namespace sf;

int main() {

    // The following output statements are the preface for the game with rules and other info.
    cout << endl;
    cout << "So you think you are better then your friend?" << endl;
    cout << "Well joust them in a classic game of Tic-Tac-Toe game." << endl;
    cout << "Remember to use the numbers on your keyboard to set an X or O." << endl;
    cout << "You will play until either of you win or tie." << endl;
    cout << "The high score for Player 1 will be stored in the highscores.txt file" << endl;
    cout << endl;

    // The following line will create an object of the class 'Game'.
    Game ticTacToe;

    // The following if-statements will load in any files or .png(s) \
    // used in this program.
    if (!ticTacToe.loadFontsAndPics()) {
        return EXIT_FAILURE;    // used to indicate that the .png(s)
                                // were not opened correctly
    }
    if (!ticTacToe.openHighScore()) {
        return -1;              // used to indicate that the file
                                // was not opened correctly
    }

    // The following line will set the textures of the board, X, and O's.
    ticTacToe.setPieces();

    // The following line will begin the loop that will start the game and keep it going.
    ticTacToe.gameLoop();

    // After the game is over, the high score will be compared to the
    // previous score and if there is none, then it will set a new one.
    ticTacToe.checkHighScores();

    return EXIT_SUCCESS;    // used to properly exit the window
}