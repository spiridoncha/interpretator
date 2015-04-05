#include "Lex.h"
ostream& operator<<(ostream &out, Lex lex)
{
	out << '<' << lex.type_lex << ',' << lex.value_lex << '>';
	return out;
}
