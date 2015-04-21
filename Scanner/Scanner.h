#ifndef SCANNER_H
#define SCANNER_H
#include "Lex/Lex.h"
#include "../Wrap_File/Wrap_File.h"
#include "../Buffer/Buffer.h"
#include "Table_Ident/Table_Ident.h"
class Scanner
{
	enum state { H, IDENT, NUM, COMMENT, ALE, NEQ,  DELIM, COMMENT0, COMMENT1, STR };
	static const char *TW[];
	static type_of_lex words[];
	static const char *TD[];
	static type_of_lex delims[];
	Table_Ident TID;
	state Current_State;
	Wrap_File File;
	Buffer buf;
	int c_ch; // current char
	int current_number_str;
	int look(const char *buf, const char *list[]) const;
public:
	Lex get_lex();
	Scanner(const char *program) : File(program)
	{
		Current_State = H;
		c_ch = File.get_char();
		current_number_str = 1;
	}
	int get_current_number_str() { return current_number_str; }
};
#endif
