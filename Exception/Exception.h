#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "../String/String.h"
class Except
{
	virtual String what() const throw() = 0;
};
class File_Open_Error : public Except
{
public:
	virtual String what() const throw()
	{
		String tmp("file don't exist");
		return tmp;
	}
};

class Arguments_Error : public String
{
public:
};

class Lex_Error : public Except
{
public:
};
#endif
