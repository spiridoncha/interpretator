#ifndef SCANNER_H
#define SCANNER_H
#include "Lex/Lex.h"
#include "../Wrap_File/Wrap_File.h"
#include "../Buffer/Buffer.h"
class Scanner
{
	enum state { H, IDENT, NUM, COMMENT, ALE, DELIM, NEQ };
	static const char *TW[];
	static type_of_lex words[];
	static const char *TD[];
	static type_of_lex delims[];
	state Current_State;
	Wrap_File File;
	Buffer buf;
	int c_ch; // current char
	unsigned int current_str;
	int look(const char *buf, const char *list[]);
public:
	Lex get_lex();
	Scanner(const char *program) : File(program)
	{
		Current_State = H;
		c_ch = File.get_char();
		current_str = 1;
	}
};
#endif
