#include "utils/fs.h"
#include <cstring>
#include <fstream>
#include <limits>
#include <stdexcept>

namespace {
char* ConcatenationStrings(const char* str1, const char* str2) {
    size_t len1 = std::strlen(str1);
    size_t len2 = std::strlen(str2);

    char* combined = new char[len1 + len2 + 1];  // +1 for nullptr

    if (!combined) {
        throw std::runtime_error("Memory allocation failed");
    }

    std::strncpy(combined, str1, len1);
    std::strncat(combined, str2, len2);

    return combined;
}

void ThrowExceptionWithFilename(const char* message, const char* filename) {
    throw std::runtime_error(ConcatenationStrings(message, filename));
}
}  // namespace

namespace fs {
void WriteFile(const char* filename, const char* content) {
    if (!filename || !content) {
        throw std::invalid_argument("Filename or content cannot be null.");
    }

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        ThrowExceptionWithFilename("Failed to open file: ", filename);
    }

    size_t contentLength = std::strlen(content);
    if (contentLength > static_cast<size_t>(std::numeric_limits<std::streamsize>::max())) {
        throw std::overflow_error("Content size exceeds maximum allowed size.");
    }

    file.write(content, static_cast<std::streamsize>(contentLength));
    if (!file) {
        ThrowExceptionWithFilename("Failed to write to file: ", filename);
    }
}

char* ReadFile(const char* filename) {
    if (!filename) {
        throw std::invalid_argument("Filename cannot be null.");
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        ThrowExceptionWithFilename("Failed to open file: ", filename);
    }

    file.seekg(0, std::ios::end);
    size_t size = static_cast<size_t>(file.tellg());
    if (size == static_cast<size_t>(-1)) {
        ThrowExceptionWithFilename("Failed to determine file size: ", filename);
    }

    file.seekg(0, std::ios::beg);
    if (size > static_cast<size_t>(std::numeric_limits<std::streamsize>::max())) {
        throw std::overflow_error("File size exceeds maximum allowed size.");
    }

    char* content = new char[size + 1];
    if (!content) {
        throw std::runtime_error("Memory allocation failed.");
    }

    file.read(content, static_cast<std::streamsize>(size));
    if (!file) {
        delete[] content;
        ThrowExceptionWithFilename("Failed to read file: ", filename);
    }

    content[size] = '\0';
    return content;
}
}  // namespace fs
