#include "Classes.h"

Fraction::Fraction(int numerator, int denominator) :numerator(numerator)
{
	SetDenom(denominator);
}

void Fraction::SetDenom(int denominator)
{
	if (denominator == 0)
	{
		this->denominator = 1;
		return;
	}
	this->denominator = denominator;
	if (denominator < 0)
	{
		this->numerator *= -1;
		this->denominator = -this->denominator;
	}
}

void Fraction::Show()
{
	if (denominator > 1)
		this->Normalize();
	cout << numerator;
	if (denominator != 1 && numerator != 0)
		cout << "/" << denominator;
	cout << endl;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	if (other.numerator == 0)
		throw "Error. Division by zero. Result is reset to zero.\n";
	else
		return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);
}

void Fraction::Normalize()
{
	int tmp = (numerator < 0 ? -numerator : numerator);
	int min = (tmp < denominator ? tmp : denominator);
	int divider = 1;
	for (int i = 2; i <= min; i++)
	{
		if (numerator % i == 0 && denominator % i == 0)
			divider = i;
	}
	if (divider > 1)
	{
		numerator /= divider;
		denominator /= divider;
	}
}

int& Fraction::operator[](const char* element)
{
	if (!strcmp("num", element))
		return numerator;
	else if (!strcmp("denom", element))
		return denominator;
	else
		throw "Invalid index\n";
}

Fraction& operator--(Fraction& fraction)
{
	fraction = fraction - Fraction(1, 1);
	return fraction;
}

Fraction operator--(Fraction& fraction, int)
{
	Fraction tmp(fraction);
	fraction = --fraction;
	return tmp;
}

Fraction operator-(const Fraction& fraction, int number)
{
	return fraction - Fraction(number);
}

Fraction operator-(int number, const Fraction& fraction)
{
	Fraction tmp = Fraction(number) - fraction;
	return tmp;
}

Student::Student() : Student(00000, 0, nullptr, "None") {}

Student::Student(int recordBook, int marksQuantity, int* marks, const char* surname) :
	recordBook(recordBook), marksQuantity(marksQuantity)
{
	this->marks = marks;
	int size = strlen(surname) + 1;
	this->surname = new char[size];
	strcpy_s(this->surname, size, surname);
}

Student::Student(const Student& other) :
	Student(recordBook, marksQuantity, marks, surname) {}

Student::~Student()
{
	if (surname != nullptr)
		delete[] surname;
	if (marks != nullptr)
		delete[] marks;
}

void Student::ShowMarks() const
{
	if (marks != nullptr && marksQuantity > 0)
	{
		cout << "\t    Subjects/marks  ";
		for (int i = 0; i < marksQuantity; i++)
		{
			cout << i + 1 << ":" << setw(3) << marks[i] << "  ";
		}
		cout << endl;
	}
	else
		cout << "\t    ----Student has no marks----\n";
}

void Student::SetSurname(const char* surname)
{
	if (this->surname != nullptr)
		delete[] this->surname;
	int size = strlen(surname) + 1;
	this->surname = new char[size];
	strcpy_s(this->surname, size, surname);
}

void Student::ShowFullInfo() const
{
	cout << "Surname: " << setw(11) << GetSurname() << "   Record book #" << GetRecordBook() << "\tAvarage mark: " << setprecision(4) << GetAvarageMark() << endl;
	ShowMarks();
}

double Student::GetAvarageMark() const
{
	if (marks != nullptr && marksQuantity > 0)
	{
		int sum = 0;
		for (int i = 0; i < marksQuantity; i++)
		{
			sum += marks[i];
		}
		return (double)sum / marksQuantity;
	}
	else
		return 0;
}

void Student::SetMark(int subjectIndex, int mark)
{
	if (subjectIndex > marksQuantity - 1 || subjectIndex < 0)
		throw "Invalid subject index.\n";
	else if (mark > markMaxLimit || mark < markMinLimit)
		throw "Invalid mark.\n";
	else
		marks[subjectIndex] = mark;
}

void Student::AddMark(int mark)
{
	if (mark > markMaxLimit || mark < markMinLimit)
	{
		cout << "\nInvalid mark.\n";
		system("pause");
	}
	else
	{
		int* tmp = marks;
		marks = new int[marksQuantity + 1];
		for (int i = 0; i < marksQuantity; i++)
		{
			marks[i] = tmp[i];
		}
		delete[] tmp;
		marks[marksQuantity++] = mark;
	}
}

void Student::RemoveMark(int subjectIndex)
{
	if (marksQuantity == 0 || marks == nullptr)
	{
		cout << "Error. Student has no marks.\n";
		system("pause");
	}
	else if (subjectIndex > marksQuantity || subjectIndex <= 0)
	{
		cout << "\nInvalid subject index.\n";
		system("pause");
	}
	else
	{
		int* tmp = marks;
		marks = new int[marksQuantity - 1];
		for (int i = 0, j = 0; i < marksQuantity; i++)
		{
			if (i != subjectIndex - 1)
				marks[j++] = tmp[i];
		}
		delete[] tmp;
		marksQuantity--;
	}
}