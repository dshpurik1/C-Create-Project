//
// Created by dshpu on 12/1/2020.
//

#ifndef SFML_TEMPLATE_GAME_H
#define SFML_TEMPLATE_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Game {
private:
    sf::RenderWindow window;
    sf::Texture gameBoard, pieceX, pieceO;
    sf::Sprite addBoard, addX, addO, piece[9];
    sf::Font fontType;
    sf::Text message;
    sf::IntRect square[9];
    sf::Vector2i position[9];
    sf::Event event;
public:
    void loadGameWindow();
    bool loadPieceFiles();
    bool loadFontFile();
    void setGamePieces();
    void setUserPrompt();
    void rectangleCoordinates();
    void setRectCoordinates(sf::IntRect &rect, int left, int top, int width, int height);
    void setPositionPieces(sf::Vector2i &pos, int left, int top);
    void positionPiece();
    bool isClickInBounds(int boardPos);
    bool takeTurn(int player);
    void updateUserPrompt(int turn, bool invalidPos);
    void gameLoop();

};


#endif //SFML_TEMPLATE_GAME_H
