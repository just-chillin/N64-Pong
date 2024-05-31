#include "ball.h"

struct ball make_ball() {
    // Determine the center of the screen
    int center_x = display_get_width() / 2;
    int center_y = display_get_height() / 2;
    struct ball ball = {
        .x = center_x,
        .y = center_y
    };
    return ball;
}

void render_ball(surface_t* display) {

}

void update_ball(struct ball* ball, surface_t* display) {
    // Get the current vector
    // Update the position based on the vector
    // Check for collisions
    // Update the vector based on the collisions
    // Draw the ball

    // print the address of display
    printf("display address: %p\n", display);
    render_ball(display);
}