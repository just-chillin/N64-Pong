#include "score.h"

void render_score(surface_t *disp, int p1, int p2) {
  char p1_text[10] = {0};
  char p2_text[10] = {0};
  sprintf(&p1_text[0], "%d", p1);
  sprintf(&p2_text[0], "%d", p2);
  graphics_draw_text(disp, 30, 10, p1_text);
  graphics_draw_text(disp, display_get_width() - 30, 10, p2_text);
}