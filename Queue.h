#ifndef TP2_TALLER_QUEUE_H
#define TP2_TALLER_QUEUE_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class Queue {
public:
  Queue() = default;

  void push(std::string &&);

  std::string pop();

private:
  std::queue<std::string> queue;
//  std::mutex mutex;
//  std::condition_variable conditionVariable;
};


#endif //TP2_TALLER_QUEUE_H
