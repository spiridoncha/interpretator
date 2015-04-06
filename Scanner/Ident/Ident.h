#ifndef IDENT_H
#define IDENT_H
#include "../Lex/Lex.h"
#include <string.h>
#pragma once
class Ident
{
	char *name;
	bool declare;
	type_of_lex type;
	bool assigh;
	int value;
public:
	Ident() : declare(false), assigh(false) {}
	void put_name(const char *n)
	{
		name = new char [strlen(n) + 1];
		strcpy(name, n);
	}
	bool get_declare() { return declare; }
	void put_declare() : declare = true {}
};
#endif
