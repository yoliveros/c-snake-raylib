#include "SnakeBody.h"
#include <string.h>

Vector2 *body[SIZE];

int front = -1, rear = -1;

void en_queue(Vector2 value) {
  if (rear == SIZE - 1)
    return;

  if (front == -1) {
    front = 0;
    memset(*body, 0, sizeof(body));
  }

  rear++;
  *body[rear] = value;
}

void de_queue() {
  if (front == -1)
    return;

  front++;
  if (front > rear)
    front = rear = -1;
}
