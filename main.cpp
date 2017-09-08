#include <iostream>
#include "ArgumentHandler.h"
#include <string>

#define SUCCESS 0
#define ERROR 1

int main(int argc, char *argv[]) {
    ArgumentHandler argumentHandler(argc, argv);
    std::string currentArgument;
    try {
        currentArgument = argumentHandler.nextArgument();
        if (currentArgument == "--debug") {
            std::cout << "debug mode!" << std::endl;
            currentArgument = argumentHandler.nextArgument();
        }

        if (currentArgument == "--input") {
            std::cout << "read from file " << argumentHandler.nextArgument()
                      << std::endl;
            currentArgument = argumentHandler.nextArgument();
        }

        if (currentArgument == "--output") {
            std::cout << "write to file " << argumentHandler.nextArgument()
                      << std::endl;
            currentArgument = argumentHandler.nextArgument();
        }

        argumentHandler.rewind();
        std::cout << "rest of parameters:" << std::endl;

        while (argumentHandler.thereIsNextArgument()) {
            currentArgument = argumentHandler.nextArgument();
            if (currentArgument == "echo") {
                std::cout << "echo!" << std::endl;
            } else if (currentArgument == "match") {
                std::string regex = argumentHandler.nextArgument();
                std::cout << "match " << regex << "!" << std::endl;
            } else if (currentArgument == "replace") {
                std::string pattern = argumentHandler.nextArgument();
                std::string replacement = argumentHandler.nextArgument();
                std::cout << "replace " << pattern << " with " << replacement
                          << "!" << std::endl;
            } else {
                return ERROR;
            }
            if (argumentHandler.thereIsNextArgument() &&
                argumentHandler.nextArgument() != "::") {
                return ERROR;
            }
        }
    } catch (std::exception &e) {
        return ERROR;
    }

    std::cout << "success!" << std::endl;
    return SUCCESS;
}
