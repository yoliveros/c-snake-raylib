#pragma once

#include "include/raylib.h"

#define SIZE 255

extern Vector2 *body[SIZE];

void en_queue(Vector2 value);

void de_queue();
