#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "aescrypt/app.h"
#include "aescrypt/utils.h"

using std::cout;
using std::string;
using std::cerr;

int main(int argc, char* argv[]) {
    try {
        if (argc == 1) {
            Utils::wellcome();
            return 0;
        }

        bool encrypt = false, decrypt = false;
        string in, out, pwd;

        for (int argument = 1; argument < argc; ++argument) {
            string arg = argv[argument];

            if (arg == "-e")
                encrypt = true;

            else if (arg == "-d")
                decrypt = true;

            else if (arg == "-i" && argument+1<argc)
                in  = argv[++argument];

            else if (arg == "-o" && argument+1<argc)
                out = argv[++argument];

            else if (arg == "-p" && argument+1<argc)
                pwd = argv[++argument];

            else if (arg == "-h") {
                cerr << "Usage: " << argv[0]
                          << " -e|-d -i <in> -o <out> -p <pwd>\n";
                return 0;
            }
            else {
                cerr << "Unknown option: " << arg << '\n';
                return 1;
            }
        }

        if (in.empty() || out.empty() || pwd.empty())
            return 1;

        if (encrypt == decrypt)
            return 1;



        AESCryptApp app;

        if (encrypt)
            app.encrypt_file(in, out, pwd);
        else
            app.decrypt_file(in, out, pwd);

        cout << "Operation completed.\n";
        return 0;
    }

    catch (const std::exception& e) {
        cerr << "aescrypt: fatal error: " << e.what() << '\n';
        return 1;
    }

    catch (...) {
        cerr << "aescrypt: unknown fatal error\n";
        return 1;
    }
}