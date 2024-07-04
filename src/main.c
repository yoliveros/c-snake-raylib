#include "include/raylib.h"

#include "SnakeBody.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define offset 75
#define cell_size 30
#define cell_count 30
#define interval 0.08

Vector2 init_head = {(float)cell_count / 2, (float)cell_count / 2};

State state = {
    .direction = {.5, 0},
    .body = {{0}},
    .score = 0,
};

void reset() {
  restart();

  state = (State){
      .direction = {.5, 0},
      .body = {{0}},
      .score = 0,
  };

  en_queue(init_head, false);
}

void snake_movement() {
  if (IsKeyDown(KEY_RIGHT) && state.direction.x != -.5) {
    state.direction = (Vector2){.5, 0};
  }
  if (IsKeyDown(KEY_LEFT) && state.direction.x != .5) {
    state.direction = (Vector2){-.5, 0};
  }
  if (IsKeyDown(KEY_UP) && state.direction.y != .5) {
    state.direction = (Vector2){0, -.5};
  }
  if (IsKeyDown(KEY_DOWN) && state.direction.y != -.5) {
    state.direction = (Vector2){0, .5};
  }

  Vector2 *curr_head = get_rear();
  Vector2 new_head = {
      curr_head->x + state.direction.x,
      curr_head->y + state.direction.y,
  };

  printf("%f, %f\n", new_head.x, new_head.y);

  if (new_head.x >= cell_count || new_head.x <= -.5 ||
      new_head.y >= cell_count || new_head.y <= -.5) {
    printf("Game over\n");
    reset();
    return;
  }

  en_queue(new_head, false);
  de_queue();
}

int main() {
  InitWindow(2 * offset + cell_size * cell_count,
             2 * offset + cell_size * cell_count, "Snake");

  SetTargetFPS(60);

  en_queue(init_head, false);

  double last_update = 0;

  while (!WindowShouldClose()) {
    // update
    double curr_time = GetTime();

    if (curr_time - last_update < interval) {
      continue;
    }

    snake_movement();

    last_update = curr_time;

    Vector2 *curr_head = get_rear();

    BeginDrawing();
    ClearBackground(GREEN);
    DrawRectangle(offset + curr_head->x * cell_size - 1,
                  offset + curr_head->y * cell_size, 20, 20, WHITE);
    DrawText("Snake", offset - 5, 20, 40, DARKGREEN);
    Rectangle rect = {(float)offset - 5, (float)offset - 5,
                      (float)cell_size * cell_count + 10,
                      (float)cell_size * cell_count + 10};
    DrawRectangleLinesEx(rect, 5, DARKGREEN);
    DrawText(TextFormat("%i", state.score), offset - 5,
             offset + cell_size * cell_count + 10, 40, DARKGREEN);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
