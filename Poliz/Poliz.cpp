#include "Poliz.h"
void Poliz::resize()
{
	if (real_size == full_size)
	{
		Lex *new_prog = new Lex[2*full_size];
		for(int i=0;i<real_size;++i)
		{
			new_prog[i] = prog[i];
		}
		full_size *= 2;
		delete[] prog;
		prog = new_prog;
	}
}
