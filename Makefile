CXX = g++
CXXFLAGS = -Wall -std=c++11

clean:
	rm -f *.o eduLang
	rm -f Scanner/*.o Scanner/Lex/*.o

build: main.cpp Scanner/Scanner.o
	$(CXX) $(CXXFLAGS) main.cpp -o eduLang

Scanner/scanner.o: Scanner.cpp Scanner.h Scanner/Lex/Lex.o Scanner/Ident/Ident.o
	$(CXX) $(CXXFLAGS) -c Scanner.cpp -o Scanner.o

Scanner/Lex/Lex.o: Scanner/Lex.cpp Scanner/Lex.h
	$(CXX) $(CXXFLAGS) -c Lex.cpp -o Lex.o

Scanner/Ident/Ident.o: Scanner/Ident/Ident.cpp Scanner/Ident/Ident.h
	$(CXX) $(CXXFLAGS) -c Ident.cpp -o Ident.o

run: build
	./eduLang

valg: build
	valgrind ./eduLang
