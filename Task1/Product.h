#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product
{
private:
	string name;
	double price = 0;
	int quantity = 0;
public:
	Product() :Product("Product", 0, 0) {}
	Product(string name, double price, int quantity)
	{
		SetName(name);
		SetPrice(price);
		SetQuantity(quantity);
	}
	Product(const Product& other)
	{
		this->price = other.price;
		this->quantity = other.quantity;
		this->SetName(other.GetName());
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName() const
	{
		return name;
	}
	void SetPrice(double price)
	{
		if (price >= 0)
			this->price = price;
	}
	double GetPrice() const
	{
		return price;
	}
	void SetQuantity(int quantity)
	{
		if (quantity >= 0)
			this->quantity = quantity;
	}
	int GetQuantity() const
	{
		return quantity;
	}
	void Info() const
	{
		cout << "Product: " << name << "\tPrice: " << price << "\tQuantity: " << quantity << endl;
	}
};

class TxtSerializerProduct //- для збереження та відновлення екземпляру продукту у(з) текстовому(го) файлі(у)
{
public:
	void writeProduct(string filename, const Product& p)
	{
		int pos = filename.find(".");
		if (pos == string::npos)
			filename += ".txt";
		ofstream out(filename, ios::out);
		if (!out)
			cerr << "Error opening file " << filename << " for writing" << endl;
		else
		{
			out << p.GetName() << endl;
			out << p.GetPrice() << endl;
			out << p.GetQuantity() << endl;
		}
		out.close();
	}
	void readProduct(string filename, Product& p)
	{
		int pos = filename.find(".");
		if (pos == string::npos)
			filename += ".txt";
		ifstream in(filename, ios::in);
		if (!in)
			cerr << "Error opening file " << filename << " for reading" << endl;
		else
		{
			string name;
			double price;
			int quantity;
			in >> name >> price >> quantity;
			p.SetName(name.data());
			p.SetPrice(price);
			p.SetQuantity(quantity);
		}
		in.close();
	}
};

class BinSerializerProduct //- для збереження та відновлення екземпляру продукту у(з) бінарному(го) файлі(у)
{
public:
	void writeProduct(string filename, const Product& p)
	{
		int pos = filename.find(".");
		if (pos == string::npos)
			filename += ".dat";
		ofstream out(filename, ios_base::binary);
		if (!out)
			cerr << "Error opening file " << filename << endl;
		else
		{
			double price = p.GetPrice();
			int quantity = p.GetQuantity();
			int size = p.GetName().size();
			out.write((char*)& size, sizeof(size));
			out.write((char*) p.GetName().data(), size * sizeof(char));
			out.write((char*)& price, sizeof(price));
			out.write((char*)& quantity, sizeof(quantity));
		}
	}
	void readProduct(string filename, Product& p)
	{
		int pos = filename.find(".");
		if (pos == string::npos)
			filename += ".dat";
		ifstream in(filename, ios_base::binary);
		if (!in)
			cerr << "Error opening file " << filename << endl;
		else
		{
			double price;
			int quantity;
			int size;
			in.read((char*)& size, sizeof(int));
			char* tmp = new char[size + 1];
			in.read((char*) tmp, size * sizeof(char));
			tmp[size] = '\0';
			in.read((char*)& price, sizeof(price));
			in.read((char*)& quantity, sizeof(quantity));
			p.SetName(tmp);
			p.SetPrice(price);
			p.SetQuantity(quantity);
		}
	}
};