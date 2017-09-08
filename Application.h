#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H


#include "ArgumentHandler.h"

class Application {
public:
  explicit Application(ArgumentHandler);

  void run();

private:
  bool debug;
  ArgumentHandler argumentHandler;
};


#endif //TP2_TALLER_APPLICATION_H
