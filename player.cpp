#include "player.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Player::get_x() const {
    return x;
}

int Player::get_y() const {
    return y;
}

