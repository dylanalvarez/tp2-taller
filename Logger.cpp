#include <iostream>
#include <string>
#include <vector>
#include "Logger.h"

void Logger::log(const std::string &processID, const std::string &log) {
  std::lock_guard<std::mutex> lock(mutex);
  processLogs[processID].push_back(log);
}

std::string Logger::getProcessID(std::string processName) {
  int processNumber = 1;
  while (processLogs.count(processName + std::to_string(processNumber))) {
    processNumber += 1;
  }
  std::string processID = processName + std::to_string(processNumber);
  processLogs[processID] = std::vector<std::string>(
    1, "(" + std::to_string(processLogs.size() + 1) + ") " + processID);
  processIDs.push_back(processID);
  return processID;
}

Logger::~Logger() {
  bool first = true;
  for (auto &processID : processIDs) {
    for (auto &log : processLogs[processID]) {
      if(first){
        first = false;
      } else {
        std::cerr << std::endl;
      }
      std::cerr << log << std::endl;
    }
  }
}
