#include "utils/parseArgs.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace {
const int kRequiredArgumentsCount = 5;

constexpr const char* kSourceFileArgument = "--source-file=";
constexpr const char* kKeyFileArgument = "--key-file=";
constexpr const char* kDecodeFileArgument = "--decode-file=";
constexpr const char* kEncodeFileArgument = "--encode-file=";

void PrintUsage() {
    std::cout << "Usage:" << std::endl
              << "filename <source_file> <key_file> <decode_file> <encode_file>" << std::endl
              << "or" << std::endl
              << "filename " << kSourceFileArgument << "<source_file> " << kKeyFileArgument << "<key_file> " << kDecodeFileArgument
              << "<decode_file> " << kEncodeFileArgument << "<encode_file>" << std::endl
              << std::endl;
}

void ThrowException() {
    PrintUsage();
    throw std::invalid_argument("Invalid arguments");
}

bool EqualsString(const char* str1, const char* str2) {
    return std::strncmp(str1, str2, std::strlen(str2)) == 0;
}
}  // namespace

namespace parseArgs {
Args parse(int argc, char** argv) {
    Args args{};

    if (argc != kRequiredArgumentsCount) {
        ThrowException();
    }

    int countOfNamedArguments = 0;

    for (int i = 0; i < argc; i++) {
        if (EqualsString(argv[i], kSourceFileArgument)) {
            args.sourceFile = argv[i] + std::strlen(kSourceFileArgument);
            countOfNamedArguments++;
        }
        if (EqualsString(argv[i], kKeyFileArgument)) {
            args.keyFile = argv[i] + std::strlen(kKeyFileArgument);
            countOfNamedArguments++;
        }
        if (EqualsString(argv[i], kDecodeFileArgument)) {
            args.decodeFile = argv[i] + std::strlen(kDecodeFileArgument);
            countOfNamedArguments++;
        }
        if (EqualsString(argv[i], kEncodeFileArgument)) {
            args.encodeFile = argv[i] + std::strlen(kEncodeFileArgument);
            countOfNamedArguments++;
        }
    }

    if (countOfNamedArguments == 0) {
        args.sourceFile = argv[1];
        args.keyFile = argv[2];
        args.decodeFile = argv[3];
        args.encodeFile = argv[4];
    } else if (countOfNamedArguments != 4) {
        ThrowException();
    }

    return args;
}
}  // namespace parseArgs
