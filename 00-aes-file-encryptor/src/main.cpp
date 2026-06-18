#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "aescrypt/app.h"

int main(int argc, char* argv[]) {
    try {
        AESCryptApp application;
        return application.run(argc, argv);
    }
    catch (const std::exception& e) {
        std::cerr << "aescrypt: fatal error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "aescrypt: unknown fatal error\n";
        return EXIT_FAILURE;
    }
}