#ifndef TP2_TALLER_MATCH_H
#define TP2_TALLER_MATCH_H

#include <string>
#include "Thread.h"
#include "BlockingQueue.h"

class Match : public Thread {
public:
  Match(const std::string& regex, BlockingQueue& source);

  void run() override;

  BlockingQueue& outputQueue() override;

private:
  std::string regex;
  BlockingQueue& source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_MATCH_H
