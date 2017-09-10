#include <iostream>
#include <string>
#include "FileWriter.h"

FileWriter::FileWriter(BlockingQueue& source, std::ostream *destination) :
  source(source),
  destination(destination) {}

void FileWriter::run() {
  std::string line = source.pop();
  while (!line.empty()) {
    *destination << line << std::endl;
    line = source.pop();
  }
}

BlockingQueue &FileWriter::outputQueue() {
  throw std::exception();
}
