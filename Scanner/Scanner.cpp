#include "Scanner.h"
int Scanner::look(const char *buf, const char *list[])
{
	int i = 0;
	while(list[i])
	{
		if (!strcmp(buf, list[i]))
		{
			return i;
		}
		++i;
	}
	return 0;
}

Lex Scanner::get_lex()
{
	//int d, i;
	//Current_State = H;
	//do
	//{
	//	
	//} while(true);
	const char *p = "while";
	int i;
	if ((i = look(p, TW)) != 0)
		return Lex(words[i], i);
	else
		return Lex();
}
