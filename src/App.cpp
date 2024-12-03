#include <iostream>

namespace {
void Execute(int argc, char** argv) {
}
}  // namespace

namespace App {
void Run(int argc, char** argv) {
    char input = 'y';

    while (input == 'y') {
        Execute(argc, argv);

        std::cout << "Continue? (y/n): ";
        std::cin >> input;
    }
}
}  // namespace App
