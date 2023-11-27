//
// Created by lehen on 25/11/2023.
//

#include "../../headers/UI/PlayersChoice.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

void PlayersChoice::Draw() {
    // pour tout les joueurs, on affiche un rectangle pour le choix de couleur, et son nom
    GameEngine::DrawRectangle(position, colorSize, GetColor(playerColors[0]));

    for (int i = 1; i < numberOfPlayer; ++i) {
        Vec2<int> offset = {0, colorSize.GetX() * i + padding * i};
        GameEngine::DrawRectangle(position  + offset, colorSize, GetColor(playerColors[i]));
    }

    // draw text box + text
    Vec2<int> offset = {colorSize.GetX() + padding, 0};
    GameEngine::DrawRectangle(position + offset, nameSize, RAYWHITE);
    DrawText(playerNames[0].c_str(), (position + offset).GetX(), (position + offset).GetY(), 48, BLACK);

    for (int i = 1; i < numberOfPlayer; ++i) {
        offset = {colorSize.GetX() + padding, colorSize.GetY() * i + padding * i};
        GameEngine::DrawRectangle(position  + offset, nameSize, RAYWHITE);
        DrawText(playerNames[i].c_str(), (position + offset).GetX(), (position + offset).GetY(), 48, BLACK);

    }
}

bool PlayersChoice::CanClickColor(Vec2<int> offset) {
    if (GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(), position + offset, colorSize)){
        return true;
    }
    return false;
}

bool PlayersChoice::CanClickName(Vec2<int> offset) {
    if (GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(), position + offset, nameSize)){
        return true;
    }
    return false;
}


void PlayersChoice::DetectClick(Color* colorsToReturn, const char** namesToReturn) {
    // colors handler
    // si click changer la couleur à la prochaine
    if (CanClickColor({0,0}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        NextColor(0);
    }

    // meme chose pour les autres (offset != {0,0}
    for (int i = 1; i < numberOfPlayer; ++i) {
        Vec2<int> offset = {0, colorSize.GetX() * i + padding * i};
        if (CanClickColor(offset) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            NextColor(i);
        }
    }

    // names handler
    if (CanClickName({colorSize.GetX() + padding,0}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        isTyping = true;
        nameClicked = 0;
    }
    for (int i = 1; i < numberOfPlayer; ++i) {
        Vec2<int> offset = {colorSize.GetX() + padding, colorSize.GetY() * i + padding * i};
        if (CanClickName(offset) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            isTyping = true;
            nameClicked = i;
        }
    }

    // typing handler
    if (isTyping){
        int key = GetCharPressed();

        while (key > 0){
            if ((key >= 32) && (key <= 125)){
                playerNames[nameClicked] += (char)key;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)){
            playerNames[nameClicked].pop_back();
        }
        if (IsKeyPressed(KEY_ENTER)){
            isTyping = false;
        }
    }

    // return values input in output variables (convert from c++ types to c array)
    for (int i = 0; i < numberOfPlayer; ++i) {
        colorsToReturn[i] = (GetColor(playerColors[i]));
        namesToReturn[i] = (playerNames[i]).c_str();
    }

}


