#ifndef EXEC_H
#define EXEC_H
#include "../Poliz/Poliz.h"
#include "../Parser/Parser.h"
#include "../Stack/Stack.h"
#include "../Scanner/Table_Ident/Table_Ident.h"
#include "../String/String.h"
#include <iostream>

class Exec
{
	Lex elem;
public:
	void exec(Poliz &, Table_Ident &);
};

#endif
