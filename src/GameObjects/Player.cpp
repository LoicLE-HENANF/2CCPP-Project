//
// Created by lehen on 12/11/2023.
//

#include "../../headers/GameObjects/Player.h"

Color Player::GetColor() const {
    return color;
}

void Player::SetColor(Color _color) {
    color = _color;
}

Tiles& Player::GetTiles() {
    return tiles;
}

std::string Player::GetPlayerName() {
    return name;
}

void Player::SetName(std::string _name) {
    name = _name;
}
