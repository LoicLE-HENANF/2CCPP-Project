//
// Created by lehen on 25/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYERSCHOICE_H
#define INC_2CCPP_PROJECT_PLAYERSCHOICE_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "../Utilities/Vec2.h"
#include "raylib.h"
#include"../Settings.h"

/**
 * @brief Represents a player choice interface in the game.
 *
 * The PlayersChoice class manages information about a player choice interface, including its position, size, padding,
 * color choices, and name inputs.
 */
class PlayersChoice { ;
public:

    /**
     * @brief Constructor for the PlayersChoice class.
     *
     * @param position The position of the player choice interface.
     * @param colorSize The size of the color choices.
     * @param nameSize The size of the name inputs.
     * @param padding The padding between different elements.
     */
    PlayersChoice(Vec2<int> position,
                  Vec2<int> colorSize,
                  Vec2<int> nameSize,
                  int padding)
            :
            position(position),
            colorSize(colorSize),
            nameSize(nameSize),
            padding(padding)
    {
        playerNames.resize(numberOfPlayer);
    }

    /**
     * @brief Destructor for the PlayersChoice class.
     */
    ~PlayersChoice() = default;

    /**
     * @brief Draws the player choice interface on the screen.
     */
    void Draw();

    /**
     * @brief Checks if a color choice can be clicked.
     *
     * @param offset The offset from the player choice interface position.
     * @return True if the color choice can be clicked, false otherwise.
     */
    bool CanClickColor(Vec2<int> offset);

    /**
     * @brief Checks if a name input can be clicked.
     *
     * @param offset The offset from the player choice interface position.
     * @return True if the name input can be clicked, false otherwise.
     */
    bool CanClickName(Vec2<int> offset);

    /**
     * @brief Detects a click on the player choice interface and returns selected colors and names.
     *
     * @param colorsToReturn Pointer to an array to store selected colors.
     * @param namesToReturn Pointer to an array to store entered names.
     */
    void  DetectClick(Color* colorsToReturn, const char** namesToReturn);

    /**
     * @brief Sets the number of players and resizes the playerNames vector accordingly.
     *
     * @param nb The number of players.
     */
    void SetNumberOfPlayer(int nb){
        numberOfPlayer = nb;
        playerNames.resize(numberOfPlayer);
    }

private:
    Vec2<int> position;
    Vec2<int> colorSize;
    Vec2<int> nameSize;

    int padding;

    enum class AllColor {
        RED_,
        BLUE_,
        GREEN_,
        PURPLE_,
        YELLOW_,
        ORANGE_,
        PINK_,
        SKYBLUE_,
        DARKBLUE_,
        VIOLET_,
        BEIGE_,
        c1_,
    };
    
    int numberOfPlayer = 2;

    std::vector<AllColor> playerColors = {AllColor::RED_,
                             AllColor::BLUE_,
                             AllColor::GREEN_,
                             AllColor::PURPLE_,
                             AllColor::YELLOW_,
                             AllColor::ORANGE_,
                             AllColor::PINK_,
                             AllColor::SKYBLUE_,
                             AllColor::DARKBLUE_,
                             AllColor::BEIGE_,
                             AllColor::VIOLET_,
                             AllColor::c1_};

    std::vector<std::string> playerNames;
    bool isTyping = false;
    int nameClicked;

    /**
     * @brief Gets the Color associated with the given AllColor enumeration value.
     *
     * @param color The AllColor value.
     * @return The corresponding Color.
     */
    Color GetColor(AllColor color){
        switch (color) {

            case AllColor::RED_:
                return RED;
            case AllColor::BLUE_:
                return BLUE;
            case AllColor::GREEN_:
                return GREEN;
            case AllColor::PURPLE_:
                return PURPLE;
            case AllColor::YELLOW_:
                return YELLOW;
            case AllColor::ORANGE_:
                return ORANGE;
            case AllColor::PINK_:
                return PINK;
            case AllColor::SKYBLUE_:
                return SKYBLUE;
            case AllColor::DARKBLUE_:
                return DARKBLUE;
            case AllColor::VIOLET_:
                return VIOLET;
            case AllColor::BEIGE_:
                return BEIGE;
            case AllColor::c1_:
                return settings::c1;
            default:
                std::cout << "default color reached" << std::endl;
                return WHITE;

        }
    };

    /**
     * @brief Moves to the next color in the sequence for a specific player.
     *
     * @param index The index of the player.
     */
    void NextColor(int index){
        playerColors[index] = AllColor((int(playerColors[index]) + 1) % 12);
        bool same = true;
        // while same color already in use, search for an other color
        while(same){
            same = false;
            for (int i = 0; i < numberOfPlayer; ++i) {
                if (index != i){
                    if (playerColors[i] == playerColors[index]){
                        same = true;
                    }
                }
            }
            if (same){
                playerColors[index] = AllColor((int(playerColors[index]) + 1) % 12);
            }
        }
    };
};


#endif //INC_2CCPP_PROJECT_PLAYERSCHOICE_H
