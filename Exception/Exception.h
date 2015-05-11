#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "../String/String.h"
class Except
{
public:
	virtual String what() const throw() = 0;
	virtual ~Except() {}
};
class File_Open_Error : public Except
{
	String st;
public:
	File_Open_Error(const String &s) : st(s) {}
	virtual String what() const throw()
	{
		String tmp("File_Open_Error: '");
		tmp += st;
		tmp += String("' - file don't exist");
		return tmp;
	}
};

class Arguments_Error : public Except
{
	int argc;
public:
	Arguments_Error(int arg) : argc(arg) {}
	virtual String what() const throw()
	{
		String tmp("Arguments_Error: expected 1 arg (given ");
		tmp += String::int_to_str(argc-1);
		tmp += String(")");
		return tmp;
	}
};

class Lex_Error : public Except
{
	int n_str;
public:
	Lex_Error(int n) : n_str(n) {}
	int get_n_str() const { return n_str; }
};

class Lex_Error_Comment : public Lex_Error
{
public:
	Lex_Error_Comment(int n_str) : Lex_Error(n_str) {}
	virtual String what() const throw()
	{
		String tmp("Lex_Error: Error Comment ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		return tmp;
	}
};

class Lex_Error_String : public Lex_Error
{
public:
	Lex_Error_String(int n_str) : Lex_Error(n_str) {}
	virtual String what() const throw()
	{
		String tmp("Lex_Error: Error String ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		return tmp;
	}
};

class Lex_Error_Incorrect : public Lex_Error
{
public:
	Lex_Error_Incorrect(int n_str) : Lex_Error(n_str) {}
	virtual String what() const throw()
	{
		String tmp("Lex_Error: Incorrect symbol ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		return tmp;
	}
};

class Syntax_Error : public Except
{
	int n_str;
public:
	Syntax_Error(int n) : n_str(n) {}
	int get_n_str() const { return n_str; }
};

class Syntax_Error_Expected : public Syntax_Error
{
	String str;
public:
	Syntax_Error_Expected(int n, const String &st) : Syntax_Error(n), str(st) {}
	virtual String what() const throw()
	{
		String tmp("Syntax_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("Expected ") += str;
		return tmp;
	}
};

class Syntax_Error_Expression : public Syntax_Error
{
public:
	Syntax_Error_Expression(int n) : Syntax_Error(n) {}
	virtual String what() const throw()
	{
		String tmp("Syntax_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("invalid expression");
		return tmp;
	}
};

class Semantic_Error : public Except
{
	int n_str;
public:
	Semantic_Error(int n) : n_str(n) {}
	int get_n_str() const { return n_str; }
};

class Semantic_Error_Twise_Declare : public Semantic_Error
{
	String name;
public:
	Semantic_Error_Twise_Declare(int n, const String &str) : Semantic_Error(n), name(str) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("twice declare ");
		tmp += String("'") + name + String("'");
		return tmp;
	}
};

class Semantic_Error_Not_Declare : public Semantic_Error
{
	String name;
public:
	Semantic_Error_Not_Declare(int n, const String &str) : Semantic_Error(n), name(str) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("not declare " );
		tmp += String("'") + name + String("'");
		return tmp;
	}
};

class Semantic_Error_Read_Bool : public Semantic_Error
{
public:
	Semantic_Error_Read_Bool(int n) : Semantic_Error(n) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("bool not exist for read");
		return tmp;
	}
};

class Semantic_Error_Expected_Bool_Expression : public Semantic_Error
{
public:
	Semantic_Error_Expected_Bool_Expression(int n) : Semantic_Error(n) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("expected bool expression");
		return tmp;
	}
};

class Semantic_Error_Type_No_Equal : public Semantic_Error
{
public:
	Semantic_Error_Type_No_Equal(int n) : Semantic_Error(n) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("in assign type no equal");
		return tmp;
	}
};

class Semantic_Error_Operation_Do_Not_Exist : public Semantic_Error
{
public:
	Semantic_Error_Operation_Do_Not_Exist(int n) : Semantic_Error(n) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("operation do not exist");
		return tmp;
	}
};

class Semantic_Error_Loop : public Semantic_Error
{
	String word;
public:
	Semantic_Error_Loop(int n, const String &str) : Semantic_Error(n), word(str) {}
	virtual String what() const throw()
	{
		String tmp("Semantic_Error: ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		tmp += String(" : ");
		tmp += String("'") + word + String("' ");
		tmp += String("must be in loop");
		return tmp;
	}
};

class Divide_Zero : public Except
{
public:
	virtual String what() const throw()
	{
		String tmp("Runtime_Error: ");
		tmp += String("zero division");
		return tmp;
	}
};
#endif
