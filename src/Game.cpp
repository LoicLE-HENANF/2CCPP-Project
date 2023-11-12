//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include "assert.h"

Game::Game(int width, int height, const std::string& title) {
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    InitWindow(width, height, title.c_str());


}

Game::~Game() noexcept {
    assert(GetWindowHandle()); //If assertion triggers : windows is already closed
    CloseWindow();
}

bool Game::GameShouldClose() const {
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
    ClearBackground(RAYWHITE);
}

void Game::Update() {

}
