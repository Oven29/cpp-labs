#include "collections/Vector.h"
#include "utils/parseArgs.h"
#include "utils/FS.h"
#include <iostream>

int main(int argc, char** argv) {
    Vector::VecInt vector = Vector::CreateVector();
    PrintVector(vector);

    // for (int i = 0; i < -1; ++i) {
    //     std::cout << i << std::endl;
    // }

    // FS::WriteFile("test.txt", "New text");
    // char* content = FS::ReadFile("test2.txt");
    // std::cout << content << std::endl;

    parseArgs::Args args = parseArgs::parse(argc, argv);
    std::cout << "Source file: " << args.sourceFile << std::endl;
    std::cout << "Key file: " << args.keyFile << std::endl;
    std::cout << "Decode file: " << args.decodeFile << std::endl;
    std::cout << "Encode file: " << args.encodeFile << std::endl;

    // PushBack(vector, 1);
    // PrintVector(vector);

    // const int a = 10;
    // PushBack(vector, a);
    // PrintVector(vector);

    // PushBack(vector, 3);
    // PrintVector(vector);

    // const int b = 20;
    // PushBack(vector, b);
    // PrintVector(vector);

    // GetElement(vector, 0) = 2;
    // PrintVector(vector);

    // Vector::DeleteVector(vector);

    // for (int i = 0; i < argc; i++) {
    //     std::cout << argv[i] << std::endl;
    // }

    // std::cout << argv[0] << std::endl;

    return 0;
}
