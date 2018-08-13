#pragma once


class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void pushBack(int value); //puts a number at the end of the array, increases array size if necessary

	void popBack(); //Removes the current last pushed value in the array

	int getAt(unsigned int index); // get the value at the given index

	void getAll(); //print everything

	void rotateArray(int rotateAmount); //each value in the array a set amount of spaces over, any number that gets pushed past the end gets sent back to the start.

	void insertAt(unsigned int index, int value);	//Insert the given value at the given index
													/*
													eg:
													Before: 0, 1, 2, 3
													insertAt(2, 20);
													After : 0, 1, 20, 2, 3
													*/

	void removeAt(unsigned int index);	//Remove the value at the given index
										/*
										eg:
										Before: 0, 1, 2, 3
										removeAt(2);
										After: 0, 1, 3
										*/


private:
	void resizeArray(unsigned int newMaxAmount);
	bool isFull() const;
	int getAmount() const;

	int m_currentSize = 0;
	int m_maxSize;
	int* m_contents;

};