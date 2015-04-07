#include "Scanner/Scanner.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw(Arguments_Error());
		}
		Scanner Scan(argv[1]);
		cout << Scan.get_lex();
	}
	catch(const exception &a) 
	{
		cout << a.what() << endl;
	}
	return 0;
}
