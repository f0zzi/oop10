#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class WrongLengthException {};
class WrongDepthException {};
class WrongWidthException {};
class WrongTypeException {};

enum ResType { noType, lake, sea, ocean };

class Reservoir
{
private:
	char* name;
	ResType type;
	int width, length, depth;
	static int reservoirCount;
public:
	Reservoir() : Reservoir("No name", 0, 1, 1, 1) {};
	Reservoir(const char* name, int type, int width, int length, int depth);
	~Reservoir();

	void SetName(const char* name);

	void SetResType(int type);

	void SetWidth(int width);

	void SetLength(int length);

	void SetDepth(int depth);

	static int GetReservoirCount()
	{
		return reservoirCount;
	}
	void ShowFullInfo() const;

	const char* GetName() const
	{
		return this->name;
	}
	int GetWidth() const
	{
		return this->width;
	}
	int GetLength() const
	{
		return this->length;
	}
	int GetDepth() const
	{
		return this->depth;
	}
	ResType GetResType() const
	{
		return this->type;
	}
	int GetVolume() const
	{
		return this->width * this->length * this->depth;
	}
	int GetArea() const
	{
		return this->width * this->length;
	}
	static bool SameResType(const Reservoir& first, const Reservoir& second);

	static int GetBiggerAreaRes(const Reservoir& first, const Reservoir& second);

	static int GetBiggestFromArray(Reservoir** arr, ResType type);

	Reservoir& operator++();

	Reservoir operator++(int);
};

Reservoir& operator+(Reservoir& res, int number);