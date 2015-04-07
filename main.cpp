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
		Lex a;
		do
		{
			a = Scan.get_lex();
			cout << a.get_value_int();
		} while (a.get_type() != LEX_FINISH);
	}
	catch(const Arguments_Error &a)
	{
		cout << a.what() << argc-1 << a.what2() << endl;
	}
	catch(const exception &a) 
	{
		cout << a.what() << endl;
	}
	return 0;
}
