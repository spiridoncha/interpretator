#ifndef TABLE_IDENT_H
#define TABLE_IDENT_H
#include "../Ident/Ident.h"
#pragma once
class Table_Ident
{
	Ident *p;
	unsigned int size;
	unsigned int real_size;
	void re_size();
public:
	Table_Ident(unsigned int start_size=4) : real_size(0)
	{
		p = new Ident[size=start_size];
	}
	~Table_Ident() { delete[] p; }
	Table_Ident(const Table_Ident&);
	Ident& operator[](unsigned int k) const { return p[k]; }
	unsigned int put(const char*);
};
#endif
