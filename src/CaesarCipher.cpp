#include "CaesarCipher.h"
#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "collections/Vector.h"

namespace {

const int kMod = 128;

const int kColWeight = 15;

[[nodiscard]] int GetASCII(char c) {
    return static_cast<int>(c);
}

[[nodiscard]] char GetCharByASCII(int asciiCode) {
    return static_cast<char>(asciiCode);
}

[[nodiscard]] bool IsSymbol(char c) {
    return std::ispunct(c) == 0 && c != ' ' && c != '\n';
}

// [[nodiscard]] Vector::VecInt GetNotebookkeys(const char* notebook) {
    
//     return keys;
// }

[[nodiscard]] char* ProccessText(const char* text, const char* notebook, bool encode) {
    Vector::VecInt keys = Vector::CreateVector();
    Vector::PushBack(keys, 0);

    for (size_t i = 0; i < std::strlen(notebook); i++) {
        if (IsSymbol(notebook[i])) {
            int lastItem = Vector::GetElement(keys, keys.size - 1);
            keys.vector[i] = lastItem + GetASCII(notebook[i]);
        } else {
            Vector::PushBack(keys, 0);
        }
    }

    const size_t textLength = std::strlen(text);
    char* result = new char[textLength + 1];

    for (size_t i = 0; i <= textLength; i++) {
        int key = Vector::GetElement(keys, i % keys.size);
        int asciiCode = GetASCII(text[i]);
        int asciiValue = (encode ? (asciiCode + key) % kMod + 1 : (asciiCode - key - 1 + kMod) % kMod);
        result[i] = GetCharByASCII(asciiValue);
    }

    Vector::DeleteVector(keys);

    result[textLength] = '\0';

    return result;
}

}  // namespace

namespace CaesarCipher {

char* Encode(const char* text, const char* notebook) {
    return ProccessText(text, notebook, true);
}

char* Decode(const char* text, const char* notebook) {
    return ProccessText(text, notebook, false);
}

void GenerateStatistics(const char* originalText, const char* encodedText, const char* notebook) {
    int asciiFrequency[kMod] = {0};
    int uniqueEncodings[kMod] = {0};
    size_t originalTextLength = std::strlen(originalText);
    size_t encodedTextLength = std::strlen(encodedText);

    for (size_t i = 0; i <= originalTextLength; i++) {
        int symbol = GetASCII(originalText[i]) % kMod;
        asciiFrequency[symbol]++;
    }

    char* decodeText = Decode(encodedText, notebook);
 
    for (size_t i = 0; i <= encodedTextLength; i++) {
        int encodeSymbol = GetASCII(encodedText[i]) % kMod;
        int decodeSymbol = GetASCII(decodeText[i]) % kMod;

        for (size_t j = 0; j <= encodedTextLength; j++) {
            if (encodeSymbol == encodedText[j] && GetASCII(encodedText[j] != decodeSymbol)) {
                uniqueEncodings[encodeSymbol]++;
            }
        }
    }

    std::cout << "Origin text length: " << originalTextLength << std::endl;

    // Vector::VecInt keys = GetNotebookkeys(notebook);
    // std::cout << "Notebook words: " << keys.size << std::endl;
    // Vector::DeleteVector(keys);

    std::cout << std::setw(kColWeight) << "Symbol " << std::setw(kColWeight) << "ASCII Code " << std::setw(kColWeight) << "Frequency "
              << std::setw(kColWeight) << "Unique Encodings " << std::endl;

    for (int i = 0; i < kMod; i++) {
        if (asciiFrequency[i] > 0 && i >= 32) {
            std::cout << std::setw(kColWeight) << GetCharByASCII(i) << std::setw(kColWeight) << i << std::setw(kColWeight)
                      << asciiFrequency[i] << std::setw(kColWeight) << uniqueEncodings[i] + 1 << std::endl;
        }
    }
}

}  // namespace CaesarCipher
