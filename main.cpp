#include "headers/Game.h"
#include "src/Game.cpp"

#include "headers/Board.h"
#include "headers/settings.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{settings::screenWidth,
              settings::screenHeight,
              settings::fps,
              settings::title};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}