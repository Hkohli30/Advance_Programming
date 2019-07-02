#include<iostream>
#include"Command.h"
#include<string>


/*
*
* Removes spaces and perform parsing of string
* @param  commandLine: the command entered by user
*/

void Command::parse(string commandLine,int currentline, int lastline)
{
	removeSpaces(commandLine);
	parseString(commandLine,currentline,lastline);
}

/*
*
* Getter for left Operand value i.e. 1,2p --> returns 1
* @return leftOperand: returns the left operand
*/

string Command::getLeftOp()
{
	return leftOperand;
}
/*
*
* Setter for left Operand 
* @param value: sets leftOperand to given value
*/

void Command::setLeftOp(string value)
{
	this->leftOperand = value;
}

/*
*
* Getter for right Operand value i.e. 1,2p --> returns 2
* @return rightOperand: returns the right operand
*/
string Command::getRightOp()
{
	return this->rightOperand;
}
/*
*
* Setter for right Operand
* @param value: sets rightOperand to given value
*/
void Command::setRightOp(string value)
{
	this->rightOperand = value;
}
/*
*
* Getter for operation value i.e. 1,2p --> returns p
* @return operation: returns operation
*/

char Command::getOperationSym()
{
	return this->operation;
}
/*
*
* Setter for operand value 
* @param operation_value: sets the Operation to char value 'p'
*/
void Command::setOperationSym(char operation_value)
{
	this->operation = operation_value;
}
bool Command::getFlag()
{
	return type_flag;
}

void Command::setFlag(bool value)
{
	type_flag = value;
}

/*
*
* Removes spaces in the string i.e. 1,2 p --> 1,2p
* @param s: string which holds the command inputed value
*/
void Command::removeSpaces(string& s)
{
	size_t find_space;
	find_space = s.find(" ");
	while (find_space != string::npos)
	{
		s = s.erase(find_space, 1);
		find_space = s.find(" ");
	}
}

/*
*
* parses the string and sets the operation,leftOperand and rightOperand values
* based on length of the entered value
* @param s: string which holds the command inputed value
*/
void Command::parseString(string s,int currentline, int lastline)
{
	if (s.length() == 0)
	{
		this->operation = '+';
		this->leftOperand = '1';
		this->rightOperand = '1';
	}
	else if (isNumber(s))
	{
		this->operation = 'g';
		this->leftOperand = s;
		this->rightOperand = s;
	}
	else if (s.length() == 1)
	{
		parseSingleCommand(s);
	}
	else if (s.length() == 2)
	{
		parseDualCommand(s);
	}
	else
	{
		parseMultiCommand(s);
	}
	setLineNo(".", currentline);
	setLineNo("$", lastline);
}

/*
*
* Parses single values such as * or number
* @param s: string which holds the command inputed value
*/
void Command::parseSingleCommand(string s)
{
	if (s == "*")
	{
		this->operation = 'p';
		this->leftOperand = "1";
		this->rightOperand = "$";
	}
	else if (s == "," || s == ".")
	{
		this->operation = 'p';
		this->leftOperand = ".";
		this->rightOperand = ".";
	}
	else if (s == "+" || s == "-")
	{
		this->operation = s[0];
		this->leftOperand = "1";
		this->rightOperand = "1";
	}
	else if (s == "$" || isNumber(s))
	{
		this->operation = 'g';
		this->leftOperand = s;
		this->rightOperand = s;
	}
	else
	{
		this->operation = s[0];
		this->leftOperand = ".";
		this->rightOperand = ".";
	}
}

/*
*
* Parses dual string values like 1,p or .p
* @param s: string which holds the command inputed value
*/
void Command::parseDualCommand(string s)
{
	if (containsComma(s) && s[0] == ',' && s[1] != ',')
	{
		this->operation = 'p';
		this->leftOperand = ".";
		this->rightOperand = s[1];
	}
	else if (containsComma(s) && s[0] != ',' && s[1] == ',')
	{
		this->operation = 'p';
		this->leftOperand = s[0];
		this->rightOperand = ".";
	}
	else
	{
		this->operation = s[1];
		this->leftOperand = s[0];
		this->rightOperand = s[0];
	}
}

/*
*
* Parses commands like 1,2p or .,.p etc
* @param s: string which holds the command inputed value
*/
void Command::parseMultiCommand(string s)
{
	if (containsCommand(s) && containsComma(s))
	{
		this->operation = s[s.length() - 1];
		string address = s.substr(0, s.length() - 1);
		splitByComma(address);
	}
	else if (containsCommand(s))
	{
		string address = s.substr(0, s.length() - 1);
		this->operation = s[s.length() - 1];
		this->leftOperand = address;
		this->rightOperand = address;
	}
	else if (containsComma(s))
	{
		this->operation = 'p';
		splitByComma(s);
	}
}

/*
*
* Finds out whether the string contains comma or not
* @param s: string which holds the command inputed value
* @return bool value: true or false
*/
bool Command::containsComma(string s)
{
	if (s.find(",") != string::npos)
	{
		return true;
	}
	return false;
}

/*
*
* Splits the string by comma and assigns value to operation,
* leftOperand and rightOperand
* @param s: string which holds the command inputed value
*/
void Command::splitByComma(string address)
{
	size_t index = address.find(",");
	if (index == 0)
	{
		this->leftOperand = ".";
		this->rightOperand= address.substr(index + 1);
	}
	else if (index == (address.length() - 1))
	{
		this->leftOperand = address.substr(0, index);
		this->rightOperand = ".";
	}
	else
	{
		this->leftOperand = address.substr(0, index);
		this->rightOperand = address.substr(index + 1);
	}
}

/*
*
* Checks if the command is in the string or not
* @param s: string which holds the command inputed value
* @return : true or false
*/
bool Command::containsCommand(string s)
{
	if (s.find_last_of("aivudxrjpcgwq-+$.*") != string::npos)
	{
		return true;
	}
	return false;
}

/*
*
* Checks the entered string is a valid number or not
* @param s: string which holds the command inputed value
* @return bool: true or false
*/

bool Command::isNumber(string element)
{
	for (int i = 0; i < element.length(); i++)
	{
		if (!isdigit(element[i]))
		{
			return false;
		}
	}
	return true;
}

void Command::setLineNo(const string address, const int lineNumber)
{
	if (leftOperand.compare(address) == 0)
	{
		this->leftOperand = to_string(lineNumber);
	}

	if (rightOperand.compare(address) == 0)
	{
		this->rightOperand = to_string(lineNumber);
	}
}

bool Command::isValidRange(const int lastLine)
{
	if (!isNumber(leftOperand) || !isNumber(rightOperand))
	{
		return false;
	}

	int left = stoi(leftOperand);
	int right = stoi(rightOperand);
	if (1 <= left && left <= lastLine && 1 <= right && right <= lastLine)
	{
		return true;
	}
	return false;
}