
#ifndef LINEEDITOR_H
#define LINEEDITOR_H
#include<string>
#include"Command.h"
#include<list>
#include<vector>
using namespace std;

class LineEditor {

private:
	list<string> buffer;
	vector<string> clipboard;
	int current_line;
	string filename;
	Command command;

public:
	// Constructor
	LineEditor(string);
	void run();
	void readFile(string);
	void writeFile();

	// Movement Commands
	void moveToLine(const int);
	void move(const int,const char); // 5+ or 5-

	// print and quit
	void printBuffer(const list<string>&);		// arg 2
	void printSelection(const list<string>&, const int, const int);
	void saveAndQuit();
	void quit();
	void createFile(const string);
	
	// perform Operations Like join
	void performEmpty();
	void performJoin(list<string> &, const int, const int);
	void performReplace(list<string> &,const string,int,const int);	// 2 args or report error
	void performAppend(list<string> &,const string,const int);	// after line
	void performCutClip(list<string> &,vector<string>&,const int,const int);  // int range copy
	void performPaste(list<string> &, vector<string>&,const int, bool);	// 0-u(above) and 1-v(below)
	void performDelete(list<string> &,const int,const int);
	void performInsert(list<string> &,const string,const int);		// insert before
	void performChange(list<string> &,const string, const string,const int,const  int);	// 1,2c
	void cmdMode(list<string>&);

	void sampleCreate(list<string>&, vector<string>&);
};

#endif // !LINEEDITOR_H
