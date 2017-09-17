#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H

#include <vector>
#include "ArgumentHandler.h"
#include "Thread.h"
#include "BlockingQueue.h"
#include "Logger.h"

/*
 * A functor that is initialized with the program arguments received in the
 * main function and when run, executes the application
 */
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
