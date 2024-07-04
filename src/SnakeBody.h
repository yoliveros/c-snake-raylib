#pragma once

#include "include/raylib.h"

#define SIZE 255

typedef struct {
  Vector2 direction;
  unsigned char score;
  Vector2 body[SIZE];
} State;

extern State state;

void en_queue(Vector2 value);

void de_queue();

Vector2 *get_rear();

void restart();
