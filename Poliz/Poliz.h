#include "../Scanner/Lex/Lex.h"
#include <iostream>
class Poliz
{
public:
	Poliz() : full_size(10), real_size(0), free(0) { prog = new Lex[full_size]; }
	~Poliz() { delete[] prog; }
	void put_lex(Lex lex) { resize(); prog[free++] = lex; }
	void put_lex(Lex lex, int pos) { prog[pos] = lex; }
	void blank() { resize(); ++free; /*TODO*/ ++real_size;};
	int get_free() { return free; }
	void out();
	Lex& operator[](int i)
	{
		//
		return prog[i];
	}
	
private:
	Lex *prog;
	int full_size;
	int real_size;
	int free;
	void resize();
};
