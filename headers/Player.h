//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYER_H
#define INC_2CCPP_PROJECT_PLAYER_H

#include "raylib.h"
#include <string>

class Player {
private:
    std::string name;
    Color color;
public:
    Player();
    ~Player();
    Player(const Player& other) = delete; //copy constructor deleted
    Player& operator=(const Player& other) = delete; //copy assignment deleted

};


#endif //INC_2CCPP_PROJECT_PLAYER_H
