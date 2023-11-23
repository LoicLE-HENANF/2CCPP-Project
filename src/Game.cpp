//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include <cassert>

#include "../headers/Settings.h"
#include "../headers/GameStates.h"
#include "../headers/Tile.h"

using namespace settings;

// Game class implementation
Game::Game(int width, int height, int _fps, const std::string &_title)
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(_fps);
    InitWindow(width, height, _title.c_str());

    areChoicesMade = false;
}

Game::~Game() noexcept {
    assert(GetWindowHandle()); //If assertion triggers : windows is already closed
    CloseWindow();
}

bool Game::GameShouldClose() {
    return WindowShouldClose();
}

///
/// Function that will run every tick (1 tick = 1/{framerate} seconds)
///
void Game::Tick() {
///
/// desc:Game logic is wrap in begin and end drawing function of raylib to avoid forgetting about it in the game logic or the display methods
///
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();

}

void Game::Draw() {
    // Draw basic logic ? maybe
    ClearBackground(GRAY);

    if(areChoicesMade){
        // les choix sont fait
        DrawGame();
    }else{
        DrawMenu();
    }

}

void Game::Update() {
    tickCounter = (tickCounter + 1) % fps;
    if (tickCounter == 1){
        // loop for displaying info once every {framerate} seconds
        std::cout << numberOfPlayer << std::endl;
        std::cout << tickCounter << std::endl;

    }

    if(areChoicesMade){
        UpdateGame();
    } else {
        UpdateMenu();
    }
}

void Game::DrawMenu() {
    // afficher bouton et slider pour que l'utilisateur choisisse ses parametres
    playButton.Draw();
    numberChoice.Draw();
}

void Game::UpdateMenu() {
// UI logic (options)
    if(playButton.DetectClick()){
        areChoicesMade = true;
        boardSize = {20,20};
        board.SetBoardSize(boardSize);

        players.Init(numberOfPlayer, colorChoice);
        board.InitBoard(players);


        // all button turn off
        playButton.TurnOff();
    }

    numberOfPlayer = numberChoice.DetectClick();
}

void Game::DrawGame() {
    board.Draw();
    if (GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(),
                                           boardPosition,
                                           boardSize * (cellSize))  )
    {
        tileQueue.GetCurrentTile().DrawFollow(boardSize);
    }
}

void Game::UpdateGame() {

}
