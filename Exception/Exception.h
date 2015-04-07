#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#pragma once
class File_Open_Error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "file don't exist";
	}
};
#endif
