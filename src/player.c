#include "player.h"

const int SPEED = 3;
const int WIDTH = 10;
const int PLAYER_HEIGHT = 30;

struct player make_player(int id) {
  struct player player = {.id = id, .y = 0, .points = 0};
  return player;
}

int get_x(struct player *player) {
  return player->id == 0 ? WIDTH : display_get_width() - WIDTH;
}

void render_player(struct player *player, surface_t *display) {
  uint64_t width = display_get_width();

  // if player 0, put the player on the left side of the screen
  // else put the player on the right side of the screen
  int x_pos = get_x(player);
  graphics_draw_box(display, x_pos, player->y, WIDTH, PLAYER_HEIGHT,
                    graphics_make_color(255, 255, 255, 255));
}

void move_player(struct player *player) {
  int direction = get_dpad_direction(player->id);
  if (direction == 6) {
    int top_y = player->y + PLAYER_HEIGHT;
    int disp_height = display_get_height();
    if (top_y < disp_height) {
      player->y += SPEED;
    }
  } else if (direction == 2) {
    if (player->y > 0) {
      player->y -= SPEED;
    }
  }
}

void update_player(struct player *player, surface_t *display) {
  move_player(player);
  render_player(player, display);
}

bool coordinate_collides_with(struct player *player, int x, int y) {
  bool within_y_bounds = y >= player->y && y <= player->y + PLAYER_HEIGHT;

  int player_x = get_x(player);
  printf("player_x: %d, x=%d\n", player_x, x);
  bool within_x_bounds = x >= player_x && x <= player_x + WIDTH;

  return within_x_bounds && within_y_bounds;
}