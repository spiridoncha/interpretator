#ifndef PARSER_H
#define PARSER_H
#include "../Scanner/Scanner.h"
#include "../Stack/Stack.h"
#include <iostream>
class Parser
{
public:
	//Poliz prog;
	explicit Parser(const char *program) : scan(program) {};
	void analize();
private:
	void get_lex() 
	{
		current_lex = scan.get_lex();
		current_type_of_lex = current_lex.get_type();
		current_value_int_of_lex = current_lex.get_value_int();
		current_value_str_of_lex = current_lex.get_value_str();
	}
	void Program();
	void Program1();
	void Descriptions_And_Operators();
	void Descriptions();
	bool Description();
	void Description_int();
	void Description_string();
	void Description_bool();
	void Operators();
	bool Operator();
	void Begin_End();
	void Sequence_Of_Expressions();
	void Expression();
	void Expression1();
	void Expression2();
	void Expression3();
	void Expression4();
	void Expression5();
	void Expression6();
	void Expression_Easy();
	void For_In_Parens();

	void declare(type_of_lex);
	void assign_in_description(int);
	void check_id();
	void check_id_in_read();
	void check_id_in_assign();
	void eq_type();
	void eq_bool();
	void check_op();
	void check_not();
	void check_unary_p_m();
	
	Scanner scan;
	Lex current_lex;
	type_of_lex current_type_of_lex;
	int current_value_int_of_lex;
	String current_value_str_of_lex;
	Stack<type_of_lex> st_lex;
};
#endif
