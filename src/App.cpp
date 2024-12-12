#include <iostream>
#include "CaesarCipher.h"
#include "collections/Vector.h"
#include "utils/fs.h"
#include "utils/parseArgs.h"

namespace App {

void Run(int argc, char** argv) {
    parseArgs::Args args = parseArgs::parse(argc, argv);

    const char* source = fs::ReadFile(args.sourceFile);
    const char* keys = fs::ReadFile(args.keyFile);

    Vector::VecInt processedKeys = CaesarCipher::CreateNotebookKeys(keys);

    const char* encode = CaesarCipher::Encode(source, processedKeys);
    const char* decode = CaesarCipher::Decode(encode, processedKeys);

    fs::WriteFile(args.encodeFile, encode);
    fs::WriteFile(args.decodeFile, decode);

    CaesarCipher::GenerateStatistics(source, encode, processedKeys);
}

}  // namespace App
