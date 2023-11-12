#include "headers/Game.h"
#include "headers/Board.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{screenWidth, screenHeight, 60, "Laying Grass"};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}