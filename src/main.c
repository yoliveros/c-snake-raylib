#include "include/raylib.h"

int main() {
  const int screen_width = 800;
  const int screen_height = 600;

  InitWindow(screen_width, screen_height, "Ray lib tuto");

  SetTargetFPS(144);

  Vector2 square_position = {(float)screen_width / 2, (float)screen_height / 2};

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
    ClearBackground(RAYWHITE);
    DrawText("GG Enorawena", 190, 200, 20, LIGHTGRAY);
    DrawRectangle(square_position.x, square_position.y, 25, 25, MAROON);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
