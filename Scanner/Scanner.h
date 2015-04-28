#ifndef SCANNER_H
#define SCANNER_H
#include "Lex/Lex.h"
#include "../Wrap_File/Wrap_File.h"
#include "../Buffer/Buffer.h"
#include "Table_Ident/Table_Ident.h"
#include <string.h>
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
	int prev_number_str;
	bool unary_op;// operation maybe unary ? true : false
	bool id_expr; // id may be in expression ? true : false
	int look(const char *buf, const char *list[]) const;

	Lex ret;
	Lex next;
public:
	Lex get_lex();
	Scanner(const char *program) : File(program)
	{
		ret = Lex(LEX_NULL);
		next = Lex(LEX_NULL);
		Current_State = H;
		c_ch = File.get_char();
		unary_op = true;
		id_expr = false;
		current_number_str = 1;
	}
	int get_current_number_str() { return prev_number_str; }
	Table_Ident& get_TID() { return TID; }
};
#endif
