#include <ncurses.h>
#include "map.h"
#include "player.h"

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();

    // Create player and map
    Player* player = new Player(0, 0);
    Map* map = new Map(10, 10);

    // Game loop
    bool quit = false;
    while (!quit) {
        // Print map and wait for user input
        map->print(player);
        int ch = getch();

        // Handle user input
        switch (ch) {
            case 'h':
                player->move(0, -1);
                break;
            case 'j':
                player->move(1, 0);
                break;
            case 'k':
                player->move(-1, 0);
                break;
            case 'l':
                player->move(0, 1);
                break;
            case 'q':
                quit = true;
                break;
        }
    }

    // Clean up and exit
    delete player;
    delete map;
    endwin();
    return 0;
}

