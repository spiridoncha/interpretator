#include "Interpretator/Interpretator.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      throw Arguments_Error(argc);
    }
    Interpretator inter(argv[1]);
    inter.interpretation();
  } catch (const Except &a) {
    cout << a.what() << endl;
  }
  return 0;
}
