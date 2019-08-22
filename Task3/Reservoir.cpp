#include "Reservoir.h"

int Reservoir::reservoirCount = 0;

Reservoir::Reservoir(const char* name, int type, int width, int length, int depth)
{
	SetWidth(width);
	SetLength(length);
	SetDepth(depth);
	SetName(name);
	SetResType(type);
	reservoirCount++;
}
Reservoir::~Reservoir()
{
	if (name != nullptr)
		delete[] name;
}
void Reservoir::SetName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Reservoir::SetResType(int type)
{
	switch (type)
	{
	case 0:
		this->type = noType;
		break;
	case 1:
		this->type = lake;
		break;
	case 2:
		this->type = sea;
		break;
	case 3:
		this->type = ocean;
		break;
	default:
		WrongTypeException ex;
		throw ex;
		break;
	}
}

void Reservoir::SetWidth(int width)
{
	if (width <= 0)
	{
		WrongWidthException ex;
		throw ex;
	}
	else
		this->width = width;
}

void Reservoir::SetLength(int length)
{
	if (length <= 0)
	{
		WrongLengthException ex;
		throw ex;
	}
	else
		this->length = length;
}

void Reservoir::SetDepth(int depth)
{
	if (depth <= 0)
	{
		WrongDepthException ex;
		throw ex;
	}
	else
		this->depth = depth;
}

void Reservoir::ShowFullInfo() const
{
	cout << "Name: " << GetName();
	cout << "  Type: ";
	switch (GetResType())
	{
	case 0:
		cout << "No type";
		break;
	case 1:
		cout << "lake";
		break;
	case 2:
		cout << "sea";
		break;
	case 3:
		cout << "ocean";
		break;
	default:
		cout << "Error.";
		break;
	}
	cout << "  Volume: " << GetVolume() << "  Area: " << GetArea() << endl;
}

bool Reservoir::SameResType(const Reservoir& first, const Reservoir& second)
{
	return first.GetResType() == second.GetResType();
}

int Reservoir::GetBiggerAreaRes(const Reservoir& first, const Reservoir& second)
{
	if (first.GetArea() > second.GetArea())
		return 1;
	else if (first.GetArea() < second.GetArea())
		return -1;
	else
		return 0;
}

int Reservoir::GetBiggestFromArray(Reservoir** arr, ResType type)
{
	int size = Reservoir::GetReservoirCount();
	int index = -1;
	int maxArea = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->GetResType() == type)
		{
			if (arr[i]->GetArea() > maxArea)
			{
				index = i;
				maxArea = arr[i]->GetArea();
			}
		}
	}
	return index;
}

Reservoir& Reservoir::operator++()
{
	width++;
	length++;
	depth++;
	return *this;
}

Reservoir Reservoir::operator++(int)
{
	Reservoir tmp(*this);
	++(*this);
	return tmp;
}

Reservoir& operator+(Reservoir& res, int number)
{
	if (number > 0)
	{
		res.SetWidth(res.GetWidth() + number);
		res.SetLength(res.GetLength() + number);
		res.SetDepth(res.GetDepth() + number);
	}
	return res;
}
