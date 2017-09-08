#include <iostream>
#include "ArgumentHandler.h"
#include "Application.h"

#define SUCCESS 0
#define ERROR 1

int main(int argc, char *argv[]) {
  try {
    Application(ArgumentHandler(argc, argv)).run();
  } catch (std::exception &e) {
    return ERROR;
  }
  return SUCCESS;
}
