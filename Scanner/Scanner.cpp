#include "Scanner.h"
int Scanner::look(const char *buf, const char *list[])
{
	int i = 0;
	while(list[i])
	{
		if (!strcmp(buf, list[i]))
		{
			return i;
		}
		++i;
	}
	return 0;
}

Lex Scanner::get_lex()
{
	//int d, i;
	//Current_State = H;
	//do
	//{
	//	
	//} while(true);
/*
	const char *p = "while";
	int i;
	if ((i = look(p, TW)) != 0)
		return Lex(words[i], i);
	else
		return Lex();
*/
}

const char* Scanner::TW[] =
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
	"string",
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
const char* Scanner::TD[] =
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
	"""",
	nullptr
};
type_of_lex Scanner::words[] =
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
	LEX_STRING,
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
	LEX_APOST, //?
	LEX_NULL
};
