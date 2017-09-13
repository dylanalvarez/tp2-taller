#include <iostream>
#include <utility>
#include <string>
#include "Match.h"

void Match::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push(Line());
}

BlockingQueue &Match::outputQueue() {
  return destination;
}

Match::Match(const std::string& regex,
             BlockingQueue& source) :
  regex(regex),
  source(source) {}
