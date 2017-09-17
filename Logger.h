#ifndef TP2_TALLER_LOGGER_H
#define TP2_TALLER_LOGGER_H

#include <string>
#include <vector>
#include <map>
#include <mutex>

/*
 * It handles output of application log to std::cerr
 */
class Logger {
public:
  /*
   * The process ID is needed to identify which thread invokes log entry later
   */
  std::string getProcessID(std::string processName);

  void log(const std::string &processID, const std::string &log);

  /*
   * The information contained within this class is outputted into std::cerr
   */
  ~Logger();

private:
  std::map<std::string, std::vector<std::string>> processLogs;
  std::vector<std::string> processIDs;
  std::mutex mutex;
};


#endif //TP2_TALLER_LOGGER_H
