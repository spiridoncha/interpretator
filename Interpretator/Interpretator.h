#ifndef INTERPRETATOR_h
#define INTERPRETATOR_h
#include "../Exec/Exec.h"
#include "../Parser/Parser.h"
#include "../Scanner/Table_Ident/Table_Ident.h"
class Interpretator {
  Parser pars;
  Exec exec;

public:
  Interpretator(char *prog) : pars(prog) {}
  void interpretation();
};
#endif
