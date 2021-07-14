#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdbool.h>

#include "../includes/display.h"
#include "../includes/matrix.h"

cell matrix[X][Y];
droplet droplets[total_droplets];

void initialise_droplets() {
    for (int i=0; i < total_droplets; i ++) {
        droplets[i].active = false;
    }
}

void update_droplets() {
    for (int i = 0; i < total_droplets; i ++) {
        if (droplets[i].active) {
            matrix[droplets[i].x][droplets[i].y].brightness = MAX_INTENSITY;
        }
        if (++droplets[i].y >= Y -1) {
            droplets[i].active = false;
        }
    }
}

void add_droplets() {
    for (int i = 0; i < total_droplets; i ++) {
        if (!droplets[i].active) {
            if ((double) rand() / (double) RAND_MAX > 0.5) {
                 droplets[i].x = rand() % X; // random x position
                 droplets[i].y = 0; // begin at the top
            }
        }
    }
}

void initialise_matrix() {
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            matrix[x][y].symbol = 0;
            matrix[x][y].brightness = 0;
        }
    }
    initialise_droplets();
}

void update_matrix() {

    add_droplets();
    update_droplets();
    // randomly change all characters 

    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            matrix[x][y].symbol = 'X'; //TODO randomize this
            // decrement brightness
            if (matrix[x][y].brightness > 0) {
                matrix[x][y].brightness--; // cells fade away
            };
        }
    }
}

