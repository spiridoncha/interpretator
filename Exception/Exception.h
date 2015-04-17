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
	virtual String what() const throw()
	{
		String tmp("Lex_Error ");
		tmp += String("in str: ");
		tmp += String::int_to_str(get_n_str());
		return tmp;
	}
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
#endif
