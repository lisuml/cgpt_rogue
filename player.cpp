#include "player.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Player::get_x() {
    return x;
}

int Player::get_y() {
    return y;
}

