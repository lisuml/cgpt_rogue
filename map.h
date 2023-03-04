#ifndef MAP_H
#define MAP_H

#include "player.h"

class Map {
    private:
        int width, height;
        char** tiles;
    public:
        Map(int width, int height);
        ~Map();
        void print(Player* player);
        char get_tile(int x, int y);
        void set_tile(int x, int y, char tile);
};

#endif

