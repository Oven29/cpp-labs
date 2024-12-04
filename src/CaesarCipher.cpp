#include "CaesarCipher.h"
#include <cctype>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace {

std::vector<std::string> splitWords(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (char c : text) {
        if (std::isalnum(c)) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int calculateWordSum(const std::string& word) {
    int sum = 0;
    for (char c : word) {
        sum += static_cast<unsigned char>(c);
    }
    return sum;
}

}  // namespace

namespace CaesarCipher {

char* Encode(const char* text, const char* notebook) {
    std::vector<std::string> words = splitWords(notebook);
    if (words.empty()) {
        std::cerr << "Error: Notebook is empty!\n";
        return nullptr;
    }

    std::string result;
    size_t wordIndex = 0;

    for (const char* ptr = text; *ptr != '\0'; ++ptr) {
        int charCode = static_cast<unsigned char>(*ptr);
        int wordSum = calculateWordSum(words[wordIndex]);

        int newCharCode = (charCode + wordSum) % 128;
        result += static_cast<char>(newCharCode);

        wordIndex = (wordIndex + 1) % words.size();
    }

    char* encoded = new char[result.size() + 1];
    std::copy(result.begin(), result.end(), encoded);
    encoded[result.size()] = '\0';
    return encoded;
}

char* Decode(const char* encodedText, const char* notebook) {
    std::vector<std::string> words = splitWords(notebook);
    if (words.empty()) {
        std::cerr << "Error: Notebook is empty!\n";
        return nullptr;
    }

    std::string result;
    size_t wordIndex = 0;

    for (const char* ptr = encodedText; *ptr != '\0'; ++ptr) {
        int charCode = static_cast<unsigned char>(*ptr);
        int wordSum = calculateWordSum(words[wordIndex]);

        int newCharCode = (charCode - wordSum + 128) % 128;
        result += static_cast<char>(newCharCode);

        wordIndex = (wordIndex + 1) % words.size();
    }

    char* decoded = new char[result.size() + 1];
    std::copy(result.begin(), result.end(), decoded);
    decoded[result.size()] = '\0';
    return decoded;
}

void GenerateStatistics(const char* originalText, const char* encodedText, const char* notebook) {
    std::map<char, int> frequency;
    std::map<char, std::set<int>> variants;
    std::vector<std::string> words = splitWords(notebook);
    size_t wordIndex = 0;

    for (const char* ptr = originalText; *ptr != '\0'; ++ptr) {
        char originalChar = *ptr;
        int charCode = static_cast<unsigned char>(originalChar);

        frequency[originalChar]++;

        int wordSum = calculateWordSum(words[wordIndex]);
        int encodedCharCode = (charCode + wordSum) % 128;

        variants[originalChar].insert(encodedCharCode);

        wordIndex = (wordIndex + 1) % words.size();
    }

    std::cout << "Statistics:\n";
    std::cout << "Symbol\tASCII Code\tFrequency\tVariants\n";
    for (const auto& entry : frequency) {
        char symbol = entry.first;
        int asciiCode = static_cast<unsigned char>(symbol);
        int freq = entry.second;
        int variantCount = variants[symbol].size();

        std::cout << symbol << "\t" << asciiCode << "\t" << freq << "\t" << variantCount << "\n";
    }

    std::cout << "Notebook size (words): " << words.size() << "\n";
    std::cout << "Original text length: " << std::strlen(originalText) << "\n";
}

}  // namespace CaesarCipher
