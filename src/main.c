#include <stdio.h>

#include <libdragon.h>

#include "ball.h"
#include "player.h"

/**
 * @brief Gets inputs from the players
 *
 * @return float* Returns a tuple of xy inputs from the players. Guaranteed to
 * be of size 2.
 */
void get_inputs() {
  struct controller_data controller_data;
  controller_read(&controller_data);
}

void init_subsystems() {
  console_init();
  console_set_render_mode(RENDER_MANUAL);

  debug_init(DEBUG_FEATURE_ALL);
  console_set_debug(true);

  controller_init();

  display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
}

struct game {
  struct player players[2];
  struct ball ball;
};

void tick(struct game* game) {
    // console_render();
    controller_scan();
    surface_t* display = display_get();
    graphics_fill_screen(display, 0);

    update_player(&game->players[0], display);
    update_player(&game->players[1], display);
    update_ball(&game->ball, display);

    display_show(display);
}

int main(void) {
  init_subsystems();

  struct controller_data controller_data;

  struct game game = {
    .players = {make_player(0), make_player(1)},
    .ball = make_ball(),
  };

  while (1) {
    tick(&game);
  }
}