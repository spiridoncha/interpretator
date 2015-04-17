#include "Scanner/Scanner.h"
#include <iostream>
#include "Stack/Stack.h"
using namespace std;
int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw(Arguments_Error(argc));
		}
		Scanner Scan(argv[1]);
		Lex a;
		do
		{
			a = Scan.get_lex();
			cout << a << endl;
		} while (a.get_type() != LEX_FINISH);
	}
	catch (const Except &a)
	{
		cout << a.what() << endl;
	}
	catch (const char* str)
	{
		cout << "!!!" << str << endl;
	}
	return 0;
}
