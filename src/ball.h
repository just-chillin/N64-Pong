#pragma once

#include <libdragon.h>

#include "player.h"

struct ball {
  int x;
  float y;
  int direction_x;
  float direction_y;
};

struct ball make_ball();
void update_ball(struct ball *ball, struct player *players, surface_t *display);