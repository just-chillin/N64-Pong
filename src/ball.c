#include "ball.h"

struct ball make_ball() {
    struct ball ball = {
        .x = 0,
        .y = 0
    };
    return ball;
}

void update_ball(surface_t* display) {
    // Get the current vector
    // Update the position based on the vector
    // Check for collisions
    // Update the vector based on the collisions
    // Draw the ball

    // print the address of display
    printf("display address: %p\n", display);
    // graphics_draw_box(display, 100, 100, 100, 100, graphics_make_color(255, 255, 0, 255));
}