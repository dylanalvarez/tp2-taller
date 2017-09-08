#include <string>
#include <stdexcept>
#include "ArgumentHandler.h"

ArgumentHandler::ArgumentHandler(int argc, char **argv) :
        argc(argc), argv(argv), divideByDoubleColon(false) {
    this->currentArgument = 0;
}

std::string ArgumentHandler::_nextArgument() {
    this->currentArgument++;
    if (this->currentArgument >= this->argc) { throw std::exception(); }
    return std::string(argv[this->currentArgument]);
}

std::string ArgumentHandler::nextArgument() {
    std::string argument = this->_nextArgument();
    if (this->divideByDoubleColon) {
        while (this->thereIsNextArgument() &&
               std::string(argv[this->currentArgument + 1]) != "::") {
            argument += this->nextArgument();
        }
        this->currentArgument++;
    }
    return argument;
}

bool ArgumentHandler::thereIsNextArgument() {
    return this->currentArgument < this->argc - 1;
}
