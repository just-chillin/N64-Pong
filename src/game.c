#include <stdlib.h>

#include <libdragon.h>

#include "game.h"

struct Game *create_game() {
  struct Game *game = calloc(1, sizeof(struct Game));
  *game = (struct Game){.entities = calloc(0, sizeof(struct Entity)),
                        .num_entities = 0};
  return game;
}

void add_entity(struct Game *game, struct Entity entity) {
  game->entities =
      realloc(game->entities, (game->num_entities + 1) * sizeof(struct Entity));
  game->entities[game->num_entities] = entity;
  game->num_entities++;
}

void tick(struct Game *game) {
  // Read inputs from the controllers
  controller_read(&game->controller_data);

  // Update all entities
  for (int i = 0; i < game->num_entities; i++) {
    game->entities[i].update(&game->entities[i], game);
  }
}

struct controller_data get_controller_data(struct Game *game) {
  return game->controller_data;
}