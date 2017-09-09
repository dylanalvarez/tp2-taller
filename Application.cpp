#include <iostream>
#include <fstream>
#include "Application.h"
#include "Echo.h"
#include "Match.h"
#include "Replace.h"

void Application::_setOptions() {
  std::string currentArgument = argumentHandler.nextArgument();

  if (currentArgument == "--debug") {
    debug = true;
    currentArgument = argumentHandler.nextArgument();
  }

  if (currentArgument == "--input") {
    this->source = new std::ifstream(argumentHandler.nextArgument());
    if (!*source) { throw std::exception(); }
    currentArgument = argumentHandler.nextArgument();
  }

  if (currentArgument == "--output") {
    this->destination = new std::ofstream(argumentHandler.nextArgument());
    if (!*destination) { throw std::exception(); }
    currentArgument = argumentHandler.nextArgument();
  }

  argumentHandler.rewind();
}

void Application::_prepareThreads() {
  while (argumentHandler.thereIsNextArgument()) {
    std::string currentArgument = argumentHandler.nextArgument();

    if (currentArgument == "echo") {
      threads.push_back(new Echo());
    } else if (currentArgument == "match") {
      threads.push_back(new Match(argumentHandler.nextArgument()));
    } else if (currentArgument == "replace") {
      threads.push_back(new Replace(argumentHandler.nextArgument(),
                                    argumentHandler.nextArgument()));
    } else {
      throw std::exception();
    }

    if (argumentHandler.thereIsNextArgument() &&
        argumentHandler.nextArgument() != "::") {
      throw std::exception();
    }
  }
}

void Application::_startThreads() {
  for (auto &thread : threads) {
    thread->start();
  }
}

void Application::_joinThreads() {
  for (auto &thread : threads) {
    thread->join();
    delete thread;
  }
}

Application::Application(int argc, char *argv[]) :
  debug(false),
  argumentHandler(ArgumentHandler(argc, argv)),
  source(&std::cin),
  destination(&std::cout) {
  _setOptions();
  _prepareThreads();
  _startThreads();
  _joinThreads();
}

Application::~Application() {
  if (this->source != &std::cin) {
    auto *to_be_closed = (std::ifstream *) this->source;
    to_be_closed->close();
    delete this->source;
  }
  if (this->destination != &std::cout) {
    auto *to_be_closed = (std::ofstream *) this->destination;
    to_be_closed->close();
    delete this->destination;
  }
}
