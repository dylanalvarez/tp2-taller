#include <istream>
#include <string>
#include "FileReader.h"

FileReader::FileReader(std::istream *source) :
  source(source),
  destination(BlockingQueue()) {}

void FileReader::run() {
  std::string line;
  while (*source >> line) {
    destination.push(line);
  }
  destination.push("");
}

BlockingQueue &FileReader::outputQueue() {
  return destination;
}
