#ifndef AESCRYPT_APP_H
#define AESCRYPT_APP_H

#include <string>
#include <vector>

using std::string;

class AESCryptApp {
public:
    void encrypt_file( 
        string& in_path, 
        string& out_path, 
        string& password
    );
    void decrypt_file(
        string& in_path,
        string& out_path,
        string& password
    );
};

#endif /* AESCRYPT_APP_H */