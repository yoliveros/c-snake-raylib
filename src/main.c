#include <raylib.h>

int main() {
  const int screen_width = 800;
  const int screen_height = 600;

  InitWindow(screen_width, screen_height, "Ray lib tuto");

  SetTargetFPS(144);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("GG Enorawena", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
