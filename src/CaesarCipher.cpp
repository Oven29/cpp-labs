#include "CaesarCipher.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include "collections/Vector.h"

namespace {

const int kMod = 128;

[[nodiscard]] int GetASCII(char c) {
    return static_cast<int>(c);
}

[[nodiscard]] char GetCharByASCII(int asciiCode) {
    return static_cast<char>(asciiCode);
}

[[nodiscard]] bool IsSymbol(char c) {
    return std::ispunct(c) == 0 && c != ' ' && c != '\n';
}

[[nodiscard]] Vector::VecInt GetNotebookkeys(const char* notebook) {
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

    return keys;
}

[[nodiscard]] char* ProccessText(const char* text, const char* notebook, bool encode) {
    Vector::VecInt keys = GetNotebookkeys(notebook);

    std::cout << notebook << std::endl;
    Vector::PrintVector(keys);

    const size_t textLength = std::strlen(text);
    char* result = new char[textLength + 1];

    for (size_t i = 0; i < textLength; i++) {
        if (IsSymbol(text[i])) {
            int key = Vector::GetElement(keys, i % keys.size);
            int asciiCode = GetASCII(text[i]);
            int asciiValue = (encode ? (asciiCode + key) % kMod : (key - asciiCode + kMod) % kMod);
            std::cout << asciiCode << ':' << key << ':' << asciiValue << ' ';
            result[i] = GetCharByASCII(asciiValue);
        } else {
            result[i] = text[i];
        }
    }
    std::cout << std::endl;

    result[textLength - 1] = '\0';

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
    std::cout << "Original:" << originalText << std::endl << std::endl;
    std::cout << "Encode:" << encodedText << std::endl << std::endl;
    std::cout << "Notebook:" << notebook << std::endl << std::endl;
}

}  // namespace CaesarCipher
