#include "Queue.h"

void Queue::push(std::string &&line) {
  queue.push(line);
}

std::string Queue::pop() {
  std::string &front = queue.front();
  queue.pop();
  return front;
}
