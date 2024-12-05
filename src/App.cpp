#include <iostream>
#include "CaesarCipher.h"
#include "utils/FS.h"
#include "utils/parseArgs.h"

namespace App {

void Run(int argc, char** argv) {
    parseArgs::Args args = parseArgs::parse(argc, argv);

    const char* source = FS::ReadFile(args.sourceFile);
    const char* notebook = FS::ReadFile(args.keyFile);

    const char* encode = CaesarCipher::Encode(source, notebook);
    const char* decode = CaesarCipher::Decode(encode, notebook);

    FS::WriteFile(args.encodeFile, encode);
    FS::WriteFile(args.decodeFile, decode);

    CaesarCipher::GenerateStatistics(source, encode, notebook);
}

}  // namespace App
