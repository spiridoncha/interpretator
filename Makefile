CXX = g++
CXXFLAGS = -Wall -std=c++11

clean:
	rm -f *.o eduLang

build: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o eduLang

run: build
	./eduLang

valg: build
	valgrind ./eduLang
