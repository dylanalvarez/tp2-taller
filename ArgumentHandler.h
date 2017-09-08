#ifndef TP2_TALLER_ARGUMENTHANDLER_H
#define TP2_TALLER_ARGUMENTHANDLER_H

#include <string>

class ArgumentHandler {
public:
    ArgumentHandler(int argc, char **argv);

    std::string nextArgument();

    bool thereIsNextArgument();

private:
    std::string _nextArgument();

    int argc;
    int currentArgument;
    char **argv;
    bool divideByDoubleColon;
};


#endif //TP2_TALLER_ARGUMENTHANDLER_H
