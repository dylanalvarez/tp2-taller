#include <iostream>

#define SUCCESS 0
#define ERROR 1

int main(int argc, char *argv[]) {
    if (argc < 2) { return ERROR; }
    int current = 1;

    bool debug = std::string(argv[current]) == "--debug";
    if (debug) {
        current++;
        std::cout << "debug mode!" << std::endl;
    }

    if (current >= argc) { return ERROR; }
    if (std::string(argv[current]) == "--input") {
        current++;
        if (current >= argc) { return ERROR; }
        std::cout << "read from file " << argv[current] << std::endl;
        current++;
    }

    if (current >= argc) { return ERROR; }
    if (std::string(argv[current]) == "--output") {
        current++;
        if (current >= argc) { return ERROR; }
        std::cout << "write to file " << argv[current] << std::endl;
        current++;
    }

    std::cout << "rest of parameters:" << std::endl;

    while(current < argc){
        std::cout << argv[current] << std::endl;
        current++;
    }

    std::cout << "success!" << std::endl;
    return SUCCESS;
}
