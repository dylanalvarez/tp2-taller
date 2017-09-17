#ifndef TP2_TALLER_MATCH_H
#define TP2_TALLER_MATCH_H

#include <string>
#include "Thread.h"
#include "BlockingQueue.h"

class Match : public Thread {
public:
  Match(const std::string &regex, BlockingQueue &source);

  /*
   * Outputs only lines that match its regex (ECMAScript) at least once to its
   * destination queue, until an endOfFile Line is found
   */
  void run() override;

  void addLogger(Logger *logger) override;

  BlockingQueue &outputQueue() override;

private:
  std::string regex;
  BlockingQueue &source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_MATCH_H
