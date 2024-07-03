#include "include/raylib.h"

#include "SnakeBody.h"

#define offset 75
#define cell_size 30
#define cell_count 25

Vector2 direction = {0, -1};

void snake_movement() {
  if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
  }
  if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
  }
  if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
  }
  if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP)) {
  }

  Vector2 curr_head = *body[0];
  // Vector2 new_head = {curr_head.x + direction.x, curr_head.y + direction.y};
  Vector2 new_head = {curr_head.x + 1, curr_head.y + 1};
  en_queue(new_head);
}

int main() {
  InitWindow(2 * offset + cell_size * cell_count,
             2 * offset + cell_size * cell_count, "Snake");

  SetTargetFPS(60);

  Vector2 init_head = {(float)cell_count / 2, (float)cell_count / 2};
  en_queue(init_head);

  while (!WindowShouldClose()) {
    // update
    snake_movement();

    Vector2 curr_head = *body[0];

    BeginDrawing();
    ClearBackground(GREEN);
    DrawRectangle(offset + curr_head.x * cell_size,
                  offset + curr_head.y * cell_size, 30, 20, WHITE);
    DrawText("Snake", offset - 5, 20, 40, DARKGREEN);
    Rectangle rect = {(float)offset - 5, (float)offset - 5,
                      (float)cell_size * cell_count + 10,
                      (float)cell_size * cell_count + 10};
    unsigned int score = 0;
    DrawRectangleLinesEx(rect, 5, DARKGREEN);
    DrawText(TextFormat("%i", score), offset - 5,
             offset + cell_size * cell_count + 10, 40, DARKGREEN);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
