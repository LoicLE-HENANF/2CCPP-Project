#define SUPPORT_MODULE_RSHAPES 1
#include "headers/Settings.h"
#include "headers/GameObjects/Game.h"


int main()
{
    Game game{};


    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}