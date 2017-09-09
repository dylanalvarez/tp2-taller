#include <iostream>
#include <utility>
#include "Replace.h"


void Replace::run() {
  std::cout << "Replace" << regex << "with" << replacement << "!" << std::endl;
}

Replace::Replace(std::string regex, std::string replacement) :
  regex(std::move(regex)),
  replacement(std::move(replacement)) {}
