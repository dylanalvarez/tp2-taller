#ifndef TP2_TALLER_THREAD_H
#define TP2_TALLER_THREAD_H


#include <thread>
#include "BlockingQueue.h"

class Thread {
public:
  void start();

  void join();

  virtual void run() = 0;

  virtual BlockingQueue& outputQueue() = 0;

  Thread() = default;

  Thread(const Thread &) = delete;

  Thread &operator=(const Thread &) = delete;

  Thread(Thread &&other) noexcept;

  Thread &operator=(Thread &&other) noexcept;

  virtual ~Thread() = default;

private:
  std::thread thread;
};


#endif //TP2_TALLER_THREAD_H
