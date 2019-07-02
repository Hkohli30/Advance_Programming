
// NumList.h
#ifndef NUMLIST_H
#define NUMLIST_H
#include<iostream>
#include<array>
using namespace std;

class NumList
{
	private : 
	
		int *num_pointer;	 // array
		int size;			// no. of elements in list
		int current_capacity;	// capacity of list

	public:
		
		NumList();  // default ctor
		NumList(const NumList&);							// copy ctor
		NumList& operator=(const NumList&);						// assignent operator
		~NumList();
		bool isEmpty();										
		bool exists(int& value);
		void appendElement(int);
		int get(int);		// int for position
		void set(int element, int position);		// int for positon
		void copyToThis(const NumList&);
		void copyNumList(int*,const int*);
		void deleteList();					// delete list 
		
		void resize();			// for resizing
		int getSize();
		int getCapacity();
		
		const int* getPtr();
};
#endif