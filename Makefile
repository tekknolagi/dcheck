test: build_c99 build_c11 build_cpp98 build_cpp11 build_cpp14 build_cpp17 build_cpp20

build_c99: build
	$(CC) -std=c99 example.c dcheck.c -o build/example_c99

build_c11: build
	$(CC) -std=c11 example.c dcheck.c -o build/example_c11

build_cpp98: build
	$(CXX) -std=c++98 example.cpp dcheck.c -o build/example_cpp98

build_cpp11: build
	$(CXX) -std=c++11 example.cpp dcheck.c -o build/example_cpp11

build_cpp14: build
	$(CXX) -std=c++14 example.cpp dcheck.c -o build/example_cpp14

build_cpp17: build
	$(CXX) -std=c++17 example.cpp dcheck.c -o build/example_cpp17

build_cpp20: build
	$(CXX) -std=c++20 example.cpp dcheck.c -o build/example_cpp20

build:
	mkdir -p build

.PHONY: test build_c99 build_c11 build_cpp98 build_cpp11 build_cpp14 build_cpp17 build_cpp20
