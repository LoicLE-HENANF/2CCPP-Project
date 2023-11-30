//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H


#include <string>
#include "Board.h"
#include "Tiles.h"
#include "../UI/Button.h"
#include "../UI/NumberChoice.h"
#include "../UI/PlayersChoice.h"

/**
 * @brief Represents the game and its logic.
 *
 * The Game class manages the overall game state, including drawing, updating, multiplayer logic, and UI elements.
 */
class Game {

public:

    /**
     * @brief Default constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    ~Game() noexcept; // noexcept to avoid stack unwinding

    /**
     * @brief Deleted copy constructor to prevent copying Game objects.
     */
    Game(const Game& other) = delete; //copy constructor deleted

    /**
     * @brief Deleted copy assignment operator to prevent copying Game objects.
     */
    Game& operator=(const Game& other) = delete; //copy assignment deleted

    /**
    * @brief Checks if the game should close.
    *
    * @return True if the game should close, false otherwise.
    */
    [[nodiscard]] static bool GameShouldClose() ;

    /**
     * @brief Performs a game tick, including drawing and updating.
     */
    void Tick();



private:
    // Draw and Update
    /**
    * @brief Draws the game.
    */
    void Draw();

    /**
     * @brief Updates the game logic.
     */
    void Update();

    /**
     * @brief Draws the main menu.
     */
    void DrawMenu();

    /**
     * @brief Updates the main menu logic.
     */
    void UpdateMenu();

    /**
     * @brief Draws the game when in progress.
     */
    void DrawGame();

    /**
     * @brief Updates the game logic when in progress.
     */
    void UpdateGame();

    // Game variables
    bool playing = false;
    bool starting = false;
    bool gameOver = false;

    Board board;
    Vec2<int> boardSize = {20,20};
    int placedStartingCell = 0;

    int tickCounter = 0;

    bool playerHasPlayed = false;
    bool playerIsUsingTEC = false;
    bool playerIsRemovingStone = false;

    Vec2<int> nextTilesPosition = {650,100};

    std::map<int, int> bonuses = {{settings::bonusStone, 0},
                                  {settings::bonusRobbery, 0},
                                  {settings::bonusTEC, 0}};

    // tiles
    Tiles tiles;
    std::vector<Cell> startingCells;



    //player info
    int numberOfPlayer = 2;
    Players players;
    Color* playersColor;
    const char** playersNames;

    // UI (options)

    Vec2<int> buttonSize = {70,30};

    Vec2<int> playButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) +200
    };
    Button playButton{
            playButtonPos,
            buttonSize,
            "Play",
            RED
    };

    Vec2<int> gameButtonSize = {200,30};
    Vec2<int> TECButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) + 300
    };
    Vec2<int> removeStoneButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) +400
    };

    Button TECButton{
            TECButtonPos,
            gameButtonSize,
            "Exchange Tile",
            RED
    };
    Button removeStoneButton{
            removeStoneButtonPos,
            gameButtonSize,
            "Remove Stone",
            RED
    };


    // End game variables
    Vec2<int> baseTextPosition = {20, 20};
    int endGameTextFontSize = 20;

    int highestScore = 0;
    std::string winningPlayer;
    std::string highestScoreText;



    void PlayButtonClick();

    Vec2<int> numberChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) - 100};

    NumberChoice numberChoice{numberChoicePos,
                              Vec2{100,100},
                              BLACK,
                              WHITE,
                              2,
                              9};

    Vec2<int> colorChoiceSize = {50,50};
    Vec2<int> nameChoiceSize = {300,50};

    Vec2<int> colorChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) + 50
    };


    PlayersChoice playersChoice{
        colorChoicePos,
        colorChoiceSize,
        nameChoiceSize,
        10
    };



    // UI (game)
    // TODO: next tiles
    // TODO: bouton pour utiliser bonus



    /**
     * @brief Updates the game logic during the starting phase.
     */
    void UpdateStarting();

    /**
     * @brief Draws elements during the starting phase.
     */
    void DrawingStarting();

    /**
     * @brief Ends the game.
     */
    void EndGame();

    /**
     * @brief Begins the game.
     */
    void BeginGame();

    void NextPlayer();

    bool CheckPlayerHasBonuses();

    void UpdateEndGame();

    void DrawEndGame();
};


#endif //INC_2CCPP_PROJECT_GAME_H
