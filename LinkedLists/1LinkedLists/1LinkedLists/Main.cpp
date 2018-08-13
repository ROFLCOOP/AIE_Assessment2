#include <iostream>
#include "linkedList.h"

int main()
{
	{
		LinkedList linkedList;

		std::cout << "pushBack:" << std::endl;
		linkedList.pushBack(0);
		linkedList.pushBack(40);
		linkedList.pushBack(10);
		linkedList.pushBack(40);
		linkedList.pushBack(20);
		linkedList.pushBack(40);
		linkedList.pushBack(30);
		linkedList.pushBack(40);
		linkedList.pushBack(50);

		linkedList.printList();

		std::cout << "remove(40):" << std::endl;
		linkedList.remove(40);

		linkedList.printList();

		std::cout << "popBack:" << std::endl;
		linkedList.popBack();

		linkedList.printList();

		std::cout << "popFront:" << std::endl;
		linkedList.popFront();

		linkedList.printList();

		std::cout << "insertValue(500 @ 2):" << std::endl;
		linkedList.insertValue(2, 500);

		linkedList.printList();

		std::cout << "erase:" << std::endl;
		linkedList.erase(2);

		linkedList.printList();

		std::cout << "pushFront:" << std::endl;
		linkedList.pushFront(0);

		linkedList.printList();

		std::cout	<<	"First(value and the start of the list): \n"
					<<	linkedList.first()	<<	"\n"
					<<	"\nLast(value on the end of the list): \n"
					<<	linkedList.last()	<<	"\n"
					<<	"\nCount(amount of objects in the list): \n"
					<<	linkedList.count()	<<	"\n"
					<<	std::endl;


		std::cout << "clear(shouldn't print anything):" << std::endl;
		linkedList.clear();

		linkedList.printList();
	}

	system("pause");
	return 0;
}