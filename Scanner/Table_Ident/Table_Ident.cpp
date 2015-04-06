#include "Table_Ident.h"
Table_Ident::Table_Ident(const Table_Ident &t)
{
	size = t.size;
	real_size = t.real_size;
	Ident *p = new Ident[t.size];
	for(unsigned int i=0; i<real_size; ++i)
	{
		p[i] = t.p[i];
	}
}

void Table_Ident::re_size()
{
	if (real_size == size)
	{
		Ident *p_new = new Ident[2*size];
		for(unsigned int i=0; i<real_size; ++i)
		{
			p_new[i] = p[i];
		}
		size *= 2;
		delete[] p;
		p = p_new;
	}
}

unsigned int Table_Ident::put(const char *buf)
{
	re_size();
	for(unsigned int i=0; i<size; ++i)
	{
		if (!strcmp(buf, p[i].get_name()))
			return i;
	}
	p[size].put_name(buf);
	return size++;
}
