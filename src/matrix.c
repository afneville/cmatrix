#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdbool.h>

#include "../includes/display.h"
#include "../includes/matrix.h"

cell matrix[X][Y];
point points[total_points];

void initialise_points() {
    for (int i=0; i < total_points; i ++) {
        points[i].active = false;
    }
}

void add_points() {
    for (int i = 0; i < total_points; i ++) {
        if (!points[i].active) {
            if ((double) rand() / (double) RAND_MAX > 0.95) {
                 points[i].active = true;
                 points[i].x = rand() % X; // random x position
                 points[i].y = 0; // begin at the top
            }
        }
    }
}

void update_points() {
    for (int i = 0; i < total_points; i ++) {
        if (points[i].active) {
            matrix[points[i].x][points[i].y].brightness = BRIGHTEST;
        }
        if (++points[i].y >= Y - 1) {
            points[i].active = false;
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
    initialise_points();
}

void update_matrix() {

    add_points();
    update_points();
    // randomly change all characters 

    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            matrix[x][y].symbol = 33 + rand()%75;
            // decrement brightness
            if (matrix[x][y].brightness > 0) {
                matrix[x][y].brightness--; // cells fade away
            };
        }
    }
}

