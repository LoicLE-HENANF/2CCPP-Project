#include "headers/settings.h"
#include "headers/Game.h"
#include "headers/GameStates.h"


// Simple Finite State Machine
GameState * GameState::mainMenu = new MenuPrincipal();
GameState * GameState::options = new Options();
GameState * GameState::playing = new Playing();
// add states here first from GameStates classes
GameState * GameState::currentState = GameState::mainMenu;

int main()
{
    Game game{settings::screenWidth, settings::screenHeight, settings::fps, settings::title};

    while (!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}