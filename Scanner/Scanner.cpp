#include "Scanner.h"
int Scanner::look(const char *id, const char *list[]) const
{
	int i = 0;
	while(list[i])
	{
		if (!strcmp(id, list[i]))
		{
			return i;
		}
		++i;
	}
	return 0;
}

Lex Scanner::get_lex()
{
	int d, j;
	Current_State = H;
	ret = next;
	prev_number_str = current_number_str;
	id_expr = false;
	do
	{
		switch (Current_State)
		{
			case H:
				if (c_ch==' '||c_ch=='\n'||c_ch=='\r'||c_ch=='\t')
				{
					if (c_ch == '\n')
					{
						++current_number_str;
					}
					c_ch = File.get_char();
				}
				else if (isalpha(c_ch))
				{
					buf.clear();
					buf.add(c_ch);
					c_ch = File.get_char();
					Current_State = IDENT;
				}
				else if (c_ch == '{' || c_ch == '}')
				{
					buf.clear();
					buf.add(c_ch);
					c_ch = File.get_char();
					j = look(buf(), TW);
					unary_op = false;
					next = Lex(words[j], j);	
					if (ret.get_type() == LEX_ID && id_expr)
					{
						return Lex(LEX_ID_EXPR, ret.get_value_int());
					}
					return ret;
				}
				else if (isdigit(c_ch))
				{
					d = c_ch - '0';
					c_ch = File.get_char();
					Current_State = NUM;
				}
				else if (c_ch == '/')
				{
					c_ch = File.get_char();
					Current_State = COMMENT0;
				}
				else if ((c_ch == '<')||(c_ch == '>')||(c_ch == '='))
				{
					buf.clear();
					buf.add(c_ch);
					c_ch = File.get_char();
					Current_State = ALE;
				}
				else if (c_ch == '!')
				{
					buf.clear();
					buf.add(c_ch);
					c_ch = File.get_char();
					Current_State = NEQ;
				}
				else if (c_ch == '"')
				{
					buf.clear();
					c_ch = File.get_char();
					Current_State = STR;
				}
				else if (c_ch == EOF)
				{
					next = Lex(LEX_FINISH);
					if (ret.get_type() == LEX_ID && id_expr)
					{
						return Lex(LEX_ID_EXPR, ret.get_value_int());
					}
					return ret;
				}
				else
				{
					buf.clear();
					buf.add(c_ch);
					Current_State = DELIM;
				}
				break;
			case IDENT:
				if (isalpha(c_ch)||isdigit(c_ch))
				{
					buf.add(c_ch);
					c_ch = File.get_char();
				}
				else
				{
					unary_op = false;
					if ((j = look(buf(), TW)) != 0)
					{
						next = Lex(words[j], j);
						if (ret.get_type() == LEX_ID && id_expr)
						{
							return Lex(LEX_ID_EXPR, ret.get_value_int());
						}
						return ret;
					}
					else
					{
						j = TID.put(buf());
						next = Lex(LEX_ID, j);
						if (ret.get_type() == LEX_ID && id_expr)
						{
							return Lex(LEX_ID_EXPR, ret.get_value_int());
						}
						return ret;
					}
				}
				break;
			case NUM:
				if (isdigit(c_ch))
				{
					d = 10*d + (c_ch - '0');
					c_ch = File.get_char();
				}
				else
				{
					unary_op = false;
					next = Lex(LEX_NUM, d);
					if (ret.get_type() == LEX_ID && id_expr)
					{
						return Lex(LEX_ID_EXPR, ret.get_value_int());
					}
					return ret;
				}
				break;
			case COMMENT0:
				if (c_ch == '*')
				{
					c_ch = File.get_char();
					Current_State = COMMENT;
				}
				else
				{
					j = look("/", TD);
					unary_op = true;
					next = Lex(delims[j], j);
					if (ret.get_type() == LEX_ID && id_expr)
					{
						return Lex(LEX_ID_EXPR, ret.get_value_int());
					}
					return ret;
				}
				break;
			case COMMENT:
				if (c_ch == '*')
				{
					c_ch = File.get_char();
					Current_State = COMMENT1;
				}
				else if (c_ch == EOF)
				{
					throw Lex_Error_Comment(current_number_str);
				}
				else
				{
					c_ch = File.get_char();
				}
				break;
			case COMMENT1:
				if (c_ch == '/')
				{
					c_ch = File.get_char();
					Current_State = H;
				}
				else
				{
					c_ch = File.get_char();
					Current_State = COMMENT;
				}
				break;
			case ALE:
				if (c_ch == '=')
				{
					buf.add(c_ch);
					c_ch = File.get_char();
				}
				j = look(buf(), TD);
				unary_op = true;
				if (!strcmp(buf(), "="))
				{
					id_expr = true;
				}
				next = Lex(delims[j], j);
				if (ret.get_type() == LEX_ID && id_expr)
				{
					return Lex(LEX_ID_EXPR, ret.get_value_int());
				}
				return ret;
				break;
			case NEQ:
				if (c_ch == '=')
				{
					buf.add(c_ch);
					c_ch = File.get_char();
					j = look(buf(), TD);
					unary_op = true;
					next = Lex(LEX_NEQ, j);
					if (ret.get_type() == LEX_ID && id_expr)
					{
						return Lex(LEX_ID_EXPR, ret.get_value_int());
					}
					return ret;
				}
				else
				{
					throw Lex_Error_Incorrect(current_number_str);
				}
				break;
			case STR:
				while (c_ch != '"')
				{
					if (c_ch == '\\')
					{
						c_ch = File.get_char();
					}
					else if (c_ch == EOF)
					{
						throw Lex_Error_String(current_number_str);
					}
					buf.add(c_ch);
					c_ch = File.get_char();
				}
				c_ch = File.get_char();
				unary_op = false;
				next = Lex(LEX_CONST_STRING, 0, buf());
				if (ret.get_type() == LEX_ID && id_expr)
				{
					return Lex(LEX_ID_EXPR, ret.get_value_int());
				}
				return ret;
				break;
			case DELIM:
				if ((j = look(buf(), TD)) != 0)
				{
					c_ch = File.get_char();
					//TODO
					if (!strcmp(buf(), "+") && unary_op)
					{
						unary_op = true;
						next = Lex(LEX_UNARYPLUS, j);
						if (ret.get_type() == LEX_ID && id_expr)
						{
							return Lex(LEX_ID_EXPR, ret.get_value_int());
						}
						return ret;
					}
					else if (!strcmp(buf(), "-") && unary_op)
					{
						unary_op = true;
						next = Lex(LEX_UNARYMINUS, j);
						if (ret.get_type() == LEX_ID && id_expr)
						{
							return Lex(LEX_ID_EXPR, ret.get_value_int());
						}
						return ret;
					}
					else
					{
						unary_op = strcmp(buf(), ")") ? true : false;
						next = Lex(delims[j], j);
						if (ret.get_type() == LEX_ID && id_expr)
						{
							return Lex(LEX_ID_EXPR, ret.get_value_int());
						}
						return ret;
					}
				}
				else
				{
					throw Lex_Error_Incorrect(current_number_str);
				}
				break;
			default:
				throw "default in Scanner";
		}
	} while(true);
}

const char* Scanner::TW[] =
{
	"",
	"and",
	"{",
	"bool",
	"do",
	"else",
	"}",
	"if",
	"false",
	"int",
	"string",
	"not",
	"or",
	"program",
	"read",
	"then",
	"true",
	"while",
	"for",
	"write",
	"break",
	"continue",
	nullptr
};
const char* Scanner::TD[] =
{
	"",
	";",
	",",
	"=",
	"(",
	")",
	"==",
	"<",
	">",
	"+",
	"-",
	"*",
	"/",
	"%",
	"<=",
	"!=",
	">=",
	nullptr
};
type_of_lex Scanner::words[] =
{
	LEX_NULL,
	LEX_AND,
	LEX_BEGIN,
	LEX_BOOL,
	LEX_DO,
	LEX_ELSE,
	LEX_END,
	LEX_IF,
	LEX_FALSE,
	LEX_INT,
	LEX_STRING,
	LEX_NOT,
	LEX_OR,
	LEX_PROGRAM,
	LEX_READ,
	LEX_THEN,
	LEX_TRUE,
	LEX_WHILE,
	LEX_FOR,
	LEX_WRITE,
	LEX_BREAK,
	LEX_CONTINUE,
	LEX_NULL
};
type_of_lex Scanner::delims[] =
{
	LEX_NULL,
	LEX_SEMICOLON,
	LEX_COMMA,
	LEX_ASSIGN,
	LEX_LPAREN,
	LEX_RPAREN,
	LEX_EQ,
	LEX_LSS,
	LEX_GTR,
	LEX_PLUS,
	LEX_MINUS,
	LEX_TIMES,
	LEX_SLASH,
	LEX_PERCENT,
	LEX_LEQ,
	LEX_NEQ,
	LEX_GEQ,
	LEX_NULL
};
