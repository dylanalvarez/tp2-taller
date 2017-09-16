#include <iostream>
#include <utility>
#include <regex>
#include <string>
#include "Replace.h"


void Replace::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    std::string newContent = std::regex_replace(
      line.getContent(), regex, replacement);
    Line newLine = Line(newContent);
    destination.push(newLine);
    line = source.pop();
  }
  destination.push(Line());
}

Replace::Replace(const std::string &regex, const std::string &replacement,
                 BlockingQueue &source) :
  regex(std::regex(regex, std::regex::ECMAScript)),
  replacement(replacement),
  source(source) {}

BlockingQueue &Replace::outputQueue() {
  return destination;
}
