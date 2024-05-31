#include "ball.h"

const int SIZE = 10;

struct ball make_ball() {
  // Determine the center of the screen
  int center_x = display_get_width() / 2;
  int center_y = display_get_height() / 2;
  return (struct ball){
      .x = center_x, .y = center_y, .direction_x = 1, .direction_y = 0};
}

void render_ball(struct ball *ball, surface_t *display) {
  graphics_draw_box(display, ball->x, ball->y, SIZE, SIZE,
                    graphics_make_color(255, 255, 255, 255));
}

void update_ball(struct ball *ball, surface_t *display) {
  // Get the current vector
  // Update the position based on the vector

  // Check for collisions
  // Update the vector based on the collisions
  // Draw the ball
  render_ball(ball, display);
}