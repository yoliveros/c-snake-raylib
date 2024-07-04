#include "include/raylib.h"

#include "SnakeBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define offset 75
#define cell_size 30
#define cell_count 25

Vector2 init_head = {(float)cell_count / 2, (float)cell_count / 2};

State state = {
    .direction = {1, 0},
    .body = {{0}},
    .score = 0,
};

void reset() {
  for (int i = 0; i < SIZE - 1; i++) {
    printf("%f, %f\n", state.body[i].x, state.body[i].y);
  }

  restart();

  state = (State){
      .direction = {1, 0},
      .body = {{0}},
      .score = 0,
  };

  en_queue(init_head);

  exit(-1);
}

void snake_movement() {
  if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
    state.direction = (Vector2){1, 0};
  }
  if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
    state.direction = (Vector2){-1, 0};
  }
  if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
    state.direction = (Vector2){0, 1};
  }
  if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP)) {
    state.direction = (Vector2){0, -1};
  }

  Vector2 *curr_head = get_rear();
  Vector2 new_head = {curr_head->x + state.direction.x,
                      curr_head->y + state.direction.y};

  if (new_head.x >= cell_count || new_head.y >= cell_count) {
    printf("chocaste el mio\n");
    reset();
    return;
  }

  en_queue(new_head);
  de_queue();
}

int main() {
  InitWindow(2 * offset + cell_size * cell_count,
             2 * offset + cell_size * cell_count, "Snake");

  SetTargetFPS(60);

  en_queue(init_head);

  while (!WindowShouldClose()) {
    // update
    snake_movement();

    Vector2 *curr_head = get_rear();

    BeginDrawing();
    ClearBackground(GREEN);
    DrawRectangle(offset + curr_head->x * cell_size,
                  offset + curr_head->y * cell_size, 30, 20, WHITE);
    DrawText("Snake", offset - 5, 20, 40, DARKGREEN);
    Rectangle rect = {(float)offset - 5, (float)offset - 5,
                      (float)cell_size * cell_count + 10,
                      (float)cell_size * cell_count + 10};
    DrawRectangleLinesEx(rect, 5, DARKGREEN);
    DrawText(TextFormat("%i", state.score), offset - 5,
             offset + cell_size * cell_count + 10, 40, DARKGREEN);
    EndDrawing();
    sleep(02);
  }

  CloseWindow();

  return 0;
}
