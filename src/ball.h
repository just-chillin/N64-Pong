#pragma once

#include <libdragon.h>

#include "player.h"

struct ball {
  int x, y;
  int direction_x, direction_y;
};

struct ball make_ball();
void update_ball(struct ball *ball, struct player *players, surface_t *display);