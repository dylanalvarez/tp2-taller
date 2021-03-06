#ifndef TP2_TALLER_REPLACE_H
#define TP2_TALLER_REPLACE_H

#include <string>
#include "Thread.h"
#include "BlockingQueue.h"

class Replace : public Thread {
public:
  Replace(const std::string &regex, const std::string &replacement,
          BlockingQueue &source);

  /*
   * Outputs lines with their content replaced by replacement, where they match
   * regex (ECMAScript) to its destination queue, until an endOfFile Line
   * is found
   */
  void run() override;

  void addLogger(Logger *logger) override;

  BlockingQueue &outputQueue() override;

private:
  std::string regex;
  std::string replacement;
  BlockingQueue &source;
  BlockingQueue destination;
};


#endif //TP2_TALLER_REPLACE_H
