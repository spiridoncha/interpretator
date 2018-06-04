#include "Ident.h"
Ident &Ident::operator=(const Ident &Id) {
  if (Id.name != nullptr) {
    name = new char[strlen(Id.name) + 1];
    strcpy(name, Id.name);
  }
  assign = Id.assign;
  declare = Id.declare;
  type = Id.type;
  value = Id.value;
  str = Id.str;
  return *this;
}
