#pragma once

#include <libdragon.h>

struct Entity {
  int id;
  void (*update)(struct Entity *, struct Game *);

  // Entity specific data. Ex: player has a health, enemy has a damage, etc.
  void *data;
};

struct Game {
  struct Entity *entities;
  int num_entities;
  struct controller_data controller_data;
};

struct Game *create_game();
void add_entity(struct Game *game, struct Entity entity);
void tick(struct Game *game);
struct controller_data get_controller_data(struct Game *game);