#include <raylib.h>

int main() {
  const int screen_width = 800;
  const int screen_height = 600;

  InitWindow(screen_width, screen_height, "Ray lib tuto");

  SetTargetFPS(144);

  Vector2 square_position = {(float)screenWidth / 2, (float)screenHeight / 2};

  while (!WindowShouldClose()) {
    // update
    if (IsKeyDown(KEY_RIGHT))
      ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
      ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      ballPosition.y += 2.0f;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("GG Enorawena", 190, 200, 20, LIGHTGRAY);
    DrawRectangle(square_position, 25, 25, MAROON);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
