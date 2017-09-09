#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H

#include <vector>
#include "ArgumentHandler.h"
#include "Thread.h"

class Application {
public:
  explicit Application(int argc, char *argv[]);

  ~Application();

private:
  bool debug;
  ArgumentHandler argumentHandler;
  std::istream *source;
  std::ostream *destination;
  std::vector<Thread*> threads;

  void _setOptions();
  void _prepareThreads();
  void _startThreads();
  void _joinThreads();
};


#endif //TP2_TALLER_APPLICATION_H
