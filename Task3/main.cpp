#include <iostream>
#include "Reservoir.h"
using namespace std;

int main()
{
	Reservoir reservoir;
	try
	{
		reservoir.SetResType(-1);
	}
	catch (WrongTypeException)
	{
		cout << "Wrongtype exception" << endl;
	}
	try
	{
		reservoir.SetDepth(-1);
	}
	catch (WrongDepthException)
	{
		cout << "Wrongdepth exception" << endl;
	}
	try
	{
		reservoir.SetWidth(-1);
	}
	catch (WrongWidthException)
	{
		cout << "Wrongwidth exception" << endl;
	}
	try
	{
		reservoir.SetLength(-1);
	}
	catch (WrongLengthException)
	{
		cout << "Wronglength exception" << endl;
	}
	system("pause");
	return 0;
}