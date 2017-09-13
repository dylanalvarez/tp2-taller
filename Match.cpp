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

Match::Match(const std::string& regex,
             BlockingQueue& source) :
  regex(regex),
  source(source) {}
