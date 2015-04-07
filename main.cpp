#include "Scanner/Scanner.h"
#include <iostream>
using namespace std;
int main()
{
	try
	{
		Scanner Scan("qqq.txt");
		cout << Scan.get_lex();
	}
	catch(const exception &a) 
	{
		cout << a.what() << endl;
	}
	return 0;
}
