#include <stdio.h>
#include <sys/ioctl.h>
#include <curses.h>
#include "../includes/display.h"
#include "../includes/matrix.h"

WINDOW * terminal = NULL;
int width;
int height;

int intensity[BRIGHTEST + 1] = {1,2,2,2,3,3,3,4,4,4,4,4,5,3,6};

void define_colours() {
    // set up 8 colours
    for (int i = 0; i < 8; i++) {
        init_pair(i + 1, i, COLOR_BLACK);
    }
    // set up shades of green
    for (int i = 0; i < 8; i++) {
        init_color(i, 0, i*200, 0);
    }
}

bool initialise_display() {
	/* struct winsize size; */
	/* ioctl( 0, TIOCGWINSZ, (char *) &size ); */
    /* width = size.ws_row; */
    /* height = size.ws_col; */
    WINDOW * terminal = initscr();
    if (terminal == NULL) return false;

    start_color();
    if(!has_colors() || !can_change_color()) {
        return false;
    }
    define_colours();

    return true;
}

void destroy_display() {

    delwin(terminal);
    endwin();
    refresh();

}

void display_matrix() {
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            int brightness = matrix[x][y].brightness;
            color_set(intensity[brightness], NULL);
            mvaddch(y, x, matrix[x][y].symbol);
        }
    }
    refresh();
}

