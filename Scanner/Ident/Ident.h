#ifndef IDENT_H
#define IDENT_H
#include "../Lex/Lex.h"
#include <string.h>
class Ident
{
	char *name;
	bool declare;
	type_of_lex type;
	bool assign;
	int value;
	String str;
	Ident(const Ident&) {}
public:
	Ident() : name(nullptr), declare(false), assign(false) {}
	~Ident() { delete[] name; }
	Ident& operator=(const Ident&);
	const char* get_name() const { return name; }
	void put_name(const char *n)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	bool get_declare() const { return declare; }
	void put_declare() { declare = true; }
	type_of_lex get_type() const { return type; }
	void put_type(type_of_lex t) { type = t; }
	bool get_assign() const { return assign; }
	void put_assign() { assign = true; }
	int get_value() const { return value; }
	String get_value_str() const { return str; }
	void put_value(int v) { value = v; }
	void put_value(const String &v) { str = v; }
};
#endif
