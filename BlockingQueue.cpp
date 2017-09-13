#include <iostream>
#include <string>
#include "BlockingQueue.h"

void BlockingQueue::push(std::string line) {
  {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(line);
  }
  conditionVariable.notify_one();
}

std::string BlockingQueue::pop() {
  std::unique_lock<std::mutex> lock(mutex);
  while (queue.empty()) {
    conditionVariable.wait(lock, [this] { return !queue.empty(); });
  }
  std::string &front = queue.front();
  std::string to_return = front;
  queue.pop();
  return to_return;
}
