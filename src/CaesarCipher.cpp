#include "CaesarCipher.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include "collections/Vector.h"

namespace {

// Вспомогательная функция: проверка, является ли символ частью слова
bool IsWordChar(char c) {
    return std::isalnum(static_cast<unsigned char>(c));
}

// Вспомогательная функция: подсчёт суммы ASCII-кодов символов в слове
int CalculateWordShift(const char* word) {
    int sum = 0;
    for (size_t i = 0; word[i] != '\0'; ++i) {
        sum += static_cast<unsigned char>(word[i]);
    }
    return sum;
}

// Вспомогательная функция: извлечение слов из кодового блокнота в VecChar
void ExtractWords(const char* notebook, Vector::VecChar& words) {
    Vector::VecChar currentWord = Vector::CreateVector();

    for (size_t i = 0; notebook[i] != '\0'; ++i) {
        if (IsWordChar(notebook[i])) {
            Vector::PushBack(currentWord, notebook[i]);
        } else if (currentWord.size > 0) {
            Vector::PushBack(currentWord, '\0');
            for (size_t j = 0; j < currentWord.size; ++j) {
                Vector::PushBack(words, Vector::GetElement(currentWord, j));
            }
            currentWord.size = 0;
        }
    }

    if (currentWord.size > 0) {
        Vector::PushBack(currentWord, '\0');
        for (size_t j = 0; j < currentWord.size; ++j) {
            Vector::PushBack(words, Vector::GetElement(currentWord, j));
        }
    }

    Vector::DeleteVector(currentWord);
}

// Вспомогательная функция: выполнение кодирования или декодирования
char* ProcessText(const char* text, const char* notebook, bool encode) {
    Vector::VecChar words = Vector::CreateVector();
    ExtractWords(notebook, words);

    size_t wordIndex = 0;
    size_t numWords = words.size;

    size_t textLen = std::strlen(text);
    char* result = new char[textLen + 1];

    for (size_t i = 0; i < textLen; ++i) {
        if (numWords == 0 || !IsWordChar(text[i])) {
            result[i] = text[i];
            continue;
        }

        const char* currentWord = &Vector::GetElement(words, wordIndex);
        int shift = CalculateWordShift(currentWord);
        result[i] = static_cast<char>(encode ? (text[i] + shift) % 128 : (text[i] - shift + 128) % 128);

        wordIndex += std::strlen(currentWord) + 1;
        if (wordIndex >= numWords) {
            wordIndex = 0;
        }
    }

    result[textLen] = '\0';
    Vector::DeleteVector(words);
    return result;
}

}  // namespace

namespace CaesarCipher {

char* Encode(const char* text, const char* notebook) {
    return ProcessText(text, notebook, true);
}

char* Decode(const char* encodedText, const char* notebook) {
    return ProcessText(encodedText, notebook, false);
}

void GenerateStatistics(const char* originalText, const char* encodedText, const char* notebook) {
    size_t textLen = std::strlen(originalText);

    int charCounts[128] = {0};
    int uniqueEncodings[128] = {0};

    for (size_t i = 0; i < textLen; ++i) {
        charCounts[static_cast<unsigned char>(originalText[i])]++;
    }

    for (int i = 0; i < 128; ++i) {
        if (charCounts[i] > 0) {
            for (size_t j = 0; j < textLen; ++j) {
                if (originalText[j] == i) {
                    uniqueEncodings[i]++;
                }
            }
        }
    }

    std::cout << "Keys length\t" <<  std::strlen(notebook) << std::endl;
    std::cout << "Text length\t" << textLen << std::endl;
    std::cout << "Char\tASCII\tCount" << std::endl;
    for (int i = 0; i < 128; ++i) {
        if (charCounts[i] > 0) {
            std::cout << static_cast<char>(i) << "\t" << i << "\t" << charCounts[i] << "\t" << uniqueEncodings[i] << std::endl;
        }
    }
}

}  // namespace CaesarCipher
