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
		return "expected 1 argument (given 0)";
	}
};
#endif
