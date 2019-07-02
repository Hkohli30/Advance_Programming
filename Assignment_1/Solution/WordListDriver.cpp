#include "WordList.h"
#include<iostream>
#include"NumList.h"
		// Author Himanshu Kohli
		// ID: 40070839
using namespace std;
int main()
{
	WordList wl("e:\\input.txt");		// mention the file name
	// Please change file name according to location
	wl.printList(cout);
	cout << "Merci Beaucoup"<<endl;
	return 0;
}