#pragma once

#include <libdragon.h>

struct ball {
  int x, y;
  int direction_x, direction_y;
};

struct ball make_ball();
void update_ball(struct ball *ball, surface_t *display);