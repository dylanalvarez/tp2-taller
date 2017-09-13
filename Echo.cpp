#include "Echo.h"

void Echo::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    destination.push(line);
    line = source.pop();
  }
  destination.push(Line());
}

Echo::Echo(BlockingQueue &source) :
  source(source) {}

BlockingQueue &Echo::outputQueue() {
  return destination;
}
