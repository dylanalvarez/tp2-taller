#include <iostream>
#include <fstream>
#include <string>
#include "Application.h"
#include "Echo.h"

void Application::_setOptions(){
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

void Application::_run(){
  while (argumentHandler.thereIsNextArgument()) {
    std::string currentArgument = argumentHandler.nextArgument();

    if (currentArgument == "echo") {
      Echo echo = Echo();
      echo.start();
      echo.join();
    } else if (currentArgument == "match") {
      std::string regex = argumentHandler.nextArgument();
      std::cout << "match " << regex << "!" << std::endl;
    } else if (currentArgument == "replace") {
      std::string pattern = argumentHandler.nextArgument();
      std::string replacement = argumentHandler.nextArgument();
      std::cout << "replace " << pattern << " with " << replacement
                << "!" << std::endl;
    } else {
      throw std::exception();
    }

    if (argumentHandler.thereIsNextArgument() &&
        argumentHandler.nextArgument() != "::") {
      throw std::exception();
    }
  }
}

Application::Application(int argc, char *argv[]) :
  debug(false),
  argumentHandler(ArgumentHandler(argc, argv)),
  source(&std::cin),
  destination(&std::cout) {
  _setOptions();
  _run();
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
