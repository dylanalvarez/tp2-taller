#ifndef TP2_TALLER_MATCH_H
#define TP2_TALLER_MATCH_H


#include "Thread.h"

class Match : public Thread {
public:
  explicit Match(const std::string &regex);

  void run() override;

private:
  std::string regex;
};


#endif //TP2_TALLER_MATCH_H
