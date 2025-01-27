// LineEditor.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include"LineEditor.h"
// Author Himanshu kOHli
using namespace std;
int main(int argc, char * argv[])
{

	string filename1;
	switch (argc)
	{
	case 1: //no file name
		break;
	case 2: //read from argument string
		filename1 = argv[1];
		break;
	default:
		cout << ("too many arguments - all discarded");
		filename1.clear();
		break;
	}
	//build a LineKeeper object  from the lines in the input.txt text file.
	LineEditor led(filename1);
	led.run();
	return 0;
}

