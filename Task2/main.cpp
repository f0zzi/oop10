#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Fraction fraction, fraction2;
	fraction["num"] = 10;

	// ��������� ���� ���: � �������� ������������ [] 
	// ��� �������� ������ ��������  ������� ���� �������� ������
	cout << "fraction[\"index\"] = 5;" << endl;
	try
	{
		fraction["index"] = 5;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	//	��� ����� ��  ��� ���� 0 / 10 �������� ������� � ������������ ��� ���������� ������
	cout << "fraction / fraction2" << endl;
	try
	{
		fraction / fraction2;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	//	��������� ����  ������� : 	� ����� ����������� ������ ��������� ������ 
	//	�� ����� ������ �� ���������� �� �������� ������� ��� ������� ���������
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