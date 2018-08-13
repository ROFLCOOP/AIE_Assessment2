#include "linkedList.h"
#include <string>

int main()
{
	LinkedList<int> intList;
	LinkedList<char> charList;
	LinkedList<float> floatList;

	

	intList.pushFront(0);

	intList.pushBack(10);
	intList.pushBack(20);
	intList.pushBack(60);
	intList.pushBack(60);
	intList.pushBack(30);
	intList.pushBack(40);
	intList.pushBack(50);

	std::cout << intList.begin() << "\n"
		<< intList.end() << "\n"
		<< std::endl;

	intList.printList();

	intList.insertValue(2, 100);
	intList.insertValue(5, 100);

	intList.printList();

	intList.erase(5);
	intList.erase(2);

	intList.printList();

	intList.remove(60);

	intList.printList();

	intList.popFront();
	intList.popBack();

	intList.printList();

	std::cout << intList.first() << "\n"
		<< intList.last() << "\n"
		<< intList.count() << "\n" 
		<< intList.begin() << "\n"
		<< intList.end() << "\n"
		<< std::endl;


	intList.clear();

	intList.printList();

		system("pause");
	return 0;
}