CXX = g++
CXXFLAGS = -Wall -std=c++11
VPATH = .:./Scanner:./Scanner/Lex:./Scanner/Ident:./Scanner/Table_Ident:./Wrap_File:./Buffer:./Exception:./String
LIBS = Scanner.o Lex.o Ident.o Table_Ident.o Wrap_File.o Buffer.o Exception.o String.o

clean:
	rm -f *.o eduLang

build: main.cpp $(LIBS)
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

Exception.o: Exception.cpp Exception.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

String.o: String.cpp String.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: build
	./eduLang test/qqq.txt

valg: build
	valgrind ./eduLang test/qqq.txt
