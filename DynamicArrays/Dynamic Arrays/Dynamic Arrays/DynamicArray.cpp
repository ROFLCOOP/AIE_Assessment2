#include "DynamicArray.h"
#include <iostream>
#include <cassert>

DynamicArray::DynamicArray()
{
	m_maxSize = 10;
	m_contents = new int[m_maxSize];

}

DynamicArray::~DynamicArray()
{
	delete[] m_contents;
}

bool DynamicArray::isFull() const
{
	return (m_currentSize >= m_maxSize);
}

void DynamicArray::pushBack(int value)
{
	if (isFull())
	{

		resizeArray(m_maxSize * 2);
	}

	m_contents[m_currentSize] = value;
	m_currentSize++;

}

void DynamicArray::popBack()
{
	assert(m_currentSize > 0 && "array is too Small");
	m_currentSize -= 1;
}

int DynamicArray::getAt(unsigned int index)
{
	assert(index < m_currentSize && index >= 0 && "Please use a valid index");
	return m_contents[index];
}

void DynamicArray::getAll()
{
	for (unsigned int i = 0; i < m_currentSize; i++)
	{
		std::cout << getAt(i) << " ";
	}
	std::cout << "\n";
}

void DynamicArray::rotateArray(int rotateAmount)
{
	assert(rotateAmount != 0 && "Choose a number above or below 0");
	int temp1 = 0; //temporary variable to assist in changing the place of the values in the array
	int temp2 = 0;
	if (rotateAmount > 0)
	{
		for (int r = 0; r < rotateAmount; r++)
		{
			temp1 = m_contents[0];
			m_contents[0] = m_contents[m_currentSize - 1];

			for(unsigned int i = 1; i < m_currentSize; i++)
			{
				temp2 = m_contents[i];
				m_contents[i] = temp1;
				temp1 = temp2;
			}
		}
	}
	else if (rotateAmount < 0) //negatives do not work yet
	{
		for (int r = 0; r > rotateAmount; r--)
		{
			temp1 = m_contents[m_currentSize - 1];
			m_contents[m_currentSize - 1] = m_contents[0];

			for (unsigned int i = m_currentSize; i > 0; i--)
			{
				temp2 = m_contents[i-1];
				m_contents[i] = temp1;
				temp1 = temp2;
			}
		}
	}
}

void DynamicArray::insertAt(unsigned int index, int value)
{
	assert(index > 0 || index <= m_maxSize);
	if (m_maxSize = m_currentSize + 1)
	{
		resizeArray(m_maxSize * 2);
	}

	if (index < m_currentSize && index >= 0)
	{
		pushBack(m_contents[m_currentSize - 1]);
		for (unsigned int i = m_currentSize - 2; i >= index; i--)
		{
			m_contents[i] = m_contents[i - 1];
		}
		m_contents[index] = value;
	}
	else if (index >= m_currentSize && index < m_maxSize)
	{
		pushBack(value); //adds the value to the end of the array instead of the exact index
	}

}

void DynamicArray::removeAt(unsigned int index)
{
	assert(index <= m_currentSize && "Please insert a valid index");

	for (unsigned int i = index; i < m_currentSize - 1; i++)
	{
		m_contents[i] = m_contents[i + 1];
	}
	popBack();
}

void DynamicArray::resizeArray(unsigned int newMaxAmount)
{
	int* newArray = new int[newMaxAmount];

	for (unsigned int i = 0; i < m_currentSize && i < newMaxAmount; i++)
	{
		newArray[i] = m_contents[i];
	}

	delete[] m_contents;
	m_contents = newArray;

	m_maxSize = newMaxAmount;
	if (m_currentSize > m_maxSize)
	{
		m_currentSize = m_maxSize;
	}
}


int DynamicArray::getAmount() const
{
	return m_currentSize;
}