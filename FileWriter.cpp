#include <iostream>
#include <string>
#include "FileWriter.h"

FileWriter::FileWriter(BlockingQueue &source, std::ostream *destination) :
  source(source),
  destination(destination) {}

void FileWriter::run() {
  Line line = source.pop();
  while (!line.isEndOfFile()) {
    *destination << line.getContent() << std::endl;
    line = source.pop();
  }
}

BlockingQueue &FileWriter::outputQueue() {
  throw std::exception();
}
