#include "Line.h"
#include <string>

Line::Line() : endOfFile(true) {}

Line::Line(std::string content) : endOfFile(false), content(content) {}

bool Line::isEndOfFile() {
  return endOfFile;
}

std::string Line::getContent() {
  return content;
}
