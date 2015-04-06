#ifndef SCANNER_H
#define SCANNER_H
#include "Lex/Lex.h"
#include "../Wrap_File/Wrap_File.h"
#include "../Buffer/Buffer.h"
#pragma once
class Scanner
{
	enum state { H, IDENT, NUM, COMMENT, ALE, DELIM, NEQ };
	static char *TW[];
	static type_of_lex words[];
	static char *TD[];
	static type_of_lex delims[];
	state Current_State;
	Wrap_File F;
	Buffer buf;
	int current_char;
	int look(const char *buf, char **list);
	Scanner(const Scanner&) {}
public:
	Lex get_lex();
	Scanner(const char *program) : F(program)
	{
		Current_State = H;
		current_char = F.get_Char();
	}
};
char* Scanner::TW[] =
{
	"",
	"and",
	"{",
	"bool",
	"do",
	"else",
	"}",
	"if",
	"false",
	"int",
	"not",
	"or",
	"program",
	"read",
	"then",
	"true",
	"while",
	"for",
	"write",
	nullptr
};
char* Scanner::TD[] =
{
	"",
	";",
	"@",
	",",
	"=",
	"(",
	")",
	"==",
	"<",
	">",
	"+",
	"-",
	"*",
	"/",
	"<=",
	"!=",
	">=",
	nullptr
};
type_of_lex Scanner::words[]
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
	LEX_WHILE,
	LEX_FOR,
	LEX_WRITE,
	LEX_NULL
};
type_of_lex Scanner::delims[] =
{
	LEX_NULL,
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
	LEX_NULL
};
#endif
