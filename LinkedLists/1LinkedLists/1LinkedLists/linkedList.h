#pragma once

	struct linkedListNode
	{
		int data;
		linkedListNode* next;
	};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void pushFront(int data);
	void pushBack(int data);
	void insertValue(unsigned int iterator, int data);
	linkedListNode* begin();
	linkedListNode* end();
	int first();
	int last();
	int count();
	void erase(unsigned int iterator);
	void remove(int value);
	void popBack();
	void popFront();
	void clear();

	void printList();
private:
	bool listIsEmpty(bool makeNew, int data = 0);
	bool m_makeNew = true;

	linkedListNode* m_head;
	unsigned int m_listSize = 0;
};

