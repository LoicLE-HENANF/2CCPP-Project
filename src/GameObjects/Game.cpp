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
Game::Game()
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(settings::fps);
    InitWindow(settings::screenWidth, settings::screenHeight, settings::title.c_str());
//    ToggleFullscreen();
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

    if(playing){
        DrawGame();
    }else if(starting){
        DrawingStarting();
    } else
        if(gameOver){
// TODO: fin de partie
    } else {
        DrawMenu();
    }

}

void Game::Update() {
    if(playing){
        UpdateGame();
    } else if(starting){
        UpdateStarting();
    }else if(gameOver){
// TODO: fin de partie
    } else {
        UpdateMenu();
    }
}

// menu phase functions (when choosing game options)
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

// starting phase functions (placing starting tiles)
void Game::UpdateStarting() {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        Vec2<int> position = (GameEngine::GetMousePosition() - board.GetBoardPos()) / settings::cellSize;

        if (board.CanPlaceCell(position)){
            board.SetCell(position, players.GetCurrentPlayerColor());
            placedStartingCell++;
            players.NextPlayer();
        }
    }

    if (placedStartingCell == numberOfPlayer){
        BeginGame();
    }
}

void Game::DrawingStarting() {
    std::string playerText = players.GetCurrentPlayer().GetPlayerName() + " is playing...";
    DrawText(playerText.c_str(),50, 25, 50, players.GetCurrentPlayerColor());
    board.Draw();

    startingCells[players.GetCurrentPlayerIndex()].DrawCellFollow(players.GetCurrentPlayerColor());

}


// playing phase functions (when placing tiles)
void Game::DrawGame() {
    board.Draw();

    if (!CheckPlayerHasBonuses()){
        tiles.GetCurrentTile().DrawFollow();
    }
    else{
        // draw cell
        // draw text : player has to placed stone or robbery
    }


    tiles.DrawNextTiles({650,100});

    // drawing player names

    std::string playerText = players.GetCurrentPlayerName() + " is playing...";
    DrawText(playerText.c_str(),50, 25, 50, players.GetCurrentPlayerColor());

    // drawing tiles exchanges coupon
    // TODO : DrawingTEC
    //

}



void Game::UpdateGame() {
    // Click souris gauche
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        // position = {boardX, boardY} dependant de si la souris est sur le board ou non
        Vec2<int> mousePos = GameEngine::GetMousePosition();
        Vec2<int> position = (mousePos - board.GetBoardPos()) / (settings::cellSize);

        // check if player got bonus
        if (CheckPlayerHasBonuses()) {
            // use bonus (stone)
            if (bonuses.at(1) != 0) {
                // placement des stones
                if (board.SetCellToStone(position)) {
                    bonuses.at(1)--;
                }
            }
            // use bonus (rob)
            else if (bonuses.at(2) != 0) {
                if (board.Robbery(position, players.GetCurrentPlayerColor())) {
                    bonuses.at(2)--;
                }
            }
            // if TEC, add one to the value in currentplayer
            else if (bonuses.at(3) != 0) {
                while(bonuses.at(3) != 0){
                    players.AddTECToCurrentPlayer();
                    bonuses.at(3)--;
                }
            }
        }

        if (!CheckPlayerHasBonuses()) {
            // si la souris est au dessus du board
            if (mousePos.GetY() < boardPosition.GetY()) {
                position += Vec2<int>{0, -1};
            }
            // si la souris est en dessous du board
            if (mousePos.GetY() > boardPosition.GetY() + (boardSize.GetY() * (cellSize + padding))) {
                position += Vec2<int>{0, 1};
            }
            // si la souris est a gauche du board
            if (mousePos.GetX() < boardPosition.GetX()) {
                position += Vec2<int>{-1, 0};
            }
            // si la souris est a droite du board
            if (mousePos.GetX() > boardPosition.GetX() + (boardSize.GetX() * (cellSize + padding))) {
                position += Vec2<int>{1, 0};
            }

            if (board.PlaceTile(tiles.GetCurrentTile(), position)) {
                bonuses = board.CheckForBonuses(players.GetCurrentPlayerColor());

                // player has played = true
                playerHasPlayed = true;
                for (const auto &x: bonuses) {
                    std::cout << x.first << ": " << x.second << std::endl;
                }
            }
        }

        if (CheckPlayerHasBonuses()) {
            // if TEC, add one to the value in currentplayer
            if (bonuses.at(3) != 0) {
                while(bonuses.at(3) != 0){
                    players.AddTECToCurrentPlayer();
                    bonuses.at(3)--;
                }
            }
        }

        // passage du joueur
        NextPlayer();
    }


    // Click souris droite
    if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        tiles.GetCurrentTile().RotateClockwise();
    }

    // Click F key
    if (IsKeyPressed(KEY_F)) {
        tiles.GetCurrentTile().Flip();
    }

    // TODO: detecter bonus TEC utilisé
    // si tel bonus activé, lancer une fonction associé


    if (players.GetTurn() >= 10) {
        EndGame();
    }
}



// end phase functions (when game is over and players get their scores)

void Game::PlayButtonClick() {
    bool canPlay = true;
    for (int i = 0; i < numberOfPlayer; ++i) {
        if (strlen(playersNames[i]) == 0 ){
            canPlay = false;
        }
    }

    if (canPlay){

        // board size from player number
        if(numberOfPlayer < 5){
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

void Game::EndGame() {
    // re init parametres important à 0
    placedStartingCell = 0;

    // game logic
    playing = false;
    gameOver = true;
}

void Game::BeginGame() {
    starting = false;
    playing = true;
}

// si pas de bonus en cours et que le joueur a placer sa tile
void Game::NextPlayer() {
    if (!CheckPlayerHasBonuses() && playerHasPlayed){
        tiles.NextTile();
        players.NextPlayer();
        tiles.SetTilesColor(players.GetCurrentPlayerColor());
        playerHasPlayed = false;
    }
}

bool Game::CheckPlayerHasBonuses() {
    return bonuses.at(1) + bonuses.at(2) + bonuses.at(3);
}


