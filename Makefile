dev:
	mkdir -p app
	g++ -std=c++20 -Wall -Werror -Wextra -Wpedantic *.cpp -o bin/app && ./bin/app

check:
	clang-tidy *.cpp
	clang-format --dry-run -Werror *.cpp

build:
	echo "Building..."
	rm -rf build
	mkdir build
	cd build
	cmake ..
	cmake --build .
