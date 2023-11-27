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

class PlayersChoice { ;
public:
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
    ~PlayersChoice() = default;

    void Draw();

    bool CanClickColor(Vec2<int> offset);
    bool CanClickName(Vec2<int> offset);
    void  DetectClick(Color* colorsToReturn, const char** namesToReturn);

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
                             AllColor::DARKBLUE_};

    std::vector<std::string> playerNames;
    bool isTyping = false;
    int nameClicked;
    

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
            default:
                std::cout << "default color reached" << std::endl;
                return WHITE;
        }
    };

    void NextColor(int index){
        playerColors[index] = AllColor((int(playerColors[index]) + 1) % 11);
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
                playerColors[index] = AllColor((int(playerColors[index]) + 1) % 11);
            }
        }
    };
};


#endif //INC_2CCPP_PROJECT_PLAYERSCHOICE_H
