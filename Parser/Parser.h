#ifndef PARSER_H
#define PARSER_H
#include "../Scanner/Scanner.h"
class Parser
{
	//Poliz prog;
	explicit Parser(const char *program) : scan(program) {};
	void get_lex() 
	{
		current_lex = scan.get_lex();
		current_type_of_lex = current_lex.get_type();
		current_value_int_of_lex = current_lex.get_value_int();
		current_value_str_of_lex = current_lex.get_value_str();
	}
	void analize();
	void Program();
	void Program1();
	void Descriptions_And_Operators();
	void Descriptions();
	void Description();
	void Operators();
	
private:
	Scanner scan;
	Lex current_lex;
	type_of_lex current_type_of_lex;
	int current_value_int_of_lex;
	String current_value_str_of_lex;
	//Stack<int> st_int;
	//Stack<type_of_lex> st_lex;
};
#endif
