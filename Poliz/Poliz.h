#ifndef POLIZ_H
#define POLIZ_H

#include "../Scanner/Lex/Lex.h"
#include <iostream>
class Poliz
{
public:
	Poliz() : full_size(10), real_size(0), free(0) { prog = new Lex[full_size]; }
	~Poliz() { delete[] prog; }
	void put_lex(Lex lex) { resize(); prog[free++] = lex; ++real_size; }
	void put_lex(Lex lex, int pos) { resize(); prog[pos] = lex; }
	void blank() { resize(); ++free; /*TODO*/ ++real_size;};
	int get_free() const { return free; }
	void out();
	Lex& operator[](int i)
	{
		return prog[i];
	}
	
private:
	Lex *prog;
	int full_size;
	int real_size;
	int free;
	void resize();
	void operator=(const Poliz&);
	Poliz(const Poliz&);
};
#endif
