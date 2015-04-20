#include "Parser.h"
#include <iostream>

void Parser::analize()
{
	get_lex();
	Program();
	//prog.print()
	std::cout << "ya" << std::endl;
}

void Parser::Program()
{
	if (current_type_of_lex == LEX_PROGRAM)
	{
		get_lex();
	}
	else
	{
		throw current_lex;
	}
	Program1();
	if (current_type_of_lex != LEX_FINISH)
	{
		throw current_lex;
	}
}
	
void Parser::Program1()
{
	if (current_type_of_lex == LEX_BEGIN)
	{
		get_lex();
		Descriptions_And_Operators();
	}
	else
	{
		throw current_lex;
	}
	if (current_type_of_lex == LEX_END)
	{
		get_lex();
	}
	else
	{
		throw current_lex;
	}
}

void Parser::Descriptions_And_Operators()
{
	Descriptions();
	Operators();
}

void Parser::Descriptions()
{
	//TODO
	Description();
	while (current_type_of_lex == LEX_SEMICOLON)
	{
		get_lex();
		Description();
	}
}
void Parser::Description()
{
	//TODO
	if (current_type_of_lex == LEX_INT)
	{
		get_lex();
	}
	else if (current_type_of_lex == LEX_STRING)
	{
		get_lex();
	}
	else if (current_type_of_lex == LEX_BOOL)
	{
		get_lex();
	}
	else
	{
		throw current_lex;
	}
}

void Parser::Operators()
{
	
}
