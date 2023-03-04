#include <ncurses.h>
#include "map.h"
#include "player.h"

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();

    // Create player and map
    Player player(1, 1);
    Map map(12, 12);

    // Game loop
    while (true) {
        // Print map and wait for user input
        map.print(&player);
        int ch = getch();

        // Handle user input
        int dx = 0, dy = 0;
        switch (ch) {
            case 'h': dy = -1; break;
            case 'j': dx = 1; break;
            case 'k': dx = -1; break;
            case 'l': dy = 1; break;
            case 'q': endwin(); return 0;
        }

        // Move player
        player.move(dx, dy);

        // Check if player has collided with a wall
        if (map.get_tile(player.get_x(), player.get_y()) == '#') {
            // Move player back to previous position
            player.move(-dx, -dy);
        }
    }
}

