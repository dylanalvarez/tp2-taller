#ifndef TP2_TALLER_REPLACE_H
#define TP2_TALLER_REPLACE_H

#include <string>
#include "Thread.h"
#include "BlockingQueue.h"

class Replace : public Thread {
public:
  Replace(const std::string& regex, const std::string& replacement,
          BlockingQueue& source);

  void run() override;

  BlockingQueue& outputQueue() override;

private:
  std::string regex;
  std::string replacement;
  BlockingQueue& source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_REPLACE_H
