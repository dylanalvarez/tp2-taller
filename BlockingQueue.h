#ifndef TP2_TALLER_BLOCKING_QUEUE_H
#define TP2_TALLER_BLOCKING_QUEUE_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Line.h"

class BlockingQueue {
public:
  void push(Line);

  Line pop();

  BlockingQueue() = default;

  BlockingQueue(const BlockingQueue &) = delete;

  BlockingQueue &operator=(const BlockingQueue &) = delete;

private:
  std::queue<Line> queue;
  std::mutex mutex;
  std::condition_variable conditionVariable;
};


#endif //TP2_TALLER_BLOCKING_QUEUE_H
