#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Windows.h>

#include "Game.h"

int main() 
{

    //Init game
    srand(time(NULL));
    Game game;
    game.initAll();

    while (game.isWindowOpen()) 
    {

        //Update
        game.frameUpdate();

        //Render
        game.render();

    }

    return 0;
}