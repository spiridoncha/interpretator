#include "Interpretator.h"
void Interpretator::interpretation()
{
	Table_Ident &TID = pars.get_Scan().get_TID();
	pars.analize();
	exec.exec(pars.prog, TID);
}
