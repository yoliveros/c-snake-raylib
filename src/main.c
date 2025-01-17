#include "include/raylib.h"
#include <stdio.h>

#define GRID_SIZE 16
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

struct snake_struct {
  Vector2 position;
  Vector2 velocity;
};

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "snake");
  bool started = false;

  struct snake_struct snake[100] = {0};
  int snake_length = 1;

  for (int i = 0; i < snake_length; i++) {
    snake[i].position.x = 8 + i;
    snake[i].position.y = 8;
  }

  Vector2 collect = {11, 3};

  int base_fps = 10;
  SetTargetFPS(base_fps);

  while (!WindowShouldClose()) {
    int fps = GetFPS();

    if (IsKeyDown(KEY_SPACE)) {
      if (!started)
        started = true;
    }

    // SNAKE MOVEMENT
    if (started) {
      for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
      }

      if (IsKeyDown(KEY_RIGHT)) {
        snake[0].velocity = (Vector2){1, 0};
      } else if (IsKeyDown(KEY_LEFT)) {
        snake[0].velocity = (Vector2){-1, 0};
      } else if (IsKeyDown(KEY_UP)) {
        snake[0].velocity = (Vector2){0, -1};
      } else if (IsKeyDown(KEY_DOWN)) {
        snake[0].velocity = (Vector2){0, 1};
      }

      snake[0].position.x += snake[0].velocity.x;
      snake[0].position.y += snake[0].velocity.y;
    }

    // COLLISIONS AND SCREEN BORDER
    if (snake[0].position.x >= GRID_SIZE)
      snake[0].position.x = 0;
    else if (snake[0].position.x < 0)
      snake[0].position.x = GRID_SIZE - 1;

    if (snake[0].position.y >= GRID_SIZE)
      snake[0].position.y = 0;
    else if (snake[0].position.y < 0)
      snake[0].position.y = GRID_SIZE - 1;

    if (snake[0].position.x == collect.x && snake[0].position.y == collect.y) {
      snake_length++;
      collect.x = GetRandomValue(0, GRID_SIZE - 1);
      collect.y = GetRandomValue(0, GRID_SIZE - 1);
    }

    for (int i = 1; i < snake_length; i++) {
      if (snake[0].position.x == snake[i].position.x &&
              snake[0].position.y == snake[i].position.y ||
          IsKeyDown(KEY_R)) {
        snake_length = 1;
        snake[0].position.x = 8;
        snake[0].position.y = 8;
        started = false;
      }
    }

    // DRAWING
    BeginDrawing();
    ClearBackground(GREEN);

    for (int i = 0; i < snake_length; ++i) {
      Rectangle rect = {snake[i].position.x * SCREEN_WIDTH / GRID_SIZE,
                        snake[i].position.y * SCREEN_HEIGHT / GRID_SIZE,
                        SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT / GRID_SIZE};

      DrawRectangleRec(rect, WHITE);
    }

    DrawRectangle(collect.x * SCREEN_WIDTH / GRID_SIZE,
                  collect.y * SCREEN_HEIGHT / GRID_SIZE,
                  SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT / GRID_SIZE, RED);

    // START MESSAGE
    if (!started) {
      DrawText("PRESS SPACE TO PLAY", 16, 400, 36, PURPLE);
    }

    // SCORE
    char conv[10];
    snprintf(conv, sizeof(conv), "%d", snake_length);

    DrawText(conv, 256, 16, 36, BLUE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
