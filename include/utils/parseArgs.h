#pragma once

namespace parseArgs {

struct Args {
    char* sourceFile = nullptr;
    char* keyFile = nullptr;
    char* decodeFile = nullptr;
    char* encodeFile = nullptr;
};

[[nodiscard]] Args parse(int argc, char** argv);

}  // namespace parseArgs
