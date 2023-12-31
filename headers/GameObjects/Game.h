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
    ~Game() noexcept;

    /**
     * @brief Deleted copy constructor to prevent copying Game objects.
     */
    Game(const Game& other) = delete;

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
    int tickCounter = 0; // for testing
    bool playing = false;
    bool starting = false;
    bool gameOver = false;
    bool playerHasPlayed = false;
    bool playerIsUsingTEC = false;
    bool playerIsRemovingStone = false;
    bool playerIsSkippingTurn = false;

    Vec2<int> boardSize = {20,20};
    Board board;
    Tiles tiles;
    std::vector<Cell> startingCells;

    int placedStartingCell = 0;

    std::map<int, int> bonuses = {{settings::bonusStone, 0},
                                  {settings::bonusRobbery, 0},
                                  {settings::bonusTEC, 0}};

    //players info
    int numberOfPlayer = 2;
    Players players;
    Color* playersColor;
    const char** playersNames;

    // Sizes
    Vec2<int> buttonSize = {70,30};
    Vec2<int> colorChoiceSize = {50,50};
    Vec2<int> nameChoiceSize = {300,50};
    Vec2<int> gameButtonSize = {275,30};

    // Positions
    Vec2<int> nextTilesPosition = {settings::screenWidth - 150, settings::boardPosition.GetY()};
    Vec2<int> nextTilesTextPosition = nextTilesPosition - Vec2<int>{0, 25};
    Vec2<int> numberChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) - 100
    };
    Vec2<int> colorChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) + 50
    };
    Vec2<int> playButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) + 350
    };

    Vec2<int> TECTextPos = nextTilesPosition + Vec2<int>{-200,  600};
    Vec2<int> TECButtonPos = nextTilesPosition + Vec2<int>{-200,  650};
    Vec2<int> removeStoneButtonPos = nextTilesPosition + Vec2<int>{-200,  700};
    Vec2<int> skipButtonPos = nextTilesPosition + Vec2<int>{-200,  750};


    // UI elements
    NumberChoice numberChoice{numberChoicePos,
                              Vec2{100,100},
                              BLACK,
                              WHITE,
                              2,
                              9};

    PlayersChoice playersChoice{
            colorChoicePos,
            colorChoiceSize,
            nameChoiceSize,
            10
    };

    Button playButton{
            playButtonPos,
            buttonSize,
            "Play",
            RED
    };

    Button TECButton{
            TECButtonPos,
            gameButtonSize,
            "Exchange Tile (use 1TEC)",
            RED
    };
    Button removeStoneButton{
            removeStoneButtonPos,
            gameButtonSize,
            "Remove Stone (use 1TEC)",
            RED
    };

    Button skipButton{
            skipButtonPos,
            gameButtonSize,
            "Skip Turn",
            RED
    };


    // End game variables
    Vec2<int> baseTextPosition = {20, 20};
    int endGameTextFontSize = 30;

    int highestScore = 0;
    std::string winningPlayer;
    std::string highestScoreText;

    Vec2<int> restartButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            settings::screenHeight - 100
    };

    Button restartButton = {
        restartButtonPos,
        gameButtonSize,
        "Return to Main Menu",
        RED
    };


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

    /**
    * @brief Advances to the next player in the game.
    */
    void NextPlayer();

    /**
    * @brief Checks if the current player has any bonuses.
    *
    * @return True if the current player has bonuses, false otherwise.
    */
    bool CheckPlayerHasBonuses();

    /**
    * @brief Updates the game state at the end of the game.
    */
    void UpdateEndGame();

    /**
    * @brief Draws the end game screen.
    */
    void DrawEndGame();


    /**
     * @brief Skips the turn in the game.
    */
    void SkipTurn();

    /**
    * @brief Handles the button click event for the "Play" button.
     */
    void PlayButtonClick();

    /**
    * @brief Restarts the game.
    */
    void RestartGame();
};


#endif //INC_2CCPP_PROJECT_GAME_H
