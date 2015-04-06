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
	~Ident() { delete[] name; }
	void put_name(const char *n)
	{
		name = new char [strlen(n) + 1];
		strcpy(name, n);
	}
	bool get_declare() const { return declare; }
	void put_declare() : declare(true) {}
	type_of_lex get_type() const { return type; }
	void put_type(type_of_lex t) : type(t) {}
	bool get_assign() const { return assign; }
	void put_assign() : assign(true) {}
	int get_value() const { return value; }
	void put_value(int v) : value(v) {}
};
#endif
