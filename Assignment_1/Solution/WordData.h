
#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include<string>
#include "NumList.h"

using namespace std;
class WordData
{
	private : 

		char *word;				 // array of characters
		int frequency_count;	// no of occurences
		NumList numList;
		
		
	public : 
		
		WordData(char *word, int line_no);
		WordData(const WordData&);
		WordData& operator=(const WordData &); 
		~WordData();
		
		// extra set of functions
		
		void incrementFrequency();
		bool checkLineNo(int);
		void appendLineNo(int);
		int getFrequencyCount();
		const char* getReadPointer();
		const NumList* getReadNumList();
		int compareWords(const char*);			// match frequency ++
		const ostream& printWord(ostream&);		// print word

		void copyToThis(const WordData&);		// copies worddata
		void copyWord(char*);					// copies word
	
};

#endif