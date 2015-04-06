CXX = g++
CXXFLAGS = -Wall -std=c++11
VPATH = .:./Scanner:./Scanner/Lex:./Scanner/Ident:./Scanner/Table_Ident:./Wrap_File:./Buffer

clean:
	rm -f *.o eduLang
	rm -f Scanner/*.o Scanner/Lex/*.o Scanner/Ident/*.o Scanner/Table_Ident/*.o

build: main.cpp Scanner.o Lex.o Ident.o Table_Ident.o Wrap_File.o Buffer.o
	$(CXX) $(CXXFLAGS) $^ -o eduLang

Scanner.o: Scanner.cpp Scanner.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Wrap_File.o: Wrap_File.cpp Wrap_File.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Buffer.o: Buffer.cpp Buffer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Lex.o: Lex.cpp Lex.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Ident.o: Ident.cpp Ident.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Table_Ident.o: Table_Ident.cpp Table_Ident.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: build
	./eduLang

valg: build
	valgrind ./eduLang
