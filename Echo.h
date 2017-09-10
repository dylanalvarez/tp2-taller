#ifndef TP2_TALLER_ECHO_H
#define TP2_TALLER_ECHO_H


#include "Thread.h"
#include "BlockingQueue.h"

class Echo : public Thread {
public:
  explicit Echo(BlockingQueue& source);

  void run() override;

  BlockingQueue& outputQueue() override;

private:
  BlockingQueue& source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_ECHO_H
