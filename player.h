#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int x, y;
        int max_x, max_y;
    public:
        Player(int x, int y, int max_x, int max_y);
        void move(int dx, int dy);
        int get_x();
        int get_y();
};

#endif

