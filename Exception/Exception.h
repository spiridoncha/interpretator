#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
class File_Open_Error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "file don't exist";
	}
};

class Arguments_Error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "expected 1 argument (given ";
	}
	const char* what2() const throw()
	{
		return ")";
	}
};

class Lex_Error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Lex_Error";
	}
};
#endif
