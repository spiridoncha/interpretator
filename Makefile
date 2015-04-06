CXX = g++
CXXFLAGS = -Wall -std=c++11
VPATH = .:./Scanner:./Scanner/Lex:./Scanner/Ident:./Scanner/Table_Ident

clean:
	rm -f *.o eduLang
	rm -f Scanner/*.o Scanner/Lex/*.o Scanner/Ident/*.o Scanner/Table_Ident/*.o

build: main.cpp Scanner.o Lex.o Ident.o Table_Ident.o
	$(CXX) $(CXXFLAGS) $^ -o eduLang

Scanner.o: Scanner.cpp Scanner.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Lex.o: Lex.cpp Lex.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Ident.o: Ident.cpp Ident.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Table_Ident.o: Table_Ident.cpp Table_Ident.h Ident.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: build
	./eduLang

valg: build
	valgrind ./eduLang
