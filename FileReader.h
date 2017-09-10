#ifndef TP2_TALLER_FILEREADER_H
#define TP2_TALLER_FILEREADER_H


#include "Thread.h"
#include "BlockingQueue.h"

class FileReader : public Thread {
public:
  explicit FileReader(std::istream* source);

  void run() override;

  BlockingQueue& outputQueue() override;

private:
  std::istream *source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_FILEREADER_H