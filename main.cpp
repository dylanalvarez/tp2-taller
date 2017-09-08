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

        std::cout << "rest of parameters:" << std::endl;
    } catch (
            std::exception &e) { // TODO: use custom exception and print error
        // to stderr
        return ERROR;
    }

    while (argumentHandler.thereIsNextArgument()) {
        std::cout << currentArgument << std::endl;
        currentArgument = argumentHandler.nextArgument();
    }

    std::cout << "success!" << std::endl;
    return SUCCESS;
}
