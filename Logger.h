#ifndef TP2_TALLER_LOGGER_H
#define TP2_TALLER_LOGGER_H

#include <string>
#include <vector>
#include <map>
#include <mutex>

class Logger {
public:
  std::string getProcessID(std::string processName);

  void log(const std::string &processID, const std::string &log);

  ~Logger();

private:
  std::map<std::string, std::vector<std::string>> processLogs;
  std::vector<std::string> processIDs;
  std::mutex mutex;
};


#endif //TP2_TALLER_LOGGER_H
