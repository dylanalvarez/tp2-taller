#ifndef TP2_TALLER_BLOCKING_QUEUE_H
#define TP2_TALLER_BLOCKING_QUEUE_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class BlockingQueue {
public:
  void push(std::string);

  std::string pop();

  BlockingQueue() = default;

  BlockingQueue(const BlockingQueue &) = delete;

  BlockingQueue &operator=(const BlockingQueue &) = delete;

private:
  std::queue<std::string> queue;
  std::mutex mutex;
  std::condition_variable conditionVariable;
};


#endif //TP2_TALLER_BLOCKING_QUEUE_H
