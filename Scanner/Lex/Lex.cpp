#include "Lex.h"
std::ostream &operator<<(std::ostream &out, Lex lex) {
  out << '<' << lex.type_lex << ',' << lex.value_lex << ',' << lex.str << '>';
  return out;
}
