#include "Parser.h"
#include <iostream>

void Parser::analize()
{
	get_lex();
	Program();
	//TODO
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
	if (Description())
	{
		if (current_type_of_lex != LEX_SEMICOLON)
		{
			throw current_lex;
		}
	}
	else
	{
		return;
	}
	while (current_type_of_lex == LEX_SEMICOLON)
	{
		get_lex();
		if (Description())
		{
			if (current_type_of_lex != LEX_SEMICOLON)
			{
				throw current_lex;
			}
		}
		else
		{
			break;
		}
	}
}

bool Parser::Description()
//true if Description exist
//otherwise false
{
	if (current_type_of_lex == LEX_INT)
	{
		get_lex();
		Description_int();
		while (current_type_of_lex == LEX_COMMA)
		{
			get_lex();
			Description_int();

		}
		return true;
	}
	else if (current_type_of_lex == LEX_STRING)
	{
		get_lex();
		Description_string();
		while (current_type_of_lex == LEX_COMMA)
		{
			get_lex();
			Description_string();
		}
		return true;
	}
	else if (current_type_of_lex == LEX_BOOL)
	{
		get_lex();
		Description_bool();
		while (current_type_of_lex == LEX_COMMA)
		{
			get_lex();
			Description_bool();
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Parser::Description_int()
{
	if (current_type_of_lex == LEX_ID)
	{
		//TODO
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			get_lex();
			if (current_type_of_lex == LEX_NUM)
			{
				//TODO
				get_lex();
			}
			else
			{
				throw current_lex;
			}
		}
	}
	else
	{
		throw current_lex;
	}
}

void Parser::Description_string()
{
	if (current_type_of_lex == LEX_ID)
	{
		//TODO
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			get_lex();
			if (current_type_of_lex == LEX_CONST_STRING)
			{
				//TODO
				get_lex();
			}
			else
			{
				throw current_lex;
			}
		}
	}
	else
	{
		throw current_lex;
	}

}

void Parser::Description_bool()
{
	if (current_type_of_lex == LEX_ID)
	{
		//TODO
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			get_lex();
			if (current_type_of_lex == LEX_TRUE || current_type_of_lex == LEX_FALSE)
			{
				//TODO
				get_lex();
			}
			else
			{
				throw current_lex;
			}
		}
	}
	else
	{
		throw current_lex;
	}

}
void Parser::Zero_Or_More_Operators()
{
	if (Operator())
	{
		if (current_type_of_lex != LEX_SEMICOLON)
		{
			throw current_lex;
		}
	}
	else
	{
		return;
	}
	while (current_type_of_lex == LEX_SEMICOLON)
	{
		get_lex();
		if (Operator())
		{
			if (current_type_of_lex != LEX_SEMICOLON)
			{
				throw current_lex;
			}
		}
		else
		{
			break;
		}
	}
}

void Parser::Operators()
{
	Zero_Or_More_Operators();
}

bool Parser::Operator()
{
	//TODO
	if (current_type_of_lex == LEX_IF)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			Expression();
			if (current_type_of_lex == LEX_RPAREN)
			{
				//TODO
				get_lex();
				if (!Operator())
				{
					throw current_lex;
				}
			}
			else
			{
				throw current_lex;
			}
		}
		else
		{
			throw current_lex;
		}
		return true;
	}
	else if (current_type_of_lex == LEX_WHILE)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			Expression();
			if (current_type_of_lex == LEX_RPAREN)
			{
				//TODO
				get_lex();
				if (!Operator())
				{
					throw current_lex;
				}
			}
			else
			{
				throw current_lex;
			}
		}
		else
		{
			throw current_lex;
		}
		return true;
	}
	else if (current_type_of_lex == LEX_READ)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			if (current_type_of_lex == LEX_ID)
			{
				//TODO
				get_lex();
				if (current_type_of_lex == LEX_RPAREN)
				{
					get_lex();
					//TODO
				}
				else
				{
					throw current_lex;
				}
			}
			else
			{
				throw current_lex;
			}
		}
		else
		{
			throw current_lex;
		}
		return true;
	}
	else if (current_type_of_lex == LEX_WRITE)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			Expression();
			if (current_type_of_lex == LEX_RPAREN)
			{
				get_lex();
				//TODO
			}
			else
			{
				throw current_lex;
			}
		}
		else
		{
			throw current_lex;
		}
		return true;
	}
	else if (current_type_of_lex == LEX_ID)
	{
		//TODO
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			get_lex();
			Expression();
			//TODO
		}
		else
		{
			throw current_lex;
		}
		return true;
	}
	else
	{
		return false;
	}
}
	

void Parser::Expression()
{
	//TODO
}
