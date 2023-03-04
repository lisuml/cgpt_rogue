#include <ncurses.h>
#include "map.h"
#include "player.h"

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();

    // Create player and map
    Player* player = new Player(1, 1);
    Map* map = new Map(12, 12);

    // Game loop
    bool quit = false;
    while (!quit) {
        // Print map and wait for user input
        map->print(player);
        int ch = getch();

        // Handle user input
        int dx = 0, dy = 0;
        switch (ch) {
            case 'h':
                dx = 0;
                dy = -1;
                break;
            case 'j':
                dx = 1;
                dy = 0;
                break;
            case 'k':
                dx = -1;
                dy = 0;
                break;
            case 'l':
                dx = 0;
                dy = 1;
                break;
            case 'q':
                quit = true;
                break;
        }

        // Move player
        player->move(dx, dy);

        // Check if player has collided with a wall
        if (map->get_tile(player->get_x(), player->get_y()) == '#') {
            // Move player back to previous position
            player->move(-dx, -dy);
        }
    }

    // Clean up and exit
    delete player;
    delete map;
    endwin();
    return 0;
}

