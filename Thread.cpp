#include "Thread.h"

void Thread::start() {
  thread = std::thread(&Thread::run, this);
}

void Thread::join() {
  thread.join();
}

Thread::Thread(Thread &&other) noexcept {
  this->thread = std::move(other.thread);
  this->logger = other.logger;
}

Thread &Thread::operator=(Thread &&other) noexcept {
  this->thread = std::move(other.thread);
  return *this;
}

void Thread::addLogger(Logger *logger) {
  this->logger = logger;
}

void
Thread::_log(const std::string &input, const std::string &output) {
  this->logger->log(this->processID, input + " -> " + output);
}

Thread::Thread() :
  logger(nullptr) {}
