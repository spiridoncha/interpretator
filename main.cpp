#include <iostream>
#include "Interpretator/Interpretator.h"
using namespace std;
int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw(Arguments_Error(argc));
		}
		Interpretator inter(argv[1]);
		inter.interpretation();
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
