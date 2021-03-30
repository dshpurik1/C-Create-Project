/* CSCI 261: Final Project
 *
 * Author: Danil Shpurik
 *
 *    This declaration file for the Game stores all the variables and functions that will
 *    be utilized in the functions file. It also includes the libraries and namespaces
 *    that will clear up the functions file a little bit.
 */

#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game {
public:
    /** @brief creates a default constructor
     * @desc Creates a default constructor with two variables,
     * _wins and _counter both set to 0
     */
    Game();
    /** @brief loads all .png(s) and fonts
     * @return boolean if the .png(s) and fonts opened
     */
    bool loadFontsAndPics();
    /** @brief checks if the file opened
     * @desc checks if highscores.txt opens properly and returns the boolean
     * @return boolean if the file opened or not
     */
    bool openHighScore();
    /** @brief inputs the integer in the file and compares it to the high score
     * @desc inputs the integer and if the high score made currently is higher,
     * then it will replace the value in the file with file I/O
     */
    void checkHighScores();
    /** @brief returns the number of wins at the end
     * @return value of wins by Player 1 during the game
     */
    int countWin() const;
    /** @brief adds the texture made in MS Paint to the sprites
     * @return sprites with the proper texture applied
     */
    void setPieces();
    /** @brief used to reset all the values back to their default states.
     * @return a bunch of variables set back to their default values and arrays
     * that are cleared of any values
     */
    void reset ();
    /** @brief checks if there is a winning condition on the board for Player 1
     * @desc adds up the values in a row to see if they equal 3. If they do, then
     * return a value of true with other variables set to certain numbers to trigger
     * other events like the message and clearing the board
     * @return boolean if there are X or O's in a row at any point during the game
     */
    bool checkWin();
    /** @brief checks if there is a winning condition on the board for Player 2
     * @desc adds up the values in a row to see if they equal 3. If they do, then
     * return a value of true with other variables set to certain numbers to trigger
     * other events like the message and clearing the board
     * @return boolean if there are X or O's in a row at any point during the game
     */
    bool checkWinOther();
    /** @brief using what key Player 1 pressed, place the X in the correct place
     * @desc there are nine cases that see what number is pressed and then
     * place an X in the proper location after the button has been pressed
     * @return a counter that has increased by one, an array with the X in the
     * proper location, and an array that has the corresponding element changed to
     * one so that the program knows that space is occupied
     */
    int player(const int key);
    /** @brief using what key Player 2 pressed, place the O in the correct place
     * @desc there are nine cases that see what number is pressed and then
     * place an O in the proper location after the button has been pressed
     * @return a counter that has increased by one, an array with the O in the
     * proper location, and an array that has the corresponding element changed to
     * one so that the program knows that space is occupied
     */
    int otherPlayer(const int key);
    /** @brief depending on the integer of _message, output the respective message
     * @return message that is placed in the proper location and named correctly
     * depending on the value inputted
     */
    Text message();
    /** @brief render the window with all the proper calls to all the previous functions
     * @desc renders a window that checks for what keys are pressed and sending them
     * to the proper function. It also calls to check if the game has a winning
     * condition at any point and output all the proper .png(s) at the right time.
     * @return a closed window when the user exits out
     */
    void gameLoop();

private:
    Event _event;
    Font _font;
    ifstream _inputHighScore;
    Text _text;
    Texture _gameBoard;
    Texture _coolO;
    Texture _coolX;
    Sprite _addingBoard;
    Sprite _addingO;
    Sprite _addingX;
    Sprite _piece[9];
    int _counter;
    int _highScore;
    int _message;
    int _otherTracker[9];
    int _tracker[9];
    int _wins;
};

#endif //GAME_H
