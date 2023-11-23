//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include <cassert>

#include "../headers/Settings.h"
#include "../headers/GameStates.h"

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

void Game::Tick() {
    // game logic is wrap in begin and end drawing function of raylib to avoid forgetting about it in the game logic or the display method

    BeginDrawing();
    Update();
    Draw();
    EndDrawing();

}

void Game::Draw() {
    // Draw basic logic ? maybe
    ClearBackground(WHITE);


    if(areChoicesMade){
        // les choix sont fait
        board.Draw();
    }else{
        // afficher bouton et slider pour que l'utilisateur choisisse ses parametres
        playButton.Draw();

    }

}

void Game::Update() {
    // Game logic
    // UI logic (options)
    if(playButton.DetectClick()){
        areChoicesMade = true;
        board.SetBoardSize({20,20});
    }

    // UI logic (game)
}
