//
// Created by lehen on 12/11/2023.
//

#include <utility>

#include "../../headers/GameObjects/Player.h"

Color Player::GetColor() const {
    return color;
}

void Player::SetColor(Color _color) {
    color = _color;
}

std::string Player::GetPlayerName() {
    return name;
}

void Player::SetName(std::string _name) {
    name = std::move(_name);
}
