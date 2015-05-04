#include "Parser.h"
#include <iostream>

void Parser::analize()
{
	get_lex();
	Program();
	prog.out();
	std::cout << "yeah!!!" << std::endl;
}

void Parser::Program()
{
	get_lex();//first lex is implicit LEX_NULL
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
	Operators(false, 0);
}

void Parser::Descriptions()
{
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
	if (current_type_of_lex == LEX_ID || current_type_of_lex == LEX_ID_EXPR)
	{
		bool minus = false;
		int id = current_value_int_of_lex;
		Ident& id_in_table = scan.get_TID()[id];
		declare(LEX_INT);
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			assign_in_description(id);
			get_lex();
			if (current_type_of_lex == LEX_UNARYPLUS || current_type_of_lex == LEX_UNARYMINUS)
			{
				if (current_type_of_lex == LEX_UNARYMINUS)
				{
					minus = true;
				}
				get_lex();
			}
			if (current_type_of_lex == LEX_NUM)
			{
				if (minus)
				{
					id_in_table.put_value(-current_value_int_of_lex);
				}
				else
				{
					id_in_table.put_value(current_value_int_of_lex);
				}
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
	if (current_type_of_lex == LEX_ID || current_type_of_lex == LEX_ID_EXPR)
	{
		int id = current_value_int_of_lex;
		Ident& id_in_table = scan.get_TID()[id];
		declare(LEX_STRING);
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			assign_in_description(id);
			get_lex();
			if (current_type_of_lex == LEX_CONST_STRING)
			{
				id_in_table.put_value(current_value_str_of_lex);
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
	if (current_type_of_lex == LEX_ID || current_type_of_lex == LEX_ID_EXPR)
	{
		int id = current_value_int_of_lex;
		Ident& id_in_table = scan.get_TID()[id];
		declare(LEX_BOOL);
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			assign_in_description(id);
			get_lex();
			if (current_type_of_lex == LEX_TRUE || current_type_of_lex == LEX_FALSE)
			{
				id_in_table.put_value(current_value_int_of_lex);
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

void Parser::Operators(bool loop, int continue_point = 0)
{
	if (!Operator(loop, continue_point))
	{
		return;
	}
	while (true)
	{
		if (!Operator(loop, continue_point))
		{
			break;
		}
	}
}

void Parser::Begin_End(bool loop, int continue_point = 0)
{
	if (current_type_of_lex == LEX_BEGIN)
	{
		get_lex();
		Operators(loop, continue_point);
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
		if (!Operator(loop, continue_point))
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String("operator"));
		}
	}
}

bool Parser::Operator(bool loop, int continue_point = 0)
{
	int place_0, place_1, place_2, place_3;
	if (current_type_of_lex == LEX_IF)
	{
		get_lex();
		if (current_type_of_lex == LEX_LPAREN)
		{
			get_lex();
			Expression();
			eq_bool();
			place_2 = prog.get_free();
			prog.blank();
			prog.put_lex(Lex(POLIZ_CONDITION_GO));
			if (current_type_of_lex == LEX_RPAREN)
			{
				get_lex();
				Begin_End(false);
				place_3 = prog.get_free();
				prog.blank();
				prog.put_lex(Lex(POLIZ_GO));
				prog.put_lex(Lex(POLIZ_LABEL, prog.get_free()), place_2);
				if (current_type_of_lex == LEX_ELSE)
				{
					get_lex();
					Begin_End(false);
					prog.put_lex(Lex(POLIZ_LABEL, prog.get_free()), place_3);
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
			place_0 = prog.get_free();
			Expression();
			eq_bool();
			place_1 = prog.get_free();
			prog.blank();
			prog.put_lex(Lex(POLIZ_CONDITION_GO));
			if (current_type_of_lex == LEX_RPAREN)
			{
				get_lex();
				Begin_End(true);
				prog.put_lex(Lex(POLIZ_LABEL, place_0));
				prog.put_lex(Lex(POLIZ_GO));
				prog.put_lex(Lex(POLIZ_CONDITION_GO, prog.get_free()), place_1);
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
				check_id_in_read();
				prog.put_lex(Lex(POLIZ_ADDRESS, current_value_int_of_lex));
				get_lex();
				if (current_type_of_lex == LEX_RPAREN)
				{
					get_lex();
					prog.put_lex(Lex(LEX_READ));
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
			Sequence_Of_Expressions();
			if (current_type_of_lex == LEX_RPAREN)
			{
				get_lex();
				prog.put_lex(Lex(LEX_WRITE));
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
		place_0 = prog.get_free();
		Begin_End(true);
		if (current_type_of_lex == LEX_WHILE)
		{
			get_lex();
			if (current_type_of_lex == LEX_LPAREN)
			{
				get_lex();
				Expression();
				eq_bool();
				place_1 = prog.get_free();
				prog.blank();
				prog.put_lex(Lex(POLIZ_CONDITION_GO));
				prog.put_lex(Lex(POLIZ_LABEL, place_0));
				prog.put_lex(Lex(POLIZ_GO));
				prog.put_lex(Lex(POLIZ_LABEL, prog.get_free()), place_1);
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
	else if (current_type_of_lex == LEX_ID_EXPR)
	{
		check_id_in_assign();
		prog.put_lex(Lex(POLIZ_ADDRESS, current_value_int_of_lex));
		get_lex();
		if (current_type_of_lex == LEX_ASSIGN)
		{
			get_lex();
			Expression();
			eq_type();
			prog.put_lex(Lex(LEX_ASSIGN));
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
	else if (current_type_of_lex == LEX_BREAK)
	{
		if (!loop)
		{
			throw Semantic_Error_Loop(scan.get_current_number_str(), String("break"));
		}
		//TODO
		get_lex();
		if (current_type_of_lex != LEX_SEMICOLON)
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String(";"));
		}
		get_lex();
		return true;
	}
	else if (current_type_of_lex == LEX_CONTINUE)
	{
		//TODO
		if (!loop)
		{
			throw Semantic_Error_Loop(scan.get_current_number_str(), String("continue"));
		}
		get_lex();
		if (current_type_of_lex != LEX_SEMICOLON)
		{
			throw Syntax_Error_Expected(scan.get_current_number_str(), String(";"));
		}
		get_lex();
		return true;
	}
	else
	{
		return false;
	}
}

void Parser::For_In_Parens()
{
	//TODO
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
		eq_bool();
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
		Begin_End(true);
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
		get_lex();
		Expression();
		prog.put_lex(Lex(POLIZ_SEQ_WRITE));
	}
}

void Parser::Expression()
{
	//TODO
	if (current_type_of_lex == LEX_ID_EXPR)
	{
		check_id_in_assign();
		prog.put_lex(Lex(POLIZ_ADDRESS, current_value_int_of_lex));
		get_lex();	
		while (current_type_of_lex == LEX_ASSIGN)
		{
			//TODO
			st_lex.push(current_type_of_lex);
			get_lex();
			Expression();
			check_op();
		}
	}
	else
	{
		Expression1();
	}
}

void Parser::Expression1()
{
	Expression2();
	while (current_type_of_lex == LEX_OR)
	{
		st_lex.push(current_type_of_lex);
		get_lex();
		Expression2();
		check_op();
	}
}

void Parser::Expression2()
{
	Expression3();
	while (current_type_of_lex == LEX_AND)
	{
		st_lex.push(current_type_of_lex);
		get_lex();
		Expression3();
		check_op();
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
		st_lex.push(current_type_of_lex);
		get_lex();
		Expression4();
		check_op();
	}
		
}

void Parser::Expression4()
{
	Expression5();
	while (current_type_of_lex == LEX_PLUS || current_type_of_lex == LEX_MINUS)
	{
		st_lex.push(current_type_of_lex);
		get_lex();
		Expression5();
		check_op();
	}
}

void Parser::Expression5()
{
	Expression6();
	while (current_type_of_lex == LEX_TIMES || current_type_of_lex == LEX_SLASH || current_type_of_lex == LEX_PERCENT)
	{
		st_lex.push(current_type_of_lex);
		get_lex();
		Expression6();
		check_op();
	}
}

void Parser::Expression6()
{
	if (current_type_of_lex == LEX_NOT)
	{
		get_lex();
		Expression6();
		check_not();
	}
	else if (current_type_of_lex == LEX_UNARYMINUS || current_type_of_lex == LEX_UNARYPLUS)
	{
		type_of_lex type_lex = current_type_of_lex;
		get_lex();
		Expression6();
		check_unary_p_m(type_lex);
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
		check_id();
		prog.put_lex(Lex(LEX_ID, current_value_int_of_lex));
		get_lex();
	}
	else if (current_type_of_lex == LEX_NUM)
	{
		st_lex.push(LEX_INT);
		prog.put_lex(current_lex);
		get_lex();
	}
	else if (current_type_of_lex == LEX_CONST_STRING)
	{
		st_lex.push(LEX_STRING);
		prog.put_lex(current_lex);
		get_lex();
	}
	else if (current_type_of_lex == LEX_TRUE)
	{
		st_lex.push(LEX_BOOL);
		prog.put_lex(Lex(LEX_TRUE, 1));
		get_lex();
	}
	else if (current_type_of_lex == LEX_FALSE)
	{
		st_lex.push(LEX_BOOL);
		prog.put_lex(Lex(LEX_FALSE, 0));
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

void Parser::declare(type_of_lex type)
{
	Ident &id = scan.get_TID()[current_value_int_of_lex];
	if (id.get_declare())
	{
		throw Semantic_Error_Twise_Declare(scan.get_current_number_str(), String(id.get_name()));
	}
	else
	{
		id.put_declare();
		id.put_type(type);
	}
}

void Parser::assign_in_description(int i)
{
	Ident &id = scan.get_TID()[i];
	id.put_assign();
}

void Parser::check_id()
{
	Ident &id = scan.get_TID()[current_value_int_of_lex];
	if (!id.get_declare())
	{
		throw Semantic_Error_Not_Declare(scan.get_current_number_str(), String(id.get_name()));
	}
	else if (!id.get_assign())
	{
		std::cout << String("WARNING: variable ") << String(id.get_name()) << String(" don't assign ") << String("in str: ") << String::int_to_str(scan.get_current_number_str())<< std::endl;
		st_lex.push(id.get_type());
	}
	else
	{
		st_lex.push(id.get_type());
	}
}


void Parser::check_id_in_read()
{
	Ident &id = scan.get_TID()[current_value_int_of_lex];
	if (!id.get_declare())
	{
		throw Semantic_Error_Not_Declare(scan.get_current_number_str(), String(id.get_name()));
	}
	else if (id.get_type() == LEX_BOOL)
	{
		throw Semantic_Error_Read_Bool(scan.get_current_number_str());
	}
	else if (!id.get_assign())
	{
		id.put_assign();
	}
}

void Parser::check_id_in_assign()
{
	Ident &id = scan.get_TID()[current_value_int_of_lex];
	if (!id.get_declare())
	{
		throw Semantic_Error_Not_Declare(scan.get_current_number_str(), String(id.get_name()));
	}
	else
	{
		id.put_assign();
		st_lex.push(id.get_type());
	}
}

void Parser::eq_type()
{
	if (st_lex.pop() != st_lex.pop())
	{
		throw Semantic_Error_Type_No_Equal(scan.get_current_number_str());
	}
}

void Parser::eq_bool()
{
	if (st_lex.pop() != LEX_BOOL)
	{
		throw Semantic_Error_Expected_Bool_Expression(scan.get_current_number_str());
	}
}

void Parser::check_op()
{
	type_of_lex a, b, aOPb, ret;
	bool condition_int, condition_int_compare, condition_bool, condition_string, condition_string_compare;
	bool i, s, bl;
	a = st_lex.pop();
	aOPb = st_lex.pop();
	b = st_lex.pop(); 
	condition_string = (aOPb == LEX_PLUS) || (aOPb == LEX_ASSIGN);
	condition_int = condition_string || (aOPb == LEX_MINUS) || (aOPb == LEX_SLASH) || (aOPb == LEX_TIMES) || (aOPb == LEX_PERCENT);
	condition_bool = (aOPb == LEX_OR) || (aOPb == LEX_AND);
	condition_string_compare = (aOPb == LEX_EQ) || (aOPb == LEX_NEQ) || (aOPb == LEX_LSS) || (aOPb == LEX_GTR);
	condition_int_compare = condition_string_compare || (aOPb == LEX_LEQ) || (aOPb == LEX_GEQ);
	i = (a == LEX_INT) && (b == LEX_INT);
	s = (a == LEX_STRING) && (b == LEX_STRING);
	bl = (a == LEX_BOOL) && (b == LEX_BOOL);
	if (condition_string && s)
		ret = LEX_STRING;
	else if (condition_int && i)
		ret = LEX_INT;
	else if (condition_bool && bl)
		ret = LEX_BOOL;
	else if (condition_int_compare && i)
		ret = LEX_BOOL;
	else if (condition_string_compare && s)
		ret = LEX_BOOL;
	else
		throw Semantic_Error_Operation_Do_Not_Exist(scan.get_current_number_str());
	st_lex.push(ret);
	prog.put_lex(Lex(aOPb));
}

void Parser::check_not()
{
	if (st_lex.pop() != LEX_BOOL)
	{
		throw Semantic_Error_Operation_Do_Not_Exist(scan.get_current_number_str());
	}
	else
	{
		st_lex.push(LEX_BOOL);
	}
	prog.put_lex(Lex(LEX_NOT));
}

void Parser::check_unary_p_m(type_of_lex a)
{
	if (st_lex.pop() != LEX_INT)
	{
		throw Semantic_Error_Operation_Do_Not_Exist(scan.get_current_number_str());
	}
	else
	{
		st_lex.push(LEX_INT);
	}
	prog.put_lex(Lex(a));
}
