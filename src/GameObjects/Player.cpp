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
