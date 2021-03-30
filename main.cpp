/* CSCI 261: SFML Drawing
 *
 * Author: Danil Shpurik
 *
 *    This program utilizes SFML to draw a near replica of the Mines logo.
 *    And yes, I did have to find all the points for the convex shapes to make it as similar as possible.
 */

#include <iostream>
#include "Game.h"
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    Game game;
    game.loadGameWindow();
    if(!game.loadPieceFiles())
        return EXIT_FAILURE;

    game.setGamePieces();

    if(!game.loadFontFile())
        return EXIT_FAILURE;

    game.gameLoop();

    return EXIT_SUCCESS;
}
