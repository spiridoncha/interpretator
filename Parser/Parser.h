#ifndef PARSER_H
#define PARSER_H
#include "../Scanner.Scanner.h"
class Parser
{

private:
	Scanner scan;
	Lex current_lex;
	type_of_lex current_type_of_lex;
	int current_value_of_lex;
	//Stack<int> st_int;
	//Stack<type_of_lex> st_lex;
};
#endif
