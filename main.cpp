#include "headers/Game.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game{screenWidth, screenHeight, "Laying Grass"};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}