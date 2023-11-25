//
// Created by lehen on 23/11/2023.
//

#include "../../headers/GameObjects/Players.h"

void Players::Init(int numberOfPlayers, Color color, std::vector<Color> allColors) {
    players.clear();
    players.resize(numberOfPlayers);
    currentPlayerIndex = 0;
    players[currentPlayerIndex].SetColor(color);



    int colorCounter = 0;
    int colorToRemove = 0;
    for (Color iColor : allColors) {
        if (color.r == iColor.r && color.a == iColor.a && color.g == iColor.g && color.b == iColor.b){
            colorToRemove = colorCounter;
            allColors[colorToRemove] = WHITE;
        }
        colorCounter++;
    }

    int skip = 0;
    for (int playerIndex = 1; playerIndex < players.size(); ++playerIndex) {
        if (allColors[playerIndex].r == 255 && allColors[playerIndex].g == 255 && allColors[playerIndex].b == 255 &&allColors[playerIndex].a == 255){
            skip = 1;
        }
        players[playerIndex].SetColor(allColors[playerIndex + skip]);
    }


}

int Players::GetSize() const{
    return players.size();
}

Player Players::GetPlayer(int i) const{
    return players[i];
}

int Players::GetCurrentPlayerIndex() const {
    return currentPlayerIndex;
}
