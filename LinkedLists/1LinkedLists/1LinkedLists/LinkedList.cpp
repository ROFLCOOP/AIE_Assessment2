#include "linkedList.h"
#include <iostream>
#include <cassert>



LinkedList::LinkedList()
{
}


LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::pushFront(int data)
{
	if (!listIsEmpty(m_makeNew, data))
	{
		linkedListNode* newNode = new linkedListNode;
		newNode->data = data;
		newNode->next = m_head;

		m_head = newNode;
	}
	m_listSize++;
}

void LinkedList::pushBack(int data)
{
	if (!listIsEmpty(m_makeNew, data))
	{
		linkedListNode* current = m_head;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		linkedListNode* newNode = new linkedListNode;
		newNode->data = data;
		newNode->next = nullptr;
	
		current->next = newNode;
	}
	m_listSize++;
}

void LinkedList::insertValue(unsigned int iterator, int data)
{
	assert(iterator > 0 && "RTFM(input value above 0");
	if (!listIsEmpty(m_makeNew, data))
	{
		linkedListNode* current = m_head;
		for (unsigned int i = 0; i < iterator - 1; i++)
		{
			current = current->next;
			if (current->next == nullptr)
			{
				break;
			}
		}
		linkedListNode* newNode = new linkedListNode;
		newNode->data = data;
		newNode->next = current->next;
		current->next = newNode;
	}
	m_listSize++;
}

linkedListNode* LinkedList::begin()
{
	return m_head;
}

linkedListNode* LinkedList::end()
{
	linkedListNode* current = m_head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	return current;
}

int LinkedList::first()
{
	return m_head->data;
}

int LinkedList::last()
{
	linkedListNode* current = m_head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	return current->data;

	return 0;
}

int LinkedList::count()
{
	return m_listSize;
}

void LinkedList::erase(unsigned int iterator)
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		linkedListNode* previous = nullptr;
		for (unsigned int i = 0; i < iterator; i++)
		{
			previous = current;
			current = current->next;
//			assert(current->next != nullptr && "pick a value inside the list range")
			if (current->next == nullptr)
			{
				std::cout << iterator << " is not a valid iterator" << std::endl;
				return;
			}
		}
		previous->next = current->next;
		delete current;
		m_listSize--;
	}
}

void LinkedList::remove(int value)
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		linkedListNode* previous = nullptr;
		unsigned int delCount = 0;

		while (current->next != nullptr)
		{

			if (current->data == value)
			{
				previous->next = current->next;
				delete current;
				current = previous;
				delCount++;
			}
			previous = current;
			current = current->next;
		}
		m_listSize -= delCount;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

void LinkedList::popBack()
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		linkedListNode* previous = nullptr;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
		m_listSize--;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

void LinkedList::popFront()
{
	if(!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		m_head = current->next;
		delete current;
		m_listSize--;
	}
}

void LinkedList::clear()
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* previous = nullptr;
		while (m_head->next != nullptr)
		{
			linkedListNode* current = m_head;
			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;
			}
			delete current;
			previous->next = nullptr;
		}
		delete m_head;
		m_head = nullptr;
		m_listSize = 0;
	}
}



void LinkedList::printList()
{
	linkedListNode* current = m_head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n" << std::endl;
}

bool LinkedList::listIsEmpty(bool makeNew, int data)
{
	bool listEmpty;
	if (m_listSize == 0 && makeNew)
	{
		m_head = new linkedListNode;
		m_head->data = data;
		m_head->next = nullptr;
		listEmpty = true;
	}
	else if (m_listSize == 0 && !makeNew)
	{
		listEmpty = true;
	}
	else
	{
		listEmpty = false;
	}
	return listEmpty;
}
