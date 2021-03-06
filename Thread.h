#ifndef TP2_TALLER_THREAD_H
#define TP2_TALLER_THREAD_H


#include <thread>
#include <string>
#include "BlockingQueue.h"
#include "Logger.h"

class Thread {
public:
  void start();

  void join();

  virtual void run() = 0;

  /*
   * If a logger is added, each step will be notified to it
   */
  virtual void addLogger(Logger *logger);

  /*
   * The thread that is waiting for this instance's output needs a
   * reference to its output queue
   */
  virtual BlockingQueue &outputQueue() = 0;

  Thread();

  Thread(const Thread &) = delete;

  Thread &operator=(const Thread &) = delete;

  Thread(Thread &&other) noexcept;

  Thread &operator=(Thread &&other) noexcept;

  virtual ~Thread() = default;

protected:
  void _log(const std::string &input, const std::string &output);

  std::thread thread;
  Logger *logger;
  std::string processID;
};


#endif //TP2_TALLER_THREAD_H
