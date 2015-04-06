#ifndef LEX_H
#define LEX_H
#include <iostream>
#pragma once
enum type_of_lex
{
	LEX_NULL,
	LEX_AND,
	LEX_BEGIN,
	LEX_BOOL,
	LEX_DO,
	LEX_ELSE,
	LEX_END,
	LEX_IF,
	LEX_FALSE,
	LEX_INT,
	LEX_NOT,
	LEX_OR,
	LEX_PROGRAM,
	LEX_READ,
	LEX_THEN,
	LEX_TRUE,
	LEX_VAR,
	LEX_WHILE,
	LEX_FOR,
	LEX_WRITE,
	LEX_ID
	LEX_FIN,
	LEX_SEMICOLON,
	LEX_COMMA,
	LEX_COLON,
	LEX_ASSIGN,
	LEX_LPAREN,
	LEX_RPAREN,
	LEX_EQ,
	LEX_LSS,
	LEX_GTR,
	LEX_PLUS,
	LEX_MINUS,
	LEX_TIMES,
	LEX_SLASH,
	LEX_LEQ,
	LEX_NEQ,
	LEX_GEQ,
};

class Lex
{
	type_of_lex type_lex;
	int value_lex;
public:
	Lex(type_of_lex t = LEX_NULL, int v = 0) : type_lex(t), value_lex(v) {}
	type_of_lex get_type() const { return type_lex; }
	int get_value() const { return value_lex; }
	friend std::ostream& operator<<(std::ostream &, Lex);
};
#endif
