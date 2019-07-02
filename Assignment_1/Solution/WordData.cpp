
#include"WordData.h"
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;


WordData::WordData(char *word, int line) :
	  frequency_count(1), numList(NumList()){

	copyWord(word);
	numList.appendElement(line);
}

WordData::WordData(const WordData& object)
{
	copyToThis(object);
}
WordData& WordData::operator=(const WordData & object)
{
	if (this == &object)
	{
		return *this;
	}
	
	delete[] this->word;
	copyToThis(object);
	return *this;
}
WordData::~WordData()
{
	delete[] this->word;
}

// extra set of functions

bool WordData::checkLineNo(int value)
{
	return numList.exists(value);
}
void WordData::appendLineNo(int value)
{
	if (!numList.exists(value))
	{
		numList.appendElement(value);
	}
}
int WordData::getFrequencyCount() { return frequency_count; }

void WordData::incrementFrequency() { ++frequency_count;  }

const char* WordData::getReadPointer() {
	return this->word;
}

const NumList* WordData::getReadNumList() {
	return &numList;
}
int WordData::compareWords(const char* word) {
	return strcmp(this->word,word);
}			// match frequency ++
const ostream& WordData::printWord(ostream& out) {
	char * word = this->word;
	
	out << setw(15) << right << word;	// align words
	out << "   (" << this->frequency_count << ") ";	// print frequency
	
	const int* var = numList.getPtr();
	for (int i = 0; i < numList.getSize(); i++)	// print num list
	{
	
		out << var[i] << " ";
	}
	
	out << endl;
	return out;
} 

void WordData::copyToThis(const WordData& source) // copies word data
{
	copyWord(source.word);
	this->frequency_count = source.frequency_count;
	this->numList = source.numList;
}

void WordData::copyWord(char* source)		//copies word
{
	int length = 0;
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		length++;
	}
	this->word = new char[length+1];	// Initializing new memory

	for (i = 0; source[i] != '\0'; i++)
	{
		this->word[i] = source[i];
	}
	this->word[i] = '\0';
}