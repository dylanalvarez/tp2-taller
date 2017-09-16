#include <iostream>
#include <utility>
#include <string>
#include <regex>
#include "Match.h"

void Match::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    if (std::regex_search(line.getContent(), regex)){
      destination.push(line);
    }
    line = source.pop();
  }
  destination.push(Line());
}

BlockingQueue &Match::outputQueue() {
  return destination;
}

Match::Match(const std::string& regex,
             BlockingQueue& source) :
  regex(std::regex(regex, std::regex::ECMAScript)),
  source(source) {}
