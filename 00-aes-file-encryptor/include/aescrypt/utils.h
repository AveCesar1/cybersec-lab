#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using std::cout;
using std::string;

class Utils {
public:
    static void wellcome() {
        string banner = R"(
  /$$$$$$  /$$$$$$$$  /$$$$$$   /$$$$$$                                  /$$    
 /$$__  $$| $$_____/ /$$__  $$ /$$__  $$                                | $$    
| $$  \ $$| $$      | $$  \__/| $$  \__/  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$  
| $$$$$$$$| $$$$$   |  $$$$$$ | $$       /$$__  $$| $$  | $$ /$$__  $$|_  $$_/  
| $$__  $$| $$__/    \____  $$| $$      | $$  \__/| $$  | $$| $$  \ $$  | $$    
| $$  | $$| $$       /$$  \ $$| $$    $$| $$      | $$  | $$| $$  | $$  | $$ /$$
| $$  | $$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/
|__/  |__/|________/ \______/  \______/ |__/       \____  $$| $$____/    \___/  
                                                   /$$  | $$| $$                
                                                  |  $$$$$$/| $$                
                                                   \______/ |__/                
                                                
        )";
        cout << banner << std::endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        cout << "A simple AES file encryptor/decryptor for Unix\n\n";

        cout << "Usage: aescrypt -e|-d <in> -o <out> -p <pwd>\n";

        cout << "  -e: encrypt the file\n"
             << "  -d: decrypt the file\n"
             << "  <in>: file path (both input and output)\n"
             << "  -o <out>: output file path\n"
             << "  -p <pwd>: password\n";

        cout << "\n\n\n";
    }
};

#endif /* UTILS_H */