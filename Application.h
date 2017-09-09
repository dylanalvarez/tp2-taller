#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H


#include "ArgumentHandler.h"

class Application {
public:
  explicit Application(ArgumentHandler);

  void run();

  ~Application();

private:
  bool debug;
  ArgumentHandler argumentHandler;
  std::istream *source;
  std::ostream *destination;
};


#endif //TP2_TALLER_APPLICATION_H
