#include "collections/Vector.h"
#include "utils/parseArgs.h"
#include <iostream>

int main(int argc, char** argv) {
    Vector::VecInt vector = Vector::CreateVector();
    PrintVector(vector);

    // for (int i = 0; i < -1; ++i) {
    //     std::cout << i << std::endl;
    // }
    parseArgs::Args args = parseArgs::parse(argc, argv);
    std::cout << args.sourceFile << std::endl;

    PushBack(vector, 1);
    PrintVector(vector);

    const int a = 10;
    PushBack(vector, a);
    PrintVector(vector);

    PushBack(vector, 3);
    PrintVector(vector);

    const int b = 20;
    PushBack(vector, b);
    PrintVector(vector);

    GetElement(vector, 0) = 2;
    PrintVector(vector);

    Vector::DeleteVector(vector);

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}
