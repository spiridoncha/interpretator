#include "Parser.h"
#include <iostream>

void Parser::analize()
{
	get_lex();
	Program();
	//TODO
	std::cout << "yeah!!!" << std::endl;
}

void Parser::Program()
{
	if (current_type_of_lex == LEX_PROGRAM)
	{
		get_lex();
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("'program'"));
	}
	Program1();
	if (current_type_of_lex != LEX_FINISH)
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("'EOF'"));
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
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("'{'"));
	}
	if (current_type_of_lex == LEX_END)
	{
		get_lex();
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("'}'"));
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
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
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
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
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
			if (current_type_of_lex == LEX_PLUS || current_type_of_lex == LEX_MINUS)
			{
				//TODO
				get_lex();
			}
			if (current_type_of_lex == LEX_NUM)
			{
				//TODO
				get_lex();
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("number"));
			}
		}
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("identeficator"));
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
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("string"));
			}
		}
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("identeficator"));
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
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("'true' or 'false'"));
			}
		}
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("identeficator"));
	}

}
void Parser::Operators()
{
	if (!Operator())
	{
		return;
	}
	while (true)
	{
		if (!Operator())
		{
			break;
		}
	}
}

void Parser::Begin_End()
{
	if (current_type_of_lex == LEX_BEGIN)
	{
		get_lex();
		Operators();
		if (current_type_of_lex == LEX_END)
		{
			get_lex();
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'}'"));
		}
	}
	else
	{
		//TODO
		if (!Operator())
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("operator"));
		}
	}
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
				Begin_End();
				if (current_type_of_lex == LEX_ELSE)
				{
					//TODO
					get_lex();
					Begin_End();
				}
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
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
				Begin_End();
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
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
					if (current_type_of_lex == LEX_SEMICOLON)
					{
						get_lex();
					}
					else
					{
						throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
					}
				}
				else
				{
					throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
				}
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("identeficator"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
		}
		return true;
	}
	else if (current_type_of_lex == LEX_WRITE)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			//TODO TODO
			Sequence_Of_Expressions();
			if (current_type_of_lex == LEX_RPAREN)
			{
				get_lex();
				//TODO
				if (current_type_of_lex == LEX_SEMICOLON)
				{
					get_lex();
				}
				else
				{
					throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
				}
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
		}
		return true;
	}
	else if (current_type_of_lex == LEX_DO)
	{
		get_lex();
		Begin_End();
		if (current_type_of_lex == LEX_WHILE)
		{
			get_lex();
			if (current_type_of_lex == LEX_LPAREN)
			{
				get_lex();
				Expression();
				if (current_type_of_lex == LEX_RPAREN)
				{
					get_lex();
					if (current_type_of_lex == LEX_SEMICOLON)
					{
						get_lex();
					}
					else
					{
						throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
					}
				}
				else
				{
					throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
				}
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'while'"));
		}
		return true;
	}
	else if (current_type_of_lex == LEX_FOR)
	{
		get_lex();
		For_In_Parens();
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
			if (current_type_of_lex == LEX_SEMICOLON)
			{
				get_lex();
			}
			else
			{
				throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
			}
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("'='"));
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Parser::For_In_Parens()
{
	if (current_type_of_lex == LEX_LPAREN)
	{
		get_lex();
		Expression();
		if (current_type_of_lex == LEX_SEMICOLON)
		{
			get_lex();
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
		}
		Expression();
		if (current_type_of_lex == LEX_SEMICOLON)
		{
			get_lex();
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("';'"));
		}
		Expression();
		if (current_type_of_lex == LEX_RPAREN)
		{
			get_lex();
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
		}
		Begin_End();
	}
	else
	{
		throw Syntax_Error_Expected(scan.get_current_number_str(), String("'('"));
	}
}
	
void Parser::Sequence_Of_Expressions()
{
	Expression();
	//TODO
	while (current_type_of_lex == LEX_COMMA)
	{
		//TODO
		get_lex();
		Expression();
	}
}
void Parser::Expression()
{
	Expression1();
	while (current_type_of_lex == LEX_ASSIGN)
	{
		//TODO
		get_lex();
		Expression1();
	}
}

void Parser::Expression1()
{
	Expression2();
	while (current_type_of_lex == LEX_OR)
	{
		//TODO
		get_lex();
		Expression2();
	}
}

void Parser::Expression2()
{
	Expression3();
	while (current_type_of_lex == LEX_AND)
	{
		//TODO
		get_lex();
		Expression3();
	}

}

void Parser::Expression3()
{
	Expression4();
	while (current_type_of_lex == LEX_EQ ||
		current_type_of_lex == LEX_NEQ ||
		current_type_of_lex == LEX_LSS ||
		current_type_of_lex == LEX_GTR ||
		current_type_of_lex == LEX_LEQ ||
		current_type_of_lex == LEX_GEQ)
	{
		//TODO
		get_lex();
		Expression4();
	}
		
}

void Parser::Expression4()
{
	Expression5();
	while (current_type_of_lex == LEX_PLUS || current_type_of_lex == LEX_MINUS)
	{
		//TODO
		get_lex();
		Expression5();
	}
}

void Parser::Expression5()
{
	Expression6();
	while (current_type_of_lex == LEX_TIMES || current_type_of_lex == LEX_SLASH || current_type_of_lex == LEX_PERCENT)
	{
		//TODO
		get_lex();
		Expression6();
	}
}

void Parser::Expression6()
{
	if (current_type_of_lex == LEX_NOT)
	{
		//TODO
		get_lex();
		Expression6();
	}
	else if (current_type_of_lex == LEX_UNARYMINUS || current_type_of_lex == LEX_UNARYPLUS)
	{
		//TODO
		//std::cout << "1" << scan.get_current_number_str();
		get_lex();
		Expression6();
	}
	else
	{
		Expression_Easy();
	}
}

void Parser::Expression_Easy()
{
	if (current_type_of_lex == LEX_ID)
	{
		//TODO
		get_lex();
	}
	else if (current_type_of_lex == LEX_NUM)
	{
		//TODO
		get_lex();
	}
	else if (current_type_of_lex == LEX_CONST_STRING)
	{
		//TODO
		get_lex();
	}
	else if (current_type_of_lex == LEX_TRUE)
	{
		//TODO
		get_lex();
	}
	else if (current_type_of_lex == LEX_FALSE)
	{
		//TODO
		get_lex();
	}
	else if (current_type_of_lex == LEX_LPAREN)
	{
		get_lex();
		Expression();
		if (current_type_of_lex == LEX_RPAREN)
		{
			get_lex();
		}
		else
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("')'"));
		}
	}
	else
	{
		throw Syntax_Error_Expression(scan.get_current_number_str());
	}
}
