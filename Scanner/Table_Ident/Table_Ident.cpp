#include <iostream>
#include "Table_Ident.h"
void Table_Ident::re_size()
{
	if (real_size == size)
	{
		Ident *p_new = new Ident[2*size];
		for(int i=0; i<size; ++i)
		{
			p_new[i] = p[i];
		}
		size *= 2;
		delete[] p;
		p = p_new;
	}
}

int Table_Ident::put(const char *buf)
{
	re_size();
	for(int i=0; i<real_size; ++i)
	{
		if (!strcmp(buf, p[i].get_name()))
			return i;
	}
	p[real_size].put_name(buf);
	return real_size++;
}
