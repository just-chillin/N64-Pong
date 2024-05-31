#pragma once

#include <libdragon.h>

struct player {
  int id;
  int y;
};

struct player make_player(int id);
void update_player(struct player *player, surface_t *display);