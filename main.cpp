#include <iostream>
#include "Application.h"

#define SUCCESS 0
#define ERROR 1

int main(int argc, char *argv[]) {
  try {
    Application(argc, argv)();
  } catch (std::exception &e) {
    return ERROR;
  }
  return SUCCESS;
}
