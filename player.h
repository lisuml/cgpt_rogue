#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int x, y;
    public:
        Player(int x, int y);
        void move(int dx, int dy);
        int get_x();
        int get_y();
};

#endif

