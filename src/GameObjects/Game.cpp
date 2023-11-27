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
    InitWindow(settings::screenWidth, settings::screenHeight, _title.c_str());
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
    ClearBackground(GRAY);

    if(areChoicesMade){
        DrawGame();
    }else if(starting){
        DrawingStarting();
    } else {
        DrawMenu();
        
    }

}

void Game::Update() {
    if(areChoicesMade){
        UpdateGame();
    } else if(starting){
        UpdateStarting();
    }else {
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

    numberOfPlayer = numberChoice.DetectClick();
}

void Game::DrawGame() {
    board.Draw();

    tiles.GetCurrentTile().DrawFollow(boardSize);

    // drawing player names
    std::string playerText = players.GetCurrentPlayer().GetPlayerName() + " is playing...";
    DrawText(playerText.c_str(),50, 25, 50, players.GetCurrentPlayerColor());
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
            if (board.PlaceTile(tiles.GetCurrentTile(), position)) {
                // change tile
                tiles.NextTile();
                players.NextPlayer();
                tiles.SetTilesColor(players.GetCurrentPlayerColor());
                //            }
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            tiles.GetCurrentTile().RotateClockwise();
        }

        if (IsKeyPressed(KEY_F)) {
            tiles.GetCurrentTile().Flip();
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
        std::vector<std::string> namesToUse;
        for (int i = 0; i < numberOfPlayer; ++i) {
            colorToUse.push_back(playersColor[i]);
            namesToUse.push_back((std::string)playersNames[i]);
        }

        players.Init(numberOfPlayer, colorToUse, namesToUse);
        board.InitBoard(players);

        // init tiles and starting cells
        tiles.SetTilesColor(players.GetCurrentPlayerColor());
        startingCells.resize(numberOfPlayer);

        for (int i = 0; i < numberOfPlayer; ++i) {
            startingCells[i].SetColor(colorToUse[i]);
        }
        
        starting = true;
    }


}

void Game::UpdateStarting() {
    std::cout << "lol "<< std::endl;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vec2<int> position = (GameEngine::GetMousePosition() - board.GetBoardPos()) / (board.GetSize());
        std::cout << "pos " << position.GetX() << ", " << position.GetY() << std::endl;

        if (board.CanPlaceCell(position, players.GetCurrentPlayerColor())){
            board.SetCell(position, players.GetCurrentPlayerColor());
            placedStartingCell++;
            players.NextPlayer();
        }
    }

    if (placedStartingCell == numberOfPlayer){
        starting = false;
        areChoicesMade = true;
    }
}

void Game::DrawingStarting() {
    std::string playerText = players.GetCurrentPlayer().GetPlayerName() + " is playing...";
    DrawText(playerText.c_str(),50, 25, 50, players.GetCurrentPlayerColor());
    board.Draw();

    startingCells[players.GetCurrentPlayerIndex()].DrawCellFollow(board.GetSize(), players.GetCurrentPlayerColor());

}
