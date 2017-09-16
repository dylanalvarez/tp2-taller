#include <iostream>
#include <utility>
#include <regex>
#include "Match.h"

void Match::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    std::regex regex = std::regex(this->regex, std::regex::ECMAScript);
    bool itsAMatch = std::regex_search(line.getContent(), regex);
    if (itsAMatch) {
      destination.push(line);
    }
    if (logger) {
      _log(line.getContent(), itsAMatch ? line.getContent() : "(Filtrado)");
    }
    line = source.pop();
  }
  destination.push(Line());
}

BlockingQueue &Match::outputQueue() {
  return destination;
}

Match::Match(const std::string &regex,
             BlockingQueue &source) :
  regex(regex),
  source(source) {}

void Match::addLogger(Logger *logger) {
  Thread::addLogger(logger);
  this->processID = logger->getProcessID("match");
}
