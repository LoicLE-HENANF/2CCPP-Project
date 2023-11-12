//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H

#include <string>

class Game {
public:
    Game(int width, int height, const std::string& title);
    ~Game() noexcept; // noexcept to avoid stack unwinding
    Game(const Game& other) = delete; //copy constructor deleted
    Game& operator=(const Game& other) = delete; //copy assignment deleted

    bool GameShouldClose() const;

    void Tick();



private:
    void Draw();
    void Update();

};


#endif //INC_2CCPP_PROJECT_GAME_H
