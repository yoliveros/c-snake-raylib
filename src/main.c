#include "include/raylib.h"

#include "SnakeBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define offset 75
#define cell_size 30
#define cell_count 30
#define interval 0.08

Vector2 init_head = {(float)cell_count / 2, (float)cell_count / 2};

Vector2 food;

State state = {
    .direction = {.5, 0},
    .body = {{0}},
    .score = 0,
};

void gen_food(Vector2 *value) {
  int x = rand() % cell_count;
  int y = rand() % cell_count;
  *value = (Vector2){x, y};
}

void reset() {
  restart();

  state = (State){
      .direction = {.5, 0},
      .body = {{0}},
      .score = 0,
  };

  en_queue(init_head, false);
  gen_food(&food);
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

  if (new_head.x >= cell_count || new_head.x <= -.5 ||
      new_head.y >= cell_count || new_head.y <= -.5) {
    printf("Game over\n");
    reset();
    return;
  }

  en_queue(new_head, true);
}

int main() {
  InitWindow(2 * offset + cell_size * cell_count,
             2 * offset + cell_size * cell_count, "Snake");

  SetTargetFPS(60);

  en_queue(init_head, false);

  gen_food(&food);

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

    printf("%f, %f\n", curr_head->x, curr_head->y);

    BeginDrawing();
    ClearBackground(GREEN);
    DrawRectangle(offset + food.x * cell_size - 1, offset + food.y * cell_size,
                  20, 20, RED);
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
