#ifndef TP2_TALLER_ARGUMENT_HANDLER_H
#define TP2_TALLER_ARGUMENT_HANDLER_H

#include <string>

/*
 * A class that simplifies program argument retrieval
 */
class ArgumentHandler {
public:
  /*
   * Same arguments as the program's main function
   */
  ArgumentHandler(int argc, char **argv);

  /*
   * Pre:  thereIsNextArgument()
   */
  std::string nextArgument();

  bool thereIsNextArgument();

  /*
   * Post: nextArgument() will be the same as the one returned last time
   */
  void rewind();

private:
  std::string _nextArgument();

  int argc;
  char **argv;
  int currentArgumentPosition;
};


#endif //TP2_TALLER_ARGUMENT_HANDLER_H
