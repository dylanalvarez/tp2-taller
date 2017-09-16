#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H

#include <vector>
#include "ArgumentHandler.h"
#include "Thread.h"
#include "BlockingQueue.h"
#include "Logger.h"

class Application {
public:
  Application(int argc, char *argv[]);

  void operator()();

  ~Application();

private:
  bool debug;
  ArgumentHandler argumentHandler;
  std::istream *source;
  std::ostream *destination;
  std::vector<Thread *> threads;
  Logger logger;

  void _setOptions();

  void _prepareThreads();

  void _prepareLogger();

  void _startThreads();

  void _joinThreads();
};


#endif //TP2_TALLER_APPLICATION_H
