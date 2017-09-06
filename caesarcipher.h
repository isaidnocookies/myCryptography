#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

using namespace std;

class CaesarCipher {
private:
    string inputString;
    string outputString;
    int shift;
    bool changed;

public:
    CaesarCipher();
    CaesarCipher(string, int);

    ~CaesarCipher();

    void setShift(int);
    string getEncryptedString();
    string getDecryptedString();
    void setInputString(string);
};


#endif // CAESARCIPHER_H
