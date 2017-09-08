#include <string>
#include <stdexcept>
#include "ArgumentHandler.h"

ArgumentHandler::ArgumentHandler(int argc, char **argv) :
  argc(argc), argv(argv) {
  this->currentArgumentPosition = 0;
}

std::string ArgumentHandler::_nextArgument() {
  return std::string(argv[this->currentArgumentPosition + 1]);
}

std::string ArgumentHandler::nextArgument() {
  if (this->currentArgumentPosition >= this->argc) { throw std::exception(); }
  std::string argument = this->_nextArgument();
  this->currentArgumentPosition++;
  return argument;
}

bool ArgumentHandler::thereIsNextArgument() {
  return this->currentArgumentPosition < this->argc - 1;
}

void ArgumentHandler::rewind() {
  if (this->currentArgumentPosition == 0) { throw std::exception(); }
  this->currentArgumentPosition--;
}
