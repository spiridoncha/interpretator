#ifndef SCANNER_H
#define SCANNER_H
#include "Lex/Lex.h"
#include "../Wrap_File/Wrap_File.h"
#include "../Buffer/Buffer.h"
#pragma once
class Scanner
{
	enum state { H, IDENT, NUM, COMMENT, ALE, DELIM, NEQ };
	static const char *TW[];
	static type_of_lex words[];
	static const char *TD[];
	static type_of_lex delims[];
	state Current_State;
	Wrap_File F;
	Buffer buf;
	int current_char;
	int look(const char *buf, const char *list[]);
public:
	Lex get_lex();
	Scanner(const char *program) : F(program)
	{
		Current_State = H;
		current_char = F.get_Char();
	}
};
#endif
