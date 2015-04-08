#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "../String/String.h"
class Except
{
	//virtual String what() const throw() = 0;
};
class File_Open_Error : public Except
{
public:
	//virtual String what() const throw()
	//{
	//	String tmp("File_Open_Error: file don't exist");
	//	return tmp;
	//}
};

class Arguments_Error : public String
{
	int argc;
public:
	//Arguments_Error(int arg = 0) : argc(arg) {}
	//virtual String what() const throw()
	//{
	//	String tmp("Arguments_Error: expected 1 arg (given");
		//tmp += String(argc).to_str();
	//	tmp += String(")");
	//	return tmp;
	//}
};

class Lex_Error : public Except
{
public:
};
#endif
