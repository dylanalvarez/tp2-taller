#include <iostream>
#include <string>
#include "BlockingQueue.h"

void BlockingQueue::push(Line line) {
  {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(line);
  }
  conditionVariable.notify_one();
}

Line BlockingQueue::pop() {
  std::unique_lock<std::mutex> lock(mutex);
  while (queue.empty()) {
    conditionVariable.wait(lock, [this] { return !queue.empty(); });
  }
  Line &front = queue.front();
  Line value = front;
  queue.pop();
  return value;
}
