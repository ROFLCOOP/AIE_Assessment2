#pragma once
#include <cassert>
#include <iostream>


template<typename arrType>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const DynamicArray& other);
	~DynamicArray();
	DynamicArray& operator=(const DynamicArray& other);

	void pushBack(arrType value);
	void popBack();
	int getAt(unsigned int index);
	void getAll();
	void rotateArray(int rotateAmount);
	void insertAt(unsigned int index, arrType value);
	void removeAt(unsigned int index);


private:
	bool isFull() const;
	void resizeArray(unsigned int newMaxAmount);
	int getAmount() const;

	const int initSize = 10;
	unsigned int m_maxSize;
	unsigned int m_currentSize;
	arrType* m_contents;
};

template<typename arrType>
DynamicArray<arrType>::DynamicArray()
{
	m_maxSize = initSize;
	m_contents = new arrType[m_maxSize];
}

template<typename arrType>
DynamicArray<arrType>::DynamicArray(const DynamicArray & other)
{
	m_currentSize	= other.m_currentSize;
	m_maxSize		= other.m_maxSize;

	m_contents		= new arrType[m_maxSize];
	for (int i = 0; i < m_currentSize; i++)
	{
		m_contents[i] = other.m_contents[i];
	}

}

template<typename arrType>
DynamicArray<arrType>::~DynamicArray()
{
	delete[] m_contents;
}

template<typename arrType>
DynamicArray<arrType> & DynamicArray<arrType>::operator=(const DynamicArray & other)
{
	if (m_maxSize != other.m_maxSize)
	{
		delete[] m_contents;
		m_maxSize = other.m_maxSize;
		m_contents = new arrType[m_maxSize];
	}

	m_currentSize = other.m_currentSize;
	for (int i = 0; i < m_currentSize; ++i)
	{
		m_contents[i] = other.m_contents[i];
	}

	return *this;
}

template<typename arrType>
inline void DynamicArray<arrType>::pushBack(arrType value)
{
	if (isFull())
	{
		resizeArray(m_maxSize * 2);
	}

	m_contents[m_currentSize] = value;
	m_currentSize++;
}

template<typename arrType>
inline void DynamicArray<arrType>::popBack()
{
	assert(m_currentSize > 0 && "Array is too Small");
	m_currentSize -= 1;
}

template<typename arrType>
inline int DynamicArray<arrType>::getAt(unsigned int index)
{
	assert(index < m_currentSize && index >= 0 && "Please use a valid index");
	return m_contents[index];
}

template<typename arrType>
inline void DynamicArray<arrType>::getAll()
{
	for (unsigned int i = 0; i < m_currentSize; i++)
	{
		std::cout << getAt(i) << " ";
	}
	std::cout << std::endl;
}

template<typename arrType>
inline void DynamicArray<arrType>::rotateArray(int rotateAmount)
{

}

template<typename arrType>
inline void DynamicArray<arrType>::insertAt(unsigned int index, arrType value)
{
	if (m_maxSize = m_currentSize + 1)
	{
		resizeArray(m_maxSize * 2);
	}

	if (index < m_currentSize)
	{
		pushBack(m_contents[m_currentSize - 1]);
		for (unsigned int i = m_currentSize; i >= index; i--)
		{
			m_contents[i] = m_contents[i - 1];
		}
		m_contents[index] = value;
	}
	else if (index >= m_currentSize && index < m_maxSize)
	{
		pushBack(value); //adds the value to the end of the array instead of the exact index
		std::cout << "Index higher than currentSize, number was added to the end of the array" << std::endl;
	}
}

template<typename arrType>
inline void DynamicArray<arrType>::removeAt(unsigned int index)
{
	assert(index <= m_currentSize && "Please insert a valid index");

	for (unsigned int i = index; i < m_currentSize - 1; i++)
	{
		m_contents[i] = m_contents[i + 1];
	}
	popBack();
}

template<typename arrType>
inline bool DynamicArray<arrType>::isFull() const
{
	return (m_currentSize >= m_maxSize);
}

template<typename arrType>
inline void DynamicArray<arrType>::resizeArray(unsigned int newMaxAmount)
{
	int* newArray = new arrType[newMaxAmount];

	for (unsigned int i = 0; i < m_currentSize && i < newMaxAmount; i++)
	{
		newArray[i] = m_contents[i];
	}

	delete[] m_contents;
	m_contents = newArray;

	m_maxSize = newMaxAmount;
	if (m_currentSize > m_maxSize)
	{
		resizeArray(m_maxSize * 2);
	}
}

template<typename arrType>
inline int DynamicArray<arrType>::getAmount() const
{
	return m_currentSize;
}
