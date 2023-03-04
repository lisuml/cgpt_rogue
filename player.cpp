#include "player.h"

Player::Player(int x, int y, int max_x, int max_y) {
    this->x = x;
    this->y = y;
    this->max_x = max_x;
    this->max_y = max_y;
}

void Player::move(int dx, int dy) {
    int new_x = x + dx;
    int new_y = y + dy;
    if (new_x >= 0 && new_x < max_x) {
        x = new_x;
    }
    if (new_y >= 0 && new_y < max_y) {
        y = new_y;
    }
}

int Player::get_x() {
    return x;
}

int Player::get_y() {
    return y;
}

