#pragma once
#include <cstddef>

namespace CaesarCipher {
char* Encode(const char* text, const char* notebook);
char* Decode(const char* encodedText, const char* notebook);
void GenerateStatistics(const char* originalText, const char* encodedText, const char* notebook);
}  // namespace CaesarCipher
