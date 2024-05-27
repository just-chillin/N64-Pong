#include <stdio.h>

#include <libdragon.h>

#include "game.h"

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
  console_set_render_mode(RENDER_AUTOMATIC);

  debug_init(DEBUG_FEATURE_ALL);
  console_set_debug(true);

  controller_init();
}

int main(void) {
  init_subsystems();

  struct Game *game = create_game();

  while (1) {
    console_render();
    tick(game);
  }
}