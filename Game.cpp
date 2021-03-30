//
// Created by dshpu on 12/1/2020.
//

#include "Game.h"

void Game::loadGameWindow() {
    window.create(sf::VideoMode(400, 500), "Tic-Tac-Toe");
}

bool Game::loadPieceFiles() {
    return (gameBoard.loadFromFile("board.png") &&
            pieceX.loadFromFile("x.png") && pieceO.loadFromFile("o.png"));
}

bool Game::loadFontFile(){
    return (fontType.loadFromFile("arial.ttf"));
}

void Game::setGamePieces() {
    addBoard.setTexture(gameBoard);
    addX.setTexture(pieceX);
    addO.setTexture(pieceO);
}

void Game::setUserPrompt() {
    message.setString("Player 1's turn");
    message.setFont(fontType);
    message.setCharacterSize(40);
    message.setColor(sf::Color::Black);
    message.move(95, 410);
}

void Game::updateUserPrompt(int turn, bool invalidPos){
    std::string playerPrompt;
    if(invalidPos){
        playerPrompt = "Position already\n     taken!";
    } else {
        playerPrompt = turn % 2 == 0? "Player 1's turn" : "Player 2's turn";
    }

    message.setString(playerPrompt);

}

void Game::setRectCoordinates(sf::IntRect &rect, int rectLeft, int rectTop, int rectWidth, int rectHeight){
    rect.left = rectLeft;
    rect.top = rectTop;
    rect.width = rectWidth;
    rect.height = rectHeight;
}

void Game::rectangleCoordinates(){
    setRectCoordinates(square[0], 0, 0, 113, 120);
    setRectCoordinates(square[1], 126, 0, 262, 120);
    setRectCoordinates(square[2], 276, 0, 400, 120);

    setRectCoordinates(square[3], 0, 133, 113, 270);
    setRectCoordinates(square[4], 126, 133, 262, 270);
    setRectCoordinates(square[5], 276, 133, 400, 270);

    setRectCoordinates(square[6], 0, 283, 113, 400);
    setRectCoordinates(square[7], 126, 283, 262, 400);
    setRectCoordinates(square[8], 276, 283, 400, 400);
}

void Game::setPositionPieces(sf::Vector2i &pos, int left, int top){
    pos.x = left;
    pos.y = top;

}

void Game::positionPiece() {
    setPositionPieces(position[0], 15, 20);
    setPositionPieces(position[1], 162, 20);
    setPositionPieces(position[2], 300, 20);

    setPositionPieces(position[3], 15, 166);
    setPositionPieces(position[4], 162, 166);
    setPositionPieces(position[5], 300, 166);

    setPositionPieces(position[6], 15, 316);
    setPositionPieces(position[7], 162, 316);
    setPositionPieces(position[8], 300, 316);
}

bool Game::isClickInBounds(int boardPos){
    return event.mouseButton.x >= square[boardPos].left
           && event.mouseButton.x <= square[boardPos].width
           && event.mouseButton.y >= square[boardPos].top
           && event.mouseButton.y <= square[boardPos].height;
}

bool Game::takeTurn(int turn){
    for(int boardPos = 0; boardPos < 9; boardPos++){
        if(isClickInBounds(boardPos)){
            if(square[boardPos].left != -500){
                piece[turn] = turn % 2 == 0? addX : addO;
                piece[turn].move(position[boardPos].x, position[boardPos].y);
                square[boardPos].left = -500;
                cout << "Yes";
                updateUserPrompt(turn, false);
                return true;
            }
            else {
                updateUserPrompt(turn, true);
                return false;
            }
        }
    }
}

void Game::gameLoop(){
    int turn = 0;
    setUserPrompt();
    rectangleCoordinates();
    positionPiece();

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && turn < 9){
                if(takeTurn(turn)){
                    turn++;
                    //cout << "Yes";
                }
            }
        }

        //cout << "yes ";
        window.clear(sf::Color(0, 150, 0));
        window.draw(addBoard);
        window.draw(message);
        for (int pieceIdx = 0; pieceIdx < 9; pieceIdx++) {
            window.draw(piece[pieceIdx]);
        }
        window.display();

    }

}