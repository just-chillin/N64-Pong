#pragma once

#include <libdragon.h>

const extern int PLAYER_HEIGHT;

struct player {
  int id;
  int y;
  int points;
};

struct player make_player(int id);
void update_player(struct player *player, surface_t *display);
bool coordinate_collides_with(struct player *player, int x, int y);