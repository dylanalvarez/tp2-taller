#ifndef TP2_TALLER_LINE_H
#define TP2_TALLER_LINE_H

#include <string>

/*
 * It represents a line in a file, it can have either content or represent
 * the end of file.
 */
class Line {
public:
  Line();

  explicit Line(std::string content);

  bool isEndOfFile();

  std::string getContent();

private:
  bool endOfFile;
  std::string content;
};


#endif //TP2_TALLER_LINE_H
