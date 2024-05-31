#include "player.h"

const int SPEED = 3;
const int HEIGHT = 30;
const int WIDTH = 10;

struct player make_player(int id) {
  struct player player = {.id = id, .y = 0};
  return player;
}

void render_player(struct player *player, surface_t *display) {
  uint64_t width = display_get_width();

  // if player 0, put the player on the left side of the screen
  // else put the player on the right side of the screen
  int x_pos = player->id == 0 ? 0 : width - 10;
  graphics_draw_box(display, x_pos, player->y, WIDTH, HEIGHT,
                    graphics_make_color(255, 255, 255, 255));
}

void move_player(struct player *player) {
  int direction = get_dpad_direction(player->id);
  if (direction == 2) {
    int top_y = player->y + HEIGHT;
    int disp_height = display_get_height();
    if (top_y < disp_height) {
      player->y += SPEED;
    }
  } else if (direction == 6) {
    if (player->y > 0) {
      player->y -= SPEED;
    }
  }
}

void update_player(struct player *player, surface_t *display) {
  // create a string appending up down left or right depending on which is
  // pressed on the controller printf("player %d d-pad direction: %d\n",
  // player->id, get_dpad_direction(player->id));
  move_player(player);
  render_player(player, display);
}
