#ifndef TP2_TALLER_ECHO_H
#define TP2_TALLER_ECHO_H


#include "Thread.h"
#include "BlockingQueue.h"

class Echo : public Thread {
public:
  explicit Echo(BlockingQueue &source);

  /*
   * Outputs everything queued in the source queue it references to its
   * destination queue, until an endOfFile Line is found
   */
  void run() override;

  void addLogger(Logger *logger) override;

  BlockingQueue &outputQueue() override;

private:
  BlockingQueue &source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_ECHO_H
