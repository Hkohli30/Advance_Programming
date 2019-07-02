#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<string>
#include<locale>
#include<iomanip>
#include "WordList.h"

using namespace std;

WordList::WordList(const string& s) : firstNode{nullptr}, lastNode{nullptr}, size{0}
{
	loadList(s);
}
WordList::WordList(const WordList& value)
{
	copyToThis(value);
}
void WordList::operator=(const WordList& value)
{
	copyToThis(value);
}

WordList::~WordList()
{
	while (getListSize() != 0)
	{
		deleteWordNode();
	}
}

void WordList::deleteWordNode()
{
	while (getListSize() != 0)
	{
		WordNode *temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
		size--;
	}
}
int WordList::getListSize()
{
	return size;
}
// Prints the list
const ostream& WordList::printList(ostream& out)
{
	if (firstNode == nullptr)
	{
		cout << "Nolistmade";
	}
	else
	{
		locale loc;
		WordNode *ptr = firstNode;
		int a = 64;					// uses ascii code 
		out << "Data from from file : input.txt" << endl;
		out << "=============================" << endl;
		//out << left << setw(1) << "<" << 'A' << ">" << endl;
		while (ptr != nullptr)
		{
			
			if (tolower(char(a)) == ptr->wordDataObject.getReadPointer()[0])
			{
				ptr->wordDataObject.printWord(out);
				ptr = ptr->next;
			}
			
			else
			{
				a++;
				out << left << setw(1) << "<" << char(a) << ">" << endl;
			}

			
		}
		if (char(a) != 'Z')
			out << left << setw(1) << "<" << char(++a) << ">" << endl;
		delete ptr;		// cleanup
	}
	return out;
}

void WordList::copyToThis(const WordList& value)
{
	WordNode *prevNode = value.firstNode;
	WordNode *temp = value.firstNode; // for iteration
	while (temp != nullptr)
	{
		WordData newWordData = temp->wordDataObject;
		WordNode *newWordNode = new WordNode(newWordData);
		++(this->size);
		if (this->firstNode == nullptr)
		{
			this->firstNode = newWordNode;
			this->lastNode = newWordNode;
			prevNode = this->firstNode;
		}
		else
		{
			prevNode->next = newWordNode;
			this->lastNode = newWordNode;
		}
		
		temp = temp->next;
	}
	delete prevNode;	// cleanup
	delete temp;

}

void WordList::loadList(const string& filename) // Reads the list 
{
	locale loc;
	ifstream fin(filename);
	if (!fin)
	{
		cout << " could not open input file : " << filename << endl;
		exit(1);
	}
	int linenum = 0;
	string line;
	getline(fin, line);	// attempt to read a line 
	while ( fin )
	{
		++linenum;
		istringstream sin(line); // convert the line just read into an input stream 
		string word ;
		while (sin >> word)	// extract the words
		{
			// To lower case conversion
			for (int i = 0; i < word.length(); i++)
			{
				word[i] = tolower(word[i], loc);	// convert to lower case
			}
			
			char * charArrayWord = new char[word.length() + 1]; 
			strcpy_s(charArrayWord,word.length()+1, word.c_str());
			// ...
			stringOperation(charArrayWord);
			if (*charArrayWord != 0)		// to check if string is empty
			{
				addElementToList(charArrayWord, linenum);
			}
			
			
			delete[] charArrayWord; // clean up
		}
		
		getline(fin, line);
		
	}
	fin.close();

}
void WordList::stringOperation(char* word)
{
			// Removing special characters
	for (char* temp = word; *temp; ++temp)
	{
		if ((*temp >= 'a' && *temp <= 'z') || (*temp == '\'' && *(temp+1) =='s') || (*temp == '.' && *(word-1)=='i'))
		{
			*word++ = *temp;
		}
	}
	*word = 0;
}

WordList::WordNode* WordList::getWordNodePtr(char* word,int line_no)
{
	WordData wordDataObj(word, line_no);	//create new worddata object
	WordNode* node = new WordNode(wordDataObj);
	return node;
}
void WordList::addElementToList(char* word, int line_no)
{
	cout << endl;
	if (firstNode == nullptr)
	{
		// list is empty new wordnode to be added
		WordNode* node = getWordNodePtr(word,line_no);	// create a new object of 
		firstNode = node;
		lastNode = node;
		++size;
	}
	else
	{
		WordNode *temp = firstNode;
		WordNode *prev_node = nullptr;
		while (temp != nullptr)
		{
			if (temp->wordDataObject.compareWords(word) == 0)
			{
				temp->wordDataObject.appendLineNo(line_no);
				temp->wordDataObject.incrementFrequency();
				
				return;
			}
			else if (temp->wordDataObject.compareWords(word) < 0) // new word is bigger
			{
				prev_node = temp;
				temp = temp->next;
				
			}
			else			//  if new word is less than current word 
			{
				break;
			}
			
		}
													// at start
		if (prev_node == nullptr)
		{
			
			WordNode* node = getWordNodePtr(word,line_no);	// create a new object of 
			node->next = firstNode;
			firstNode = node;	// no need to update last node
			++size;				// increase size only if node is added
			
		}
		else	// at end
		{

			WordNode* node = getWordNodePtr(word, line_no);	// create a new object of 
			node->next = prev_node->next;
			prev_node->next = node;	// previous node will have new nodes address
			
			if (prev_node == lastNode)
			{
				lastNode = node;
			}
			++size;
		}
		
	}
}
