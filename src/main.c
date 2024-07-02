#include "include/raylib.h"

#define offset 75
#define cell_size 30
#define cell_count 25

int main() {
  InitWindow(2 * offset + cell_size * cell_count,
             2 * offset + cell_size * cell_count, "Snake");

  SetTargetFPS(60);

  Vector2 square_position = {(float)cell_count / 2, (float)cell_count / 2};

  while (!WindowShouldClose()) {
    // update
    if (IsKeyDown(KEY_RIGHT))
      square_position.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      square_position.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
      square_position.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      square_position.y += 2.0f;

    BeginDrawing();
    ClearBackground(GREEN);
    DrawRectangle(offset + square_position.x * cell_size,
                  offset + square_position.y * cell_size, 30, 20, WHITE);
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
