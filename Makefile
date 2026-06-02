CFLAGS=-Wall -Wextra -Wpedantic
CXXFLAGS=$(CFLAGS)

test: build/example_c99 build/example_c11 build/example_c17 build/example_cpp98 build/example_cpp03 build/example_cpp11 build/example_cpp14 build/example_cpp17 build/example_cpp20

build/example_c99: build example.c dcheck.c
	$(CC) $(CFLAGS) -std=c99 example.c dcheck.c -o build/example_c99

build/example_c11: build example.c dcheck.c
	$(CC) $(CFLAGS) -std=c11 example.c dcheck.c -o build/example_c11

build/example_c17: build example.c dcheck.c
	$(CC) $(CFLAGS) -std=c17 example.c dcheck.c -o build/example_c17

build/example_cpp98: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++98 example.cpp dcheck.c -o build/example_cpp98

build/example_cpp03: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++03 example.cpp dcheck.c -o build/example_cpp03

build/example_cpp11: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++11 example.cpp dcheck.c -o build/example_cpp11

build/example_cpp14: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++14 example.cpp dcheck.c -o build/example_cpp14

build/example_cpp17: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++17 example.cpp dcheck.c -o build/example_cpp17

build/example_cpp20: build example.cpp dcheck.c
	$(CXX) $(CXXFLAGS) -std=c++20 example.cpp dcheck.c -o build/example_cpp20

build:
	mkdir -p build

.PHONY: test build/example_c99 build/example_c11 build/example_cpp98 build/example_cpp03 build/example_cpp11 build/example_cpp14 build/example_cpp17 build/example_cpp20
