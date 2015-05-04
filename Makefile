CXX = g++
CXXFLAGS = -Wall -std=c++11
VPATH = .:./Scanner:./Scanner/Lex:./Scanner/Ident:./Scanner/Table_Ident:./Wrap_File:./Buffer:./Exception:./String:./Stack:./Parser:./Poliz
LIBS = Parser.o Scanner.o Lex.o Ident.o Table_Ident.o Wrap_File.o Buffer.o Exception.o String.o Stack.o Poliz.o

.PHONY : clean
clean:
	rm -f *.o eduLang

.PHONY : build
build: main.cpp $(LIBS) Poliz.h
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

Stack.o: Stack.cpp Stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Parser.o: Parser.cpp Parser.h Poliz.cpp Poliz.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Poliz.o: Poliz.cpp Poliz.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : run
run: build
	./eduLang test/qqq.txt

.PHONY : test tests.py
test: build
	python tests.py

.PHONY : valg
valg: build
	valgrind ./eduLang test/qqq.txt
