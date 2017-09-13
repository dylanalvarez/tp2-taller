#include "Line.h"
#include <string>

Line::Line() : endOfFile(true) {}

Line::Line(std::string content) : endOfFile(true), content(content) {}

bool Line::isEndOfFile() {
  return endOfFile;
}

std::string Line::getContent() {
  return content;
}
