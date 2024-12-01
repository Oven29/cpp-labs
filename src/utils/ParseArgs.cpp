#include "utils/parseArgs.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace {
const int kSourceFileArgumentLenght = 14;
const int kKeyFileArgumentLenght = 11;
const int kDecodeFileArgumentLenght = 14;
const int kEncodeFileArgumentLenght = 14;
}  // namespace

namespace parseArgs {
Args parse(int argc, char** argv) {
    Args args{};

    if (argc != 4) {
        std::cout << "Usage:\nfilename <source_file> <key_file> <decode_file> <encode_file>\nor\n"
                  << "filename --source-file=<source_file> --key-file=<key_file> --decode-file=<decode_file> --encode-file=<encode_file>" << "\n\n";

        throw std::invalid_argument("Invalid number of arguments");
    }

    if (std::strncmp(argv[1], "--source-file=", kSourceFileArgumentLenght) == 0) {
        args.sourceFile = argv[1] + kSourceFileArgumentLenght;
    } else {
        args.sourceFile = argv[1];
    }
    if (std::strncmp(argv[2], "--key-file=", kKeyFileArgumentLenght) == 0) {
        args.keyFile = argv[2] + kKeyFileArgumentLenght;
    } else {
        args.keyFile = argv[2];
    }
    if (std::strncmp(argv[3], "--decode-file=", kDecodeFileArgumentLenght) == 0) {
        args.decodeFile = argv[3] + kDecodeFileArgumentLenght;
    } else {
        args.decodeFile = argv[3];
    }
    if (std::strncmp(argv[4], "--encode-file=", kEncodeFileArgumentLenght) == 0) {
        args.encodeFile = argv[4] + kEncodeFileArgumentLenght;
    } else {
        args.encodeFile = argv[4];
    }

    return args;
}
}  // namespace parseArgs
