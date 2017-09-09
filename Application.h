#ifndef TP2_TALLER_APPLICATION_H
#define TP2_TALLER_APPLICATION_H


#include "ArgumentHandler.h"

class Application {
public:
  explicit Application(int argc, char *argv[]);

  ~Application();

private:
  bool debug;
  ArgumentHandler argumentHandler;
  std::istream *source;
  std::ostream *destination;

  void _setOptions();
  void _run();
};


#endif //TP2_TALLER_APPLICATION_H
