#pragma once
#include <cstddef>
#include "collections/Vector.h"

namespace CaesarCipher {

Vector::VecInt CreateNotebookKeys(const char* notebook);
char* Encode(const char* text, const Vector::VecInt& keys);
char* Decode(const char* encodedText, const Vector::VecInt& keys);
void GenerateStatistics(const char* originalText, const char* encodedText, const Vector::VecInt& keys);

}  // namespace CaesarCipher
