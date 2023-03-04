#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int x;
        int y;
    public:
        Player(int x, int y);
        void move(int dx, int dy);
        int get_x() const;
        int get_y() const;
};

#endif

