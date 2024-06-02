#include "ball.h"

const int SIZE = 10;

struct ball make_ball() {
  // Determine the center of the screen
  int center_x = display_get_width() / 2;
  int center_y = display_get_height() / 2;
  return (struct ball){
      .x = center_x, .y = center_y, .direction_x = 1, .direction_y = .5};
}

void render_ball(struct ball *ball, surface_t *display) {
  graphics_draw_box(display, ball->x, ball->y, SIZE, SIZE,
                    graphics_make_color(255, 255, 255, 255));
}

void move_ball(struct ball *ball) {
  // Update the position based on the vector
  ball->x += ball->direction_x;
  ball->y += ball->direction_y;
}

float calculate_bounce(struct ball *ball, struct player *player) {
  int midpoint = player->y + PLAYER_HEIGHT / 2;
  int distance_y_m = abs(midpoint - ball->y);
  float dy = -4 / PLAYER_HEIGHT * distance_y_m + 1;
  return dy * ball->direction_y;
}

void bounce(struct ball *ball, struct player *players) {
  // Check for collisions against the players
  for (int i = 0; i < 2; i++) {
    struct player player = players[i];
    if (coordinate_collides_with(&player, ball->x, ball->y) ||
        coordinate_collides_with(&player, ball->x + SIZE, ball->y + SIZE)) {
      ball->direction_x *= -1;
      ball->direction_y = calculate_bounce(ball, &player);
    }
  }

  // Check for collisions against the top and bottom of the screen
  if (ball->y < 0 || ball->y + SIZE > display_get_height()) {
    ball->direction_y *= -1;
  }
}

void update_ball(struct ball *ball, struct player *players,
                 surface_t *display) {
  // Get the current vector
  // Update the position based on the vector
  move_ball(ball);

  // Check for collisions
  // Update the vector based on the collisions
  bounce(ball, players);

  // Draw the ball
  render_ball(ball, display);
}