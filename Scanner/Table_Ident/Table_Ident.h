#ifndef TABLE_IDENT_H
#define TABLE_IDENT_H
#include "../Ident/Ident.h"
class Table_Ident {
  Ident *p;
  int size;
  int real_size;
  void re_size();
  Table_Ident(const Table_Ident &) {}

public:
  Table_Ident(int start_size = 4) : real_size(0) {
    p = new Ident[size = start_size];
  }
  ~Table_Ident() { delete[] p; }
  Ident &operator[](int k) { return p[k]; }
  int put(const char *);
};
#endif
