#ifndef TP2_TALLER_REPLACE_H
#define TP2_TALLER_REPLACE_H


#include "Thread.h"

class Replace : public Thread {
public:
  explicit Replace(std::string regex, std::string replacement);

  void run() override;

private:
  std::string regex;
  std::string replacement;
};


#endif //TP2_TALLER_REPLACE_H
