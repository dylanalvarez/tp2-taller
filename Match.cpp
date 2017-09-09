#include <iostream>
#include "Match.h"

void Match::run() {
  std::cout << "Match" << regex << "!" << std::endl;
}

Match::Match(const std::string &regex) : regex(regex) {}
