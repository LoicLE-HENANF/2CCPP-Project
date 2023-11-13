#include "headers/Game.h"
#include "src/Game.cpp"

#include "headers/Board.h"
#include "headers/settings.h"

int main()
{
    Game game{settings::screenWidth,
              settings::screenHeight,
              settings::fps,
              settings::title};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}