#include <ncurses.h>
#include "map.h"
#include "player.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    tiles = new char*[width];
    for (int i = 0; i < width; i++) {
        tiles[i] = new char[height];
        for (int j = 0; j < height; j++) {
            tiles[i][j] = '.';
        }
    }
}

Map::~Map() {
    for (int i = 0; i < width; i++) {
        delete[] tiles[i];
    }
    delete[] tiles;
}

void Map::print(Player* player) {
    clear();
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == player->get_x() && j == player->get_y()) {
                mvprintw(i, j, "@");
            } else {
                mvprintw(i, j, "%c", tiles[i][j]);
            }
        }
    }
    refresh();
}

char Map::get_tile(int x, int y) {
    return tiles[x][y];
}

