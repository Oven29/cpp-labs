#include <iostream>
#include "app.h"

int main(int argc, char** argv) {
    test::helloWorld();

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}
