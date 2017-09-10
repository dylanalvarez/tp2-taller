#include <iostream>
#include <utility>
#include <string>
#include "Replace.h"


void Replace::run() {
  std::string line = source.pop();
  while (!line.empty()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push("");
}

Replace::Replace(std::string regex, std::string replacement,
                 BlockingQueue& source) :
  regex(std::move(regex)),
  replacement(std::move(replacement)),
  source(source),
  destination(BlockingQueue()) {}

BlockingQueue &Replace::outputQueue() {
  return destination;
}
