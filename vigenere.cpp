#include "vigenere.h"

Vigenere::Vigenere() : inputString(""), key("") {}
Vigenere::Vigenere(string theInputString, string theKey) : inputString(theInputString), key(theKey) {}

void Vigenere::setKey(string newKey) {
    key = newKey;
}

string Vigenere::getEncryptedString() {
    string result = "";
    locale loc;
    string upperKey = "";
    for (std::string::size_type i=0; i < key.length(); ++i)
        upperKey =+ toupper(key[i],loc);

    if (outputString == "" || changed == true) {
        // traverse text
        for (int i=0;i<inputString.length();i++)
        {
            if (inputString[i] == ' ') {
                result += ' ';
            }
            else if (isupper(inputString[i])) {
                //result += char(int(inputString[i]+shift-65)%26 + 65);

            // Encrypt Lowercase letters
            }
            else {
                result+='.';
                //result += char(int(inputString[i]+shift-97)%26 +97);
            }
         }
        outputString = result;
        // Return the resulting string
        return result;
    } else {
        //if output string is not null, return outputString
        return outputString;
    }
}

void Vigenere::setInputString(string newString){
    inputString = newString;
}
