#include "caesarcipher.h"

using namespace std;

CaesarCipher::CaesarCipher(string theInput, int theShift) : inputString(theInput), shift(theShift), changed(true) {}
CaesarCipher::CaesarCipher():inputString(""), shift(0), changed(true) {}

CaesarCipher::~CaesarCipher() {}

string CaesarCipher::getEncryptedString() {
    //if output string is null or has changed, figure out string,
    string result = "";

    if (outputString == "" || changed == true) {
        // traverse text
        for (int i=0;i<inputString.length();i++)
        {
            if (inputString[i] == ' ') {
                result += ' ';
            }
            else if (isupper(inputString[i]))
                result += char(int(inputString[i]+shift-65)%26 + 65);

            // Encrypt Lowercase letters
            else
                result += char(int(inputString[i]+shift-97)%26 +97);
         }
        outputString = result;
        // Return the resulting string
        return result;
    } else {
        //if output string is not null, return outputString
        return outputString;
    }
}

string CaesarCipher::getDecryptedString() {
    //if output string is null or has changed, figure out string,
    string result = "";

    if (outputString == "" || changed == true) {
        // traverse text
        for (int i=0;i<inputString.length();i++)
        {
            if (inputString[i] == ' ') {
                result += ' ';
            }
            else if (isupper(inputString[i]))
                result += char(int(inputString[i]-shift-65)%26 + 65);

            // Encrypt Lowercase letters
            else
                result += char(int(inputString[i]-shift-97)%26 +97);
         }
        outputString = result;
        // Return the resulting string
        return result;
    } else {
        //if output string is not null, return outputString
        return outputString;
    }
}

void CaesarCipher::setInputString(string theInput) {
    inputString = theInput;
}

void CaesarCipher::setShift(int theShift) {
    shift = theShift;
}


