#include <iostream>
#include "Product.h"
using namespace std;

int main()
{
	Product test("tesjhdjfhdskjfhkdjshfkjsdhfkjdshfjkhdsfkjsdhkjfhsdkfhksdjhfkdsjfh1", 99.99, 99);

	BinSerializerProduct bin;
	//bin.writeProduct("test", test);
	Product* test2 = new Product;
	bin.readProduct("test", *test2);
	test2->Info();

	TxtSerializerProduct txt;
	txt.writeProduct("test2", test);
	Product* test3 = new Product;
	txt.readProduct("test2", *test3);
	test3->Info();

	system("pause");
	return 0;
}