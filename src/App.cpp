#include <iostream>

namespace App {
void Run(void (*execute)()) {
    char input = 'y';

    while (input == 'y') {
        execute();

        std::cout << "Continue? (y/n): ";
        std::cin >> input;
    }
}
}  // namespace App
