#include <ncurses.h>
#include "map.h"
#include "player.h"

Map::Map(int width, int height) : width(width), height(height) {
    tiles = new char*[width];
    for (int i = 0; i < width; i++) {
        tiles[i] = new char[height];
        for (int j = 0; j < height; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                tiles[i][j] = '#';
            } else {
                tiles[i][j] = '.';
            }
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
            const char c = (i == player->get_x() && j == player->get_y()) ? '@' : tiles[i][j];
            mvprintw(i, j, "%c", c);
        }
    }
    refresh();
}

char Map::get_tile(int x, int y) {
    return tiles[x][y];
}

void Map::set_tile(int x, int y, char tile) {
    tiles[x][y] = tile;
}

