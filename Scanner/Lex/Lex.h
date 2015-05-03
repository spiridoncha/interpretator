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
	LEX_CONST_STRING,//20
	LEX_WHILE,
	LEX_FOR,
	LEX_WRITE,//23
	LEX_ID,//24
	LEX_FIN,
	LEX_SEMICOLON,//26
	LEX_COMMA,
	LEX_ASSIGN,//28
	LEX_LPAREN,
	LEX_RPAREN,//30
	LEX_EQ,
	LEX_LSS,
	LEX_GTR,
	LEX_PLUS,
	LEX_UNARYPLUS,
	LEX_MINUS,
	LEX_UNARYMINUS,
	LEX_TIMES,
	LEX_SLASH,
	LEX_PERCENT,
	LEX_LEQ,
	LEX_NEQ,
	LEX_GEQ,
	LEX_APOST,
	LEX_ID_EXPR,
	LEX_BREAK,
	LEX_CONTINUE,
	POLIZ_GO,
	POLIZ_CONDITION_GO,
	POLIZ_LABEL,
	POLIZ_ADDRESS
};

class Lex
{
	type_of_lex type_lex;
	int value_lex;
	String str;
public:
	Lex(type_of_lex t = LEX_NULL, int v = 0, const char* st=nullptr) : type_lex(t), value_lex(v), str(st) {}
	void operator=(const Lex &other) { type_lex = other.type_lex; value_lex = other.value_lex; str = other.str; }
	Lex(const Lex &other) { type_lex = other.type_lex; value_lex = other.value_lex; str = other.str; }
	type_of_lex get_type() const { return type_lex; }
	int get_value_int() const { return value_lex; }
	String get_value_str() const { return str; }
	friend std::ostream& operator<<(std::ostream &, Lex);
};
#endif
