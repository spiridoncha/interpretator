#include "Scanner.h"
int Scanner::look(const char *buf, char **list)
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
	int d, j;
	Current_State = H;
	do
	{
		
	} while(true);
}
