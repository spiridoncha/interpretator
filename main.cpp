#include <iostream>
#include "Parser/Parser.h"
using namespace std;
int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw(Arguments_Error(argc));
		}
		//Scanner Scan(argv[1]);
		Parser Pars(argv[1]);
		Pars.analize();
		//Lex a;
		//do
		//{
		//	a = Scan.get_lex();
		//	cout << a << endl;
		//} while (a.get_type() != LEX_FINISH);
	}
	catch (const Except &a)
	{
		cout << a.what() << endl;
	}
	catch (const char* str)
	{
		cout << "!!!" << str << endl;
	}
	catch (const Lex &lex)
	{
		cout << "???" << lex << endl;
	}
	return 0;
}
