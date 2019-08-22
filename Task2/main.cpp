#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Fraction fraction, fraction2;
	fraction["num"] = 10;

	// Доповнити клас Дріб: у операторі індексування [] 
	// при невірному індексі викидати  виняток виду «Невірний індекс»
	cout << "fraction[\"index\"] = 5;" << endl;
	try
	{
		fraction["index"] = 5;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	//	При діленні на  дріб виду 0 / 10 викидати виняток з повідомленням про некоректне ділення
	cout << "fraction / fraction2" << endl;
	try
	{
		fraction / fraction2;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	//	Доповнити клас  Студент : 	у методі виставлення оцінки перевіряти оцінку 
	//	та номер оцінки на коректність та викидати винятки при невірних значеннях
	Student student(123, 3, new int[3]{ 0 }, "Student");
	cout << "student.SetMark(4, 10);" << endl;
	try
	{
		student.SetMark(4, 10);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	cout << "student.SetMark(2, 999);" << endl;
	try
	{
		student.SetMark(2, 999);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	system("pause");
	return 0;
}