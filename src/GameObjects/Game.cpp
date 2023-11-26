//
// Created by lehen on 12/11/2023.
//

#include "../../headers/GameObjects/Game.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

#include <cassert>
#include <algorithm>

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
    tickCounter = (tickCounter + 1) % fps;
    if (tickCounter == 1){
        // loop for displaying info once every {framerate} seconds
//        std::cout << numberOfPlayer << std::endl;

    }
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
    colorChoiceButton.Draw();
}

void Game::UpdateMenu() {
// UI logic (options)
    if(playButton.DetectClick()){
        PlayButtonClick();
    }

    colorChoice = colorChoiceButton.DetectClick();

    numberOfPlayer = numberChoice.DetectClick();
}

void Game::DrawGame() {
    board.Draw();

    players.GetCurrentTiles().GetCurrentTile().DrawFollow(boardSize);
}

void Game::UpdateGame() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        // position = {boardX, boardY}
        Vec2<int> position = (GameEngine::GetMousePosition() - board.GetBoardPos()) / (board.GetSize());
// on ne check pas si la souris est sur le board car certaine piece on besoin de cette fonctionnalié pour etre jouer
        //        if (((GameEngine::GetMousePosition() - board.GetBoardPos()) > Vec2<int>{0,0}) && ((GameEngine::GetMousePosition() - board.GetBoardPos()) / (board.GetSize()) <= board.GetSize())){
            if(board.PlaceTile(players.GetCurrentTiles().GetCurrentTile(), position)){
                // change tile
                players.GetCurrentTiles().NextTile();
                players.NextPlayer();
//            }
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        players.GetCurrentTiles().GetCurrentTile().RotateClockwise();
    }

    if (IsKeyPressed(KEY_F)){
        players.GetCurrentTiles().GetCurrentTile().Flip();
    }

    // TODO: detecter bonus recuperé
    // TODO: detecter bonus utilisé

    // TODO: detecter click pour flip


    // TODO: fin de partie
}

void Game::PlayButtonClick() {
    areChoicesMade = true;
    boardSize = {20,20};
    board.SetBoardSize(boardSize);

    //Inits
    players.Init(numberOfPlayer, colorChoice, allColors);
    board.InitBoard(players);

    // all button turn off
    playButton.TurnOff();
}
