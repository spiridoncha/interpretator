#include "Scanner/Scanner.h"
#include <iostream>
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
			cout << a;
		} while (a.get_type() != LEX_FINISH);
	}
	catch(const File_Open_Error &a)
	{
		cout << a.what() << endl;
	}
	catch(const Arguments_Error &a)
	{
		cout << a.what() << endl;
	}
	return 0;
}
