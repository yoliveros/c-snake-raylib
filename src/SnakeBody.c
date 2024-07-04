#include "SnakeBody.h"
#include <stdlib.h>

int front = -1, rear = -1;

void en_queue(Vector2 value) {
  if (rear == SIZE - 1)
    return;

  if (front == -1) {
    front = 0;
  }

  rear++;
  state.body[rear] = value;
}

void de_queue() {
  if (front == -1)
    return;

  front++;
  if (front > rear)
    front = rear = -1;
}

Vector2 *get_rear() {
  if (front == -1)
    return NULL;

  return &state.body[rear];
}

void restart() { front = rear = -1; }
