#include "Echo.h"

void Echo::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    destination.push(line);
    if (logger) { _log(line.getContent(), line.getContent()); }
    line = source.pop();
  }
  destination.push(Line());
}

Echo::Echo(BlockingQueue &source) :
  source(source) {}

BlockingQueue &Echo::outputQueue() {
  return destination;
}

void Echo::addLogger(Logger *logger) {
  Thread::addLogger(logger);
  this->processID = logger->getProcessID("echo");
}
