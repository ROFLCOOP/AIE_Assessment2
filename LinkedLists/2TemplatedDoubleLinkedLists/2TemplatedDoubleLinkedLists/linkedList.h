#pragma once
#include <iostream>
#include <cassert>
#include <string>

template<typename T>
class LinkedList
{
private:
	struct linkedListNode
	{
		T data;
		linkedListNode* next = nullptr;
		linkedListNode* previous = nullptr;

	};
	bool listIsEmpty(bool makeNew, T data = 0);
	bool m_makeNew = true;

	linkedListNode* m_head;
	linkedListNode* m_tail;
	unsigned int m_listSize = 0;

public:
	LinkedList();
	~LinkedList();

	void pushFront(T data);
	void pushBack(T data);
	void insertValue(unsigned int iterator, T data);
	T first();
	T last();
	auto begin();
	auto end();
	int count();
	void erase(unsigned int iterator);
	void remove(T value);
	void popBack();
	void popFront();
	void clear();

	void printList();

};

template<typename T>
inline LinkedList<T>::LinkedList()
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	//clear();
}

template<typename T>
inline void LinkedList<T>::pushFront(T data)
{
	if (!listIsEmpty(m_makeNew, data))
	{
		linkedListNode* newNode = new linkedListNode;
		newNode->data = data;
		newNode->next = m_head;
		newNode->previous = nullptr;

		m_head->previous = newNode;
		m_head = newNode;
	}
	m_listSize++;
}

template<typename T>
inline void LinkedList<T>::pushBack(T data)
{
	if (!listIsEmpty(m_makeNew, data))
	{
		linkedListNode* newNode = new linkedListNode;
		newNode->data = data;
		newNode->previous = m_tail;
		newNode->next = nullptr;

		m_tail->next = newNode;
		m_tail = newNode;
	}
	m_listSize++;
}

template<typename T>
inline void LinkedList<T>::insertValue(unsigned int iterator, T data)
{
	assert(iterator > 0 && "RTFM(input value above 0");
	if (!listIsEmpty(m_makeNew, data))
	{
		if (iterator <= m_listSize / 2)
		{
			linkedListNode* current = m_head;
			for (unsigned int i = 0; i < iterator - 1; i++)
			{
				current = current->next;
			}
			linkedListNode* newNode = new linkedListNode;
			newNode->data = data;
			newNode->next = current->next;
			newNode->previous = current;
			newNode->next->previous = newNode;
			current->next = newNode;
		}
		else if (iterator > m_listSize / 2)
		{
			linkedListNode* current = m_tail;
			for (unsigned int i = 0; i < m_listSize - iterator - 1; i++)
			{
				current = current->previous;
			}
			linkedListNode* newNode = new linkedListNode;
			newNode->data = data;
			newNode->previous = current->previous;
			newNode->next = current;
			newNode->previous->next = newNode;
			current->previous = newNode;

		}
	}
	m_listSize++;
}

template<typename T>
inline auto LinkedList<T>::begin()
{
	return m_head;
}


template<typename T>
inline auto LinkedList<T>::end()
{
	return m_tail;
}

template<typename T>
inline T LinkedList<T>::first()
{
	return m_head->data;
}

template<typename T>
inline T LinkedList<T>::last()
{
	return m_tail->data;
}

template<typename T>
inline int LinkedList<T>::count()
{
	return m_listSize;
}

template<typename T>
inline void LinkedList<T>::erase(unsigned int iterator)
{
	assert(iterator > 0 && iterator < m_listSize && "RTFM(input value must be in range of the list");
	if (!listIsEmpty(!m_makeNew))
	{
		if (iterator <= m_listSize / 2)
		{
			linkedListNode* current = m_head;
			for (unsigned int i = 0; i < iterator; i++)
			{
				current = current->next;
			}
			current->next->previous = current->previous;
			current->previous->next = current->next;
			delete current;
		}
		else if (iterator > m_listSize / 2)
		{
			linkedListNode* current = m_tail;
			for (unsigned int i = 0; i < m_listSize - iterator - 1; i++)
			{
				current = current->previous;
			}
			current->next->previous = current->previous;
			current->previous->next = current->next;
			delete current;
	
		}
		m_listSize--;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

template<typename T>
inline void LinkedList<T>::remove(T value)
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		unsigned int delCount = 0;

		while (current->next != nullptr)
		{

			if (current->data == value)
			{
				linkedListNode* previous = current;
				current->previous->next = current->next;
				current->next->previous = current->previous;
				current = current->previous;
				delete previous;
				delCount++;
			}
			if (current->next != nullptr)
			{
				current = current->next;
			}
		}
		m_listSize -= delCount;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

template<typename T>
inline void LinkedList<T>::popBack()
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_tail;
		m_tail = current->previous;
		m_tail->next = current->next;

		delete current;

		m_listSize--;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

template<typename T>
inline void LinkedList<T>::popFront()
{
	if (!listIsEmpty(!m_makeNew))
	{
		linkedListNode* current = m_head;
		m_head = current->next;
		m_head->previous = current->previous;

		delete current;

		m_listSize--;
	}
	else
	{
		std::cout << "There's nothing in the list yet" << std::endl;
		system("pause");
	}
}

template<typename T>
inline void LinkedList<T>::clear()
{
	while (m_head->next != nullptr)
	{
		m_head = m_head->next;
		delete m_head->previous;

	}
	delete m_head;
	m_head = nullptr;
	m_tail = nullptr;
	m_listSize = 0;
}

template<typename T>
inline void LinkedList<T>::printList()
{
	linkedListNode* current = m_head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n" << std::endl;
}

template<typename T>
inline bool LinkedList<T>::listIsEmpty(bool makeNew, T data)
{
	bool listEmpty;
	if (m_listSize == 0 && makeNew)
	{
		m_head = new linkedListNode;
		m_head->data = data;
		m_head->next = nullptr;
		m_head->previous = nullptr;
		m_tail = m_head;
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
