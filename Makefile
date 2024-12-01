dev:
	g++ -std=c++20 -Wall -Werror -Wextra -Wpedantic *.cpp -o binary.out && ./binary.out

check:
	clang-tidy *.cpp
	clang-format --dry-run -Werror *.cpp

build:
	echo "Building..."
	mkdir build && cd build
	cmake ..
	cmake --build .
