#include <istream>
#include <string>
#include "FileReader.h"

FileReader::FileReader(std::istream *source) :
  source(source) {}

void FileReader::run() {
  std::string content;
  while (*source >> content) {
    destination.push(Line(content));
  }
  destination.push(Line());
}

BlockingQueue &FileReader::outputQueue() {
  return destination;
}
