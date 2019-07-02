
#include "NumList.h"
#include<iostream>

using namespace std;


NumList::NumList() : size{0}, current_capacity{1}
{
	num_pointer = new int[1];
}

NumList::NumList(const NumList& value) 
{
	copyToThis(value);
}

NumList& NumList::operator=(const NumList& value)
{
	if (this == &value)
	{
		return *this;
	}
	delete[] this->num_pointer;
	this->num_pointer = new int[value.size];
	copyToThis(value);
	return *this;
}

NumList::~NumList()
{
	deleteList();
}

void NumList::deleteList()
{
	delete[] num_pointer;
}

bool NumList::isEmpty()
{
	return size == 0;
}

int NumList::getSize()
{
	return size;
}

int NumList::getCapacity()
{
	return current_capacity;
}

bool NumList::exists(int& value)
{
	int count = 0;
	int *ptr = this->num_pointer;
	
	while (count != size)
	{
		if (*ptr == value)
		{
			return true;
		}
		ptr++;
		count++;
	}
	return false;
}
void NumList::appendElement(int value)
{
	if (current_capacity == size)
	{
		resize();
	}
	num_pointer[size] = value;
	size = size + 1;
}
int NumList::get(int position) // int for position
{
	return num_pointer[position];
}
void NumList::set(int element, int position)		// int for positon
{
	if (current_capacity == size)
	{
		resize();
	}
	size = size + 1;		// increase size by 1
	int count = size;		
	while (count != 0)
	{
		if (count == position)
		{
			num_pointer[count] = element;
			break;
		}
		else
		{
			num_pointer[count] = num_pointer[count - 1];
			count--;
		}
	}

}

void NumList::copyToThis(const NumList& value)
{
	this->size = value.size;
	this->current_capacity = value.current_capacity;
	copyNumList(this->num_pointer, value.num_pointer);
}

const int*  NumList::getPtr()
{
	return num_pointer;
}

void NumList::resize()
{
	int *temp_pointer;
	if (current_capacity == size)
	{
		temp_pointer = new int[current_capacity];
		copyNumList(temp_pointer, num_pointer);		// copy elements to temp
		current_capacity = 2 * current_capacity;	// increase capacity
		num_pointer = new int[current_capacity];	// new size of array
		copyNumList(num_pointer, temp_pointer);		// receive elements from temp
		delete[] temp_pointer;						// delete pointer
	}
}

void NumList::copyNumList(int *dest,const int *source)
{
	for (int i = 0; i < this->size; i++) {
		dest[i] = source[i];
	}
}