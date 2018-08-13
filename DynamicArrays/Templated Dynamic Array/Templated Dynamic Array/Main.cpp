#include "DynamicArray.h"
#include <iostream>

void printAll(DynamicArray<int>& arr1, DynamicArray<int>& arr2) //compare the difference between 1 and 2, 1 is the original, 2 is the deviation
{
	system("pause");

	arr1.getAll();
	arr2.getAll();

	std::cout << std::endl;
}

int main()
{
	{
		DynamicArray<int> m_integArray;
		DynamicArray<int> m_integArray2;
		for (int i = 0; i < 16; i++)
		{
			m_integArray.pushBack(i);
		}
		m_integArray2 = m_integArray; // 2 will have the same numbers as 1 but changes made to one are not made to the other

		printAll(m_integArray, m_integArray2); // innitial print

		m_integArray2.insertAt(7, 100); // inserting the number 100 into array 2 at col 7

		printAll(m_integArray, m_integArray2);



	}

	system("pause");
	return 0;
}