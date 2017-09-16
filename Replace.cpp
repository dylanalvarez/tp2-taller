#include <iostream>
#include <utility>
#include <regex>
#include "Replace.h"


void Replace::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    std::regex regex = std::regex(this->regex, std::regex::ECMAScript);
    std::string newContent = std::regex_replace(
      line.getContent(), regex, replacement);
    Line newLine = Line(newContent);
    destination.push(newLine);
    if (logger) { _log(line.getContent(), newLine.getContent()); }
    line = source.pop();
  }
  destination.push(Line());
}

Replace::Replace(const std::string &regex, const std::string &replacement,
                 BlockingQueue &source) :
  regex(regex),
  replacement(replacement),
  source(source) {}

BlockingQueue &Replace::outputQueue() {
  return destination;
}

void Replace::addLogger(Logger *logger) {
  Thread::addLogger(logger);
  this->processID = logger->getProcessID("replace");
}
