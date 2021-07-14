#include <stdio.h>
#include <sys/ioctl.h>
#include <curses.h>
#include "../includes/display.h"
#include "../includes/matrix.h"

WINDOW * terminal = NULL;
int width;
int height;

int intensities[MAX_INTENSITY + 1] = {1,2,2,3,3,3,4,4,4,4,4,5,3,6};

void define_colours() {}

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
            int intensity = matrix[x][y].brightness;
            color_set(intensities[intensity], NULL);
            mvaddch(y, x, matrix[x][y].symbol);
        }
    }
    refresh();
}

