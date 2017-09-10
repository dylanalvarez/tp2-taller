#include <iostream>
#include <utility>
#include <string>
#include "Match.h"

void Match::run() {
  std::string line = source.pop();
  while (!line.empty()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push("");
}

BlockingQueue &Match::outputQueue() {
  return destination;
}

Match::Match(std::string regex,
             BlockingQueue& source) :
  regex(std::move(regex)),
  source(source),
  destination(BlockingQueue()) {}
