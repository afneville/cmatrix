#ifndef matrix_H
#define matrix_H
#define total_points 300

typedef struct point_T {
    int x, y;
    bool active;
} point;

void initialise_matrix();
void initialise_points();
void add_points();
void update_points();
void update_matrix();

#endif
