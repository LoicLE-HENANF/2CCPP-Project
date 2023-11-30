//
// Created by lehen on 12/11/2023.
//

#include <utility>
#include <sstream>

#include "../../headers/GameObjects/Player.h"

Color Player::GetColor() const {
    return color;
}

void Player::SetColor(Color _color) {
    color = _color;
}

std::string Player::GetName() {
    return name;
}

void Player::SetName(std::string _name) {
    name = std::move(_name);
}

void Player::AddTEC() {
    numberOfTEC += 1;
}

bool Player::GetNumberOfTEC() {
    return numberOfTEC;
}

void Player::RemoveTEC() {
    numberOfTEC -= 1;
}

void Player::SetScore(int playerScore) {
    score = playerScore;
}

std::string Player::GetScore() const {
    std::stringstream ss;
    ss << score;
    return ss.str();
}
