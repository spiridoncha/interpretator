#ifndef LEX_H
#define LEX_H
#include <iostream>
#include "../../String/String.h"
enum type_of_lex
{
	LEX_NULL,//0
	LEX_FINISH,//1
	LEX_AND,
	LEX_BEGIN,//3
	LEX_BOOL,
	LEX_DO,
	LEX_ELSE,
	LEX_END,
	LEX_IF,//8
	LEX_FALSE,
	LEX_INT,
	LEX_NUM,
	LEX_NOT,//12
	LEX_OR,
	LEX_PROGRAM,
	LEX_READ,
	LEX_THEN,//16
	LEX_TRUE,
	LEX_VAR,
	LEX_STRING,
	LEX_WHILE,//20
	LEX_FOR,
	LEX_WRITE,
	LEX_ID,//23
	LEX_FIN,
	LEX_SEMICOLON,//25
	LEX_COMMA,
	LEX_ASSIGN,
	LEX_LPAREN,
	LEX_RPAREN,
	LEX_EQ,
	LEX_LSS,
	LEX_GTR,
	LEX_PLUS,
	LEX_MINUS,
	LEX_TIMES,
	LEX_SLASH,//37
	LEX_LEQ,
	LEX_NEQ,
	LEX_GEQ,//40
	LEX_APOST
};

class Lex
{
	type_of_lex type_lex;
	int value_lex;
	String str;
public:
	Lex(type_of_lex t = LEX_NULL, int v = 0, const char* st=nullptr) : type_lex(t), value_lex(v), str(st) {}
	type_of_lex get_type() const { return type_lex; }
	int get_value_int() const { return value_lex; }
	String get_value_str() const { return str; }
	friend std::ostream& operator<<(std::ostream &, Lex);
};
#endif
