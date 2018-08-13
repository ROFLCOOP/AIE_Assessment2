#include "DynamicArray.h"
#include <iostream>

int main()
{
	{
		DynamicArray arr;
		for (int i = 0; i < 10; ++i)
		{
			arr.pushBack(i);
		}

		arr.getAll();

		std::cout << "\n";

		int v = arr.getAt(3);

		std::cout << "Get at: " << v << "\n";


		arr.insertAt(5, 100);

		std::cout << "\n\nThe number 100 is put on the fifth index:\n" << std::endl;
		arr.getAll();

		std::cout << "\n\nArray is rotated once to the right:\n" << std::endl;
		arr.rotateArray(1); //should rotate the amount of times in the parenthesis, /should/ rotate the other way with negatives (but does not right now)

		arr.getAll();

		arr.removeAt(5);

		std::cout << "\n\nThe number of the fifth position is removed:\n" << std::endl;
		arr.getAll();

		std::cout << "\n\nThe number on the end is removed:\n" << std::endl;
		arr.popBack();

		arr.getAll();
		std::cout << "\n";
	}

	system("pause");
	return 0;
}

