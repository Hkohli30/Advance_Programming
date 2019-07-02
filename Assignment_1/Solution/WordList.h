
#ifndef WORDLIST_H
#define WORDLIST_H
#include<iostream>
#include "WordData.h"

class WordList
{
	private :
		struct WordNode
		{
			WordData wordDataObject;
			WordNode *next;
			WordNode(WordData wordData,WordNode *next = nullptr) : wordDataObject(wordData),
					next(next){}	// constructor accepts worddata and set next pointer null or to the passed value
		};
		
		WordNode *firstNode , *lastNode;
		int size;
		
		// private functions
		void loadList(const string&);
		void addElementToList(char* word, int line_no); // append or create new node
		WordNode* getWordNodePtr(char*,int);
	
	public : 
		
		WordList(const string&);
		WordList(const WordList&);
		void operator=(const WordList&);
		~WordList();
		int getListSize();
		const ostream& printList(ostream&);
		void copyToThis(const WordList&);
		void deleteWordNode();
		void stringOperation(char*);		// for removing special characters
};


#endif