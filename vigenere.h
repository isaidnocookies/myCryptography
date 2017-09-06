#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <locale>

using namespace std;

class Vigenere {
private:
    string inputString;
    string outputString;
    string key;
    bool changed;

public:
    Vigenere();
    Vigenere(string, string);

    ~Vigenere();

    void setKey(string);
    string getEncryptedString();
    void setInputString(string);
};


#endif // VIGENERE_H
