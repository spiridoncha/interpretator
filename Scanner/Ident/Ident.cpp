#include "Ident.h"
Ident::Ident(const Ident &id)
{
	char *name = new char[strlen(id.name) + 1];
	strcpy(name, id.name);
	declare = id.declare;
	type = id.type;
	assign = id.assign;
	value = id.value;
}
