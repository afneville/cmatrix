#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdbool.h>

#include "../includes/display.h"
#include "../includes/matrix.h"

#define ITERATIONS 300
#define DELAY 50000L

int main( int argc, char **argv ){

    if (!initialise_display()) {
        return EXIT_FAILURE;
    }
    initialise_matrix();

    for (int i = 0; i < ITERATIONS; i++) {
        update_matrix();
        display_matrix();
        usleep(DELAY);
    }
    return EXIT_SUCCESS;

}
