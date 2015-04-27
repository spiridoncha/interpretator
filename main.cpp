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
		Parser Pars(argv[1]);
		Pars.analize();
	}
	catch (const Except &a)
	{
		cout << a.what() << endl;
	}
	catch(const char *a)
	{
		cout << a << endl;
	}
	return 0;
}
