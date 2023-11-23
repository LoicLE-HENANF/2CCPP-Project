#define SUPPORT_MODULE_RSHAPES 1
#include "headers/Settings.h"
#include "headers/Game.h"
#include "headers/GameStates.h"


int main()
{
    Game game{settings::screenWidth, settings::screenHeight, settings::fps, settings::title};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}