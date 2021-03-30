/* CSCI 261: Final Project
 *
 * Author: Danil Shpurik
 *
 *    This functions file will house all the main parts of the program that will
 *    load all the files, .png(s), and fonts used in the game. It will also
 *    render the window, display all the images and fonts and allow the user
 *    to only press numbers on the keyboard to add corresponding sprites
 *    to those sections. It will check for winners and compare if that is more then
 *    the high score from previous tries.
 */

#include "Game.h"

// This is a default constructor
Game::Game() {
    _wins = 0;
    _counter = 0;
}

// This next function opens the pictures
bool Game::loadFontsAndPics() {
    return (_gameBoard.loadFromFile("coolBoard.png")
            && _coolO.loadFromFile("coolO.png")
            && _coolX.loadFromFile("coolX.png")
            && _font.loadFromFile("arial.ttf"));
}

// This next function opens the highscore.txt file
bool Game::openHighScore() {
    _inputHighScore.open("highscores.txt");
    if (_inputHighScore.fail()) {
        return false;
    } else {
        return true;
    }
}

// This next function will look through the highscores.txt file and see if the current
// highscore is higher then the previous score and change it if it is
void Game::checkHighScores() {
    ifstream highScore("highscores.txt");
    highScore >> _highScore;
    if (_highScore < countWin()) {
        if (countWin() - _highScore == 1) {
            cout << "Congratulations! You beat your previous record of " << _highScore
                 << " by 1 win!" << endl;
        } else {
            cout << "Congratulations! You beat your previous record of " << _highScore
                 << " by " << (countWin() - _highScore) << " wins!" << endl;
        }
        ofstream highScore("highscores.txt");
        highScore << countWin();
    } else {
        cout << "Ah shucks. You did not beat your previous score of "
             << _highScore << "." << endl;
        cout << "Good luck next time!" << endl;
    }
    highScore.close();
}

// This next function will count the number of real wins Player 1 gets in the game
int Game::countWin() const {
    return (_wins - 1);
}

// This next functions sets the sprites texture to the pictures I drew
void Game::setPieces() {
    _addingBoard.setTexture(_gameBoard);
    _addingO.setTexture(_coolO);
    _addingX.setTexture(_coolX);
    _text.setFont(_font);
}

// The reason I have this next function instead of just calling the default constructor
// is because I need to clear all elements in an array which is easier this way
void Game::reset() {
    _wins++;
    for( int i = 0; i < 9; i++ ) {
        _tracker[i] = 0;
        _otherTracker[i] = 0;
        _piece[i] = Sprite();
    }
    _counter = 0;
    _message = 0;
}

/* This next function will add up the elements in a row to see if there
 * are three of a kind and if there is, return a boolean of true and a message value
 * so that the corresponding display will say if that Player 1 won
 */
bool Game::checkWin() {
    if( _tracker[0] + _tracker[1] + _tracker[2] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[3] + _tracker[4] + _tracker[5] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[6] + _tracker[7] + _tracker[8] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[0] + _tracker[3] + _tracker[6] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[1] + _tracker[4] + _tracker[7] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[2] + _tracker[5] + _tracker[8] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[0] + _tracker[4] + _tracker[8] == 3 ) {
        _message = 25;
        return true;
    } else if( _tracker[2] + _tracker[4] + _tracker[6 ] == 3 ) {
        _message = 25;
        return true;
    } else {
        return false;
    }
}

/* This next function will add up the elements in a row to see if there
 * are three of a kind and if there is, return a boolean of true and a message value
 * so that the corresponding display will say if that Player 2 won
 */
bool Game::checkWinOther() {
    if( _otherTracker[0] + _otherTracker[1] + _otherTracker[2] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[3] + _otherTracker[4] + _otherTracker[5] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[6] + _otherTracker[7] + _otherTracker[8] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[0] + _otherTracker[3] + _otherTracker[6] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[1] + _otherTracker[4] + _otherTracker[7] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[2] + _otherTracker[5] + _otherTracker[8] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[0] + _otherTracker[4] + _otherTracker[8] == 3 ) {
        _message = 75;
        return true;
    } else if( _otherTracker[2] + _otherTracker[4] + _otherTracker[6 ] == 3 ) {
        _message = 75;
        return true;
    } else {
        return false;
    }
}

/* The next function will input the key that was pressed and if that space is available,
 * place an X for player one in the same place the user clicked. Also output the correct message
 * and +1 on the turn counter
 */
int Game::player( const int key ) {
    if( key == Keyboard::Num1 ) {
        if( _tracker[0] == 1 || _otherTracker[0] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(100, 520);
            _piece[0] = _addingX;
            _tracker[0] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num2 ) {
        if( _tracker[1] == 1 || _otherTracker[1] == 1 ) {
            _message = 50;
            return 1;
        } else {
           _addingX.setPosition(325, 520);
           _piece[1] = _addingX;
           _tracker[1] = 1;
            _message = 0;
           return _counter++;
       }
    } else if( key == Keyboard::Num3 ) {
        if( _tracker[2] == 1 || _otherTracker[2] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(550, 520);
            _piece[2] = _addingX;
            _tracker[2] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num4 ) {
        if( _tracker[3] == 1 || _otherTracker[3] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(100, 370);
            _piece[3] = _addingX;
            _tracker[3] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num5 ) {
        if( _tracker[4] == 1 || _otherTracker[4] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(325, 370);
            _piece[4] = _addingX;
            _tracker[4] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num6 ) {
        if( _tracker[5] == 1 || _otherTracker[5] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(550, 370);
            _piece[5] = _addingX;
            _tracker[5] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num7 ) {
        if( _tracker[6] == 1 || _otherTracker[6] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(100, 220);
            _piece[6] = _addingX;
            _tracker[6] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num8 ) {
        if( _tracker[7] == 1 || _otherTracker[7] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(325, 220);
            _piece[7] = _addingX;
            _tracker[7] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num9 ) {
        if( _tracker[8] == 1 || _otherTracker[8] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingX.setPosition(550, 220);
            _piece[8] = _addingX;
            _tracker[8] = 1;
            _message = 0;
            return _counter++;
        }
    } else {
        _message = 100;
        return _message;
    }
}

/* The next function will input the key that was pressed and if that space is available,
 * place an O for player two in the same place the user clicked. Also output the correct message
 * and +1 on the turn counter
 */
int Game::otherPlayer(const int key) {
    if( key == Keyboard::Num1 ) {
        if( _tracker[0] == 1 || _otherTracker[0] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(100, 520);
            _piece[0] = _addingO;
            _otherTracker[0] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num2 ) {
        if( _tracker[1] == 1 || _otherTracker[1] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(325, 520);
            _piece[1] = _addingO;
            _otherTracker[1] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num3 ) {
        if(_tracker[2] == 1 || _otherTracker[2] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(550, 520);
            _piece[2] = _addingO;
            _otherTracker[2] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num4 ) {
        if( _tracker[3] == 1 || _otherTracker[3] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(100, 370);
            _piece[3] = _addingO;
            _otherTracker[3] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num5 ) {
        if( _tracker[4] == 1 || _otherTracker[4] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(325, 370);
            _piece[4] = _addingO;
            _otherTracker[4] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num6 ) {
        if( _tracker[5] == 1 || _otherTracker[5] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(550, 370);
            _piece[5] = _addingO;
            _otherTracker[5] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num7 ) {
        if( _tracker[6] == 1 || _otherTracker[6] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(100, 220);
            _piece[6] = _addingO;
            _otherTracker[6] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num8 ) {
        if( _tracker[7] == 1 || _otherTracker[7] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(325, 220);
            _piece[7] = _addingO;
            _otherTracker[7] = 1;
            _message = 0;
            return _counter++;
        }
    } else if( key == Keyboard::Num9 ) {
        if( _tracker[8] == 1 || _otherTracker[8] == 1 ) {
            _message = 50;
            return 1;
        } else {
            _addingO.setPosition(550, 220);
            _piece[8] = _addingO;
            _otherTracker[8] = 1;
            _message = 0;
            return _counter++;
        }
    } else {
        _message = 100;
        return _message;
    }
}

// The next function will take a look at the current value of _message and output the correct
// text that corresponds to actions that happened in the game
Text Game::message() {
    if( _message == 25 ) {
        _counter = 9;
        _text.setString("Player 1 Won!");
        _text.setPosition(240, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold | Text::Underlined);
        _text.setCharacterSize(50);
        return _text;
    } else if( _message == 75 ) {
        _counter = 9;
        _text.setString("Player 2 Won!");
        _text.setPosition(240, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold | Text::Underlined);
        _text.setCharacterSize(50);
        return _text;
    } else if( _counter == 9 ) {
        _text.setString("Nobody Won!");
        _text.setPosition(240, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold | Text::Underlined);
        _text.setCharacterSize(50);
        return _text;
    } else if( _message == 100 ) {
        _text.setString("Invalid Input! Try Again.");
        _text.setPosition(120, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold);
        _text.setCharacterSize(50);
        return _text;
    } else if( _message == 50 ) {
        _text.setString("Position Taken!");
        _text.setPosition(210, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold);
        _text.setCharacterSize(50);
        return _text;
    } else if( _counter % 2 == 0 ) {
        _text.setString("Your Turn Player 1:");
        _text.setPosition(185, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold);
        _text.setCharacterSize(50);
        return _text;
    } else if( _counter % 2 == 1 ) {
        _text.setString("Your Turn Player 2:");
        _text.setPosition(185, 130);
        _text.setFillColor(Color(0, 153, 0));
        _text.setStyle(Text::Bold);
        _text.setCharacterSize(50);
        return _text;
    } else {
        return Text();
    }
}

/* This next function will render the window and the loop that will be used to see all
 * the active pieces and messages. It will also check for events and output the correct
 * message and pieces depending on what gets pressed
 */
void Game::gameLoop() {
    RenderWindow window(VideoMode(750, 750), "Tic-Tac-Toe");
    reset();
    while( window.isOpen() ) {
        window.setKeyRepeatEnabled(false);
        window.clear(Color::Black);
        window.draw(_addingBoard);
        while( window.pollEvent(_event) ) {
            if( _event.type == Event::Closed ) {
                window.close();
            } else if( _counter % 2 == 0 && _counter != 9 ) {
                if( _event.type == sf::Event::KeyPressed ) {
                    player(_event.key.code);
                }
            } else if( _counter % 2 == 1 && _counter != 9 ) {
                if( _event.type == sf::Event::KeyPressed ) {
                    otherPlayer(_event.key.code);
                }
            } else if( _counter == 9 ) {
                if( Keyboard::isKeyPressed(Keyboard::C) ) {
                    reset();
                }
            }
            if( checkWin() ) {
                if( Keyboard::isKeyPressed(Keyboard::C) ) {
                    reset();
                }
            } else if( checkWinOther() ) {
                if( Keyboard::isKeyPressed(Keyboard::C) ) {
                    reset();
                }
            }
        }
        for( int i = 0; i < 9; i++ ) {
            window.draw(_piece[i]);
        }
        window.draw(message());
        window.display();
    }
}