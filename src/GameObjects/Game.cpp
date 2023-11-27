//
// Created by lehen on 12/11/2023.
//

#include "../../headers/GameObjects/Game.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

#include <cassert>
#include <algorithm>
#include "cstring"

using namespace settings;

// Game class implementation
Game::Game(int width, int height, int _fps, const std::string &_title)
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(_fps);
    InitWindow(0, 0, _title.c_str());
//    ToggleFullscreen();

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
    playersChoice.Draw();
}

void Game::UpdateMenu() {
// UI logic (options)
    if(playButton.DetectClick()){
        PlayButtonClick();
    }

    playersChoice.SetNumberOfPlayer(numberOfPlayer);
    playersColor = new Color[numberOfPlayer];
    playersNames = new const char*[numberOfPlayer];
    playersChoice.DetectClick(playersColor, playersNames);
    colorChoice = playersColor[0];

    numberOfPlayer = numberChoice.DetectClick();
}

void Game::DrawGame() {
    board.Draw();

    players.GetCurrentTiles().GetCurrentTile().DrawFollow(boardSize);

    // drawing player names
    std::string playerText = players.GetCurrentPlayer().GetPlayerName() + " is playing...";
    DrawText(playerText.c_str(),0, 0, 20, BLACK);

}

void Game::UpdateGame() {
    // if player is ai
    if (players.GetCurrentPlayer().GetIsAI()) {

        // if player is distant (multiplayer)
    } else if(players.GetCurrentPlayer().GetIsDistant()){

        // if player is neither distant nor ai
    } else if(!players.GetCurrentPlayer().GetIsDistant() && !players.GetCurrentPlayer().GetIsAI()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            // position = {boardX, boardY}
            Vec2<int> position = (GameEngine::GetMousePosition() - board.GetBoardPos()) / (board.GetSize());
            // on ne check pas si la souris est sur le board car certaine piece on besoin de cette fonctionnalié pour etre jouer
            //        if (((GameEngine::GetMousePosition() - board.GetBoardPos()) > Vec2<int>{0,0}) && ((GameEngine::GetMousePosition() - board.GetBoardPos()) / (board.GetSize()) <= board.GetSize())){
            if (board.PlaceTile(players.GetCurrentTiles().GetCurrentTile(), position)) {
                // change tile
                players.GetCurrentTiles().NextTile();
                players.NextPlayer();
                //            }
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            players.GetCurrentTiles().GetCurrentTile().RotateClockwise();
        }

        if (IsKeyPressed(KEY_F)) {
            players.GetCurrentTiles().GetCurrentTile().Flip();
        }

        // TODO: detecter bonus recuperé
        // TODO: detecter bonus utilisé

        // TODO: detecter click pour flip


        // TODO: fin de partie

        // multiplayer send data
        if (isServer){

        }else if(isClient){

        }
    }
}

void Game::PlayButtonClick() {
    bool canPlay = true;
    for (int i = 0; i < numberOfPlayer; ++i) {
        if (strlen(playersNames[i]) == 0 ){
            canPlay = false;
        }
    }

    if (canPlay){
        areChoicesMade = true;

        // board size from player number
        if(players.GetSize() < 5){
            boardSize = {20,20};
        }else{
            boardSize = {30,30};
        }

        board.SetBoardSize(boardSize);

        //Inits
        // changing types of color list and names list to std::vector<Color> and std::vector<std::string>
        std::vector<Color> colorToUse;
        for (int i = 0; i < numberOfPlayer; ++i) {
            colorToUse.push_back(playersColor[i]);
        }
        std::vector<std::string> namesToUse;
        for (int i = 0; i < numberOfPlayer; ++i) {
            namesToUse.push_back((std::string)playersNames[i]);
        }

        players.Init(numberOfPlayer, colorToUse, namesToUse);
        board.InitBoard(players);

        // all button turn off
        playButton.TurnOff();
    }


}
