#include <iostream>
#include "BlockingQueue.h"

void BlockingQueue::push(std::string &&line) {
  {
    std::unique_lock<std::mutex> lock(mutex);
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
  queue.pop();
  return front;
}

BlockingQueue::BlockingQueue(BlockingQueue &&other) noexcept {
  queue = std::move(other.queue);
}
