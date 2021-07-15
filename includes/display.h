#ifndef display_H
#define display_H

#define X 300
#define Y 70

#define BRIGHTEST 14

typedef struct cell_T {
    char symbol;
    int brightness;
} cell;

extern cell matrix[X][Y];

bool initialise_display();
void display_matrix();
void destroy_display();

#endif
