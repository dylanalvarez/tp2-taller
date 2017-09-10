#include <iostream>
#include <string>
#include "Echo.h"

void Echo::run() {
  std::string line = source.pop();
  while (!line.empty()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push("");
}

Echo::Echo(BlockingQueue& source) :
  source(source),
  destination(BlockingQueue()) {}

BlockingQueue &Echo::outputQueue() {
  return destination;
}
