#ifndef TP2_TALLER_FILE_WRITER_H
#define TP2_TALLER_FILE_WRITER_H


#include "Thread.h"
#include "BlockingQueue.h"

class FileWriter : public Thread {
public:
  FileWriter(BlockingQueue &source, std::ostream *destination);

  void run() override;

  BlockingQueue &outputQueue() override;

private:
  BlockingQueue &source;
  std::ostream *destination;
};

#endif //TP2_TALLER_FILE_WRITER_H
