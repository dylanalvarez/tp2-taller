#ifndef TP2_TALLER_FILE_READER_H
#define TP2_TALLER_FILE_READER_H


#include "Thread.h"
#include "BlockingQueue.h"

class FileReader : public Thread {
public:
  explicit FileReader(std::istream *source);

  /*
   * Outputs every line in source to destination
   */
  void run() override;

  BlockingQueue &outputQueue() override;

private:
  std::istream *source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_FILE_READER_H
