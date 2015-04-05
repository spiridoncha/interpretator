#ifndef LEX_H
#define LEX_H
#include <iostream>
enum type_of_lex
{
	LEX_NULL,
	LEX_AND,
	LEX_BEGIN,
	LEX_END,
	LEX_NUM,
	LEX_ID
};

class Lex
{
	type_of_lex type_lex;
	int value_lex;
public:
	Lex(type_of_lex t = LEX_NULL, int v = 0) : type_of_lex(t), value_lex(v) {}
	type_of_lex get_type() { return type_lex; }
	int get_value() { return value_lex; }
	friend std::ostream& operator<<(std::ostream &, Lex);
};
#endif