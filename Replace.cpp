#include <iostream>
#include <utility>
#include <string>
#include "Replace.h"


void Replace::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push(Line());
}

Replace::Replace(const std::string& regex, const std::string& replacement,
                 BlockingQueue& source) :
  regex(regex),
  replacement(replacement),
  source(source) {}

BlockingQueue &Replace::outputQueue() {
  return destination;
}
