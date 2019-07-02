
#ifndef COMMAND_H
#define COMMAND_H

#include<iostream>
#include<string>

using namespace std;
class Command
{
private:
	string leftOperand, rightOperand;
	char operation;
	bool type_flag;

public:

	void parse(string commandLine,int currentline, int lastline);
	string getLeftOp();
	void setLeftOp(string);
	string getRightOp();
	void setRightOp(string);
	char getOperationSym();
	void setOperationSym(char);
	bool getFlag();
	void setFlag(bool);
	void removeSpaces(string&);
	void parseString(string,int,int);

	//helper
	void parseSingleCommand(string);
	void parseDualCommand(string);
	void parseMultiCommand(string);
	void splitByComma(string);
	bool containsCommand(string s);
	bool isNumber(string s);
	bool containsComma(string);
	bool isValidRange(const int);
	void setLineNo(const string, const int);

};

#endif // !COMMAND_H
