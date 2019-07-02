
#include<iostream>
#include<string>
#include"LineEditor.h"
#include<fstream>

using namespace std;

// Constructor and Run Method

// tester method (not used in real project)
void LineEditor::sampleCreate(list<string> &sample, vector<string> & vec)
{
	for (int alpha = 1; alpha< 10; alpha++)
	{
		sample.push_back("sagar");
	}


	for (int a = 1; a <= 3; a++)
	{
		vec.push_back("ram");
	}
}

/*
* Constructor of Line Editor 
* @param  filename: assigns the local variable filename a file name.
* @return constructor dosen't have a return type
*/

LineEditor::LineEditor(string filename)
{
	this->filename = filename;
	current_line = 0;
}

/*
*
* Starts the line Editor class
*/
void LineEditor::run()
{
	string filename =this->filename;
	if (filename.length() > 0)
	{
		readFile(filename);
	}

	//sampleCreate(buffer, clipboard);
	cout << "\nEntering command mode." << endl;

	
	while (true)
	{
		cin.clear();
		cout << "? ";
		string commandLine;
		getline(cin, commandLine);
		Command cmd;
		cmd.parse(commandLine,current_line, buffer.size());
		switch(cmd.getOperationSym())
		{
		case 'a':
			if (buffer.size() == 0)
			{
				string val;
				cout << "Enter Data :" << endl;
				while (getline(cin, val))
				{
					buffer.push_back(val);
					++current_line;
				}
			}
			else if ((cmd.getLeftOp().compare(cmd.getRightOp()) == 0) && cmd.isValidRange(buffer.size()))
			{
				list<string> a;
				cmdMode(a);
				int line = stoi(cmd.getLeftOp());
				for (list<string>::iterator i = a.begin(); i != a.end(); i++)
				{
					performAppend(buffer, *i, line);
					line++;
				}
				current_line = line;
			}
			else
			{
				cout << "Invalid Operation (Append)";
			}
			break;
		case 'i':
			if (buffer.size() == 0)
			{
				string val;
				cout << "Enter Data :" << endl;
				while (getline(cin, val))
				{
					buffer.push_back(val);
					++current_line;
				}
			}
			else if ((cmd.getLeftOp().compare(cmd.getRightOp()) == 0) && cmd.isValidRange(buffer.size()))
			{
				list<string> a;
				cmdMode(a);
				int line = stoi(cmd.getLeftOp());
				for (list<string>::iterator i = a.begin(); i != a.end(); i++)
				{
					performInsert(buffer, *i, line);
					line++;
				}
				current_line = line - 1;
			}
			else
			{
				cout << "Invalid Operation the size is greater than buffer size";
			}
			break;
		case 'v':
			if (buffer.size() == 0)
			{
				for (vector<string>::iterator it = clipboard.begin(); it != clipboard.end(); it++)
					buffer.push_back(*it);
			}
			else if ((cmd.getLeftOp().compare(cmd.getRightOp()) == 0) && cmd.isValidRange(buffer.size()))
			{
				performPaste(buffer, clipboard, stoi(cmd.getLeftOp()), 0);
			}
			else if ((cmd.getLeftOp().compare(cmd.getLeftOp()) != 0))
				cout << "Invalid Range (paste v)"<<endl;
			else
				cout << "Invalid Operation(paste v)" << endl;
			break;
		case 'u':
			if (buffer.size() == 0)
			{
				for (vector<string>::iterator it = clipboard.begin(); it != clipboard.end(); it++)
					buffer.push_back(*it);
			}
			else if ((cmd.getLeftOp().compare(cmd.getRightOp()) == 0) && cmd.isValidRange(buffer.size()))
			{
				performPaste(buffer, clipboard, stoi(cmd.getLeftOp()), 1);
				current_line = stoi(cmd.getLeftOp()) + clipboard.size();
			}
			else if ((cmd.getLeftOp().compare(cmd.getLeftOp()) != 0))
				cout << "Invalid Range (paste v)" << endl;
			else
				cout << "Invalid Operation(paste v)" << endl;
			break;
		case 'd':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
			{
				performDelete(buffer, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
				
			}
			else
				cout << "Invalid Range";
			break;
		case 'x':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
				performCutClip(buffer,clipboard, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
			else
				cout << "Invalid Range" << endl;
			break;
		case 'r':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if(buffer.size() == 0 && !cmd.isValidRange(buffer.size()))
				cout << "Invalid Range" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
			{
				list<string> a;
				cmdMode(a);
				performDelete(buffer, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
				for (list<string>::iterator i = a.begin(); i != a.end(); i++)
				{
					performInsert(buffer, *i, current_line);
					//performReplace(buffer, *i, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
					++current_line;
				}
			}
			
			break;
		case 'j':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
			{
				performJoin(buffer, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
			}
			else
				cout << "Invalid Range" << endl;
			break;
		case 'p':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
			{
				printSelection(buffer,stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
			}
			else
				cout << "Invalid Range" << endl;
			break;
		case 'c':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (buffer.size() != 0 && cmd.isValidRange(buffer.size()))
			{
				cin.clear();
				string change_what, with_what;
				cout << "change what? :";
				getline(cin, change_what);
				cout << "with what? : ";
				getline(cin, with_what);
				if (change_what.length() == 0 || with_what.length() == 0)
					cout << "invalid input";
				else
				{
					performChange(buffer, change_what, with_what, stoi(cmd.getLeftOp()), stoi(cmd.getRightOp()));
					current_line = stoi(cmd.getLeftOp());
				}
			}
			else
				cout << "Invalid Range" << endl;
			break;
		case '-':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if(buffer.size() != 0)
				move(stoi(cmd.getLeftOp()), '-');
			else
				cout << "Invalid Range" << endl;
			break;
		case '+':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (cmd.isValidRange(buffer.size()) && (cmd.getLeftOp().compare(cmd.getRightOp()) == 0))
				move(stoi(cmd.getLeftOp()), '+');
			else
				cout << "Invalid Range" << endl;
			
			break;
		case 'g':
			if (buffer.size() == 0)
				cout << "Empty Buffer" << endl;
			else if (cmd.isValidRange(buffer.size()) && (cmd.getLeftOp().compare(cmd.getRightOp()) == 0))
				moveToLine(stoi(cmd.getLeftOp()));
			else
				cout << "Invalid Range" << endl;
			break;
		case 'w':
			writeFile();
			break;
		case 'q':
			quit();
			break;
		default:
			cout << "Default Invalid Command." << endl;
			break;
		}
	}

}

/*
* Reads the file if file is present
* @param  filename: filename for reading the file
*/
void LineEditor::readFile(string filename)
{
	ifstream fin(filename.c_str());
	cout << filename;
	if (!fin)
	{
		filename = "New File.txt";
		cout << "?  ["<<filename<<"]"<<endl<<endl;
	}
	else
	{
		string line;
		while (getline(fin, line))
		{
			buffer.push_back(line);
			current_line++;
		}
	}
	
}



/*
* Writes the file if file is present
* @param  filename: filename for reading the file
*/

void LineEditor::writeFile()
{
	if (buffer.size() == 0)
		cout << "buffer is empty cannot write file"<<endl;
	else
	{
		ofstream myfile;
		if (filename.compare("New File.txt") == 0)
			myfile.open("E:\\" + filename);
		else
			myfile.open(filename);
		for (list<string>::iterator it = buffer.begin(); it != buffer.end(); it++)
		{
			if (it == buffer.begin())
				myfile << *it;
			else
				myfile << "\n" + *it;
		}

		myfile.close();
	}
	
}
// Movement Commands

/*
*
* Moves the current line to specified line number
if the line number is valid
* @param  takes a line number
*/
void LineEditor::moveToLine(const int line_no)
{
	if (line_no <= buffer.size() && line_no > 0)
	{
		current_line = line_no;
	}
}

/*
*
* Moves the current line up or down the number of times specified
* @param  number: takes constant no. of times the line is to be moved
* @param  up_down: takes '+' or '-' to move down or up respectively
* @return
*/
void LineEditor::move(int number,const char up_down)
{
	if (up_down == '+')
	{
		while(buffer.size() >= number && number > 0)
		{
			if (current_line == buffer.size())
			{
				cout << "End of the buffer reached()" << endl;
				break;
			}
			current_line++;
			number--;
		}
		
	}
	else
	{
		while (number > 0 && number <= buffer.size())
		{
			if (current_line == 1)
			{
				cout << "Top of the buffer reached" << endl;
				break;
			}
			current_line--;
			number--;
		}
	}
}

// Print and Quit Commands

/*
*
* Prints the entire buffer out to system
* @param  buffer (reference): takes the buffer as input
*/
void LineEditor::printBuffer(const list<string> &buffer)
{
	if (buffer.size() > 0)
	{
		list<string>::const_iterator it = buffer.begin();
		int a = 1;
		for (it = buffer.begin(); it != buffer.end(); ++it)
		{
			if (a == current_line)
				cout << a << "> ";
			else
				cout << a << ": ";
			cout << "" << *it << endl;
			a++;
		}
	}
	else
		cout << "Empty Buffer" << endl;
}
/*
*
* Prints the lines for specified range
* @param  buffer(reference) : takes buffer as input
* @param  r1(lower range) and r2(upper range) : takes line range as input
* @return
*/
void LineEditor::printSelection(const list<string> &buffer, const int r1, const int r2)
{
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && buffer.size()>0)
	{
		list<string>::const_iterator it1, it2;
		it1 = it2 = buffer.begin();
		if (r1 != 1)
			advance(it1, r1 - 1);
		advance(it2, r2);
		int a = r1;
		for (list<string>::const_iterator it = it1; it != it2; ++it)
		{
			if (a == current_line)
				cout << a << "> " << *it << endl;
			else
				cout << a << ": " << *it << endl;
			a++;
		}
	}
	else
		cout << "Invalid range to perform print";
}

/*
*
* Saves the file and quits
*/
void LineEditor::saveAndQuit()
{

}
/*
*
* Quits the file without saving
*/
void LineEditor::quit()
{
	string c;
	cin.clear();
	while (true)
	{
		cout << "Do you want to save the file (y/n) : ";
		getline(cin, c);
		if (c.compare("y") ==0)
		{
			writeFile();
			cout << "Bye! Have a good day"<<endl;
			exit(0);
		}
		else if (c.compare("n") ==0)
		{
			cout << "Bye! Have a good day"<<endl;
			exit(0);
		}
		else
			cout << "Wrong choice"<<endl;
	}
}

/*
*
* creates a file with the given filename
* @param  filename: takes filename as input
*/
void LineEditor::createFile(const string filename)
{

}


// perform Operations

/*
*
* clears the buffer
*/
void LineEditor::performEmpty()
{
	this->buffer.clear();
}


/*
*
* Perfom insert on above the specified line number
* @param  buffer: buffer reference as an input
* @param  s(constant): the string which is to be inserted
* @param  loc(constant): the location where string is to be inserted
*/
void LineEditor::performInsert(list<string> &buffer,const string s,const int loc)
{
	list<string>::iterator it = buffer.begin();
	if (buffer.size() == 0 || loc == 1)
	{
		buffer.insert(it, s);
	}
	else if (loc <= buffer.size() && loc > 0)
	{
		advance(it, loc - 1);
		buffer.insert(it, s);
	}
	else
	{
		cout << "Invalid Operation the size is greater than buffer size for insertion";
	}
}

/*
*
* Perfom append below the specified line number
* @param  buffer: buffer reference as an input
* @param  s(constant): the string which is to be inserted
* @param  loc(constant): the location where string is to be inserted
*/
void LineEditor::performAppend(list<string> &buffer, const  string s, const  int loc)
{
	list<string>::iterator it = buffer.begin();
	advance(it, loc);
	buffer.insert(it, s);
}

/*
*
* Perfom paste data from clipboard to buffer
* @param  buffer: buffer reference as an input
* @param  vec: (clipboard) from where data is to be copied
* @param  s(constant): the string which is to be inserted
* @param  loc(constant): the location where string is to be inserted
* @param  flag(constant): pasting 0 for below(append) and 1 for above(insert)
*/

void LineEditor::performPaste(list<string>& buffer, vector<string> &vec,int loc, const  bool flag)
{
	if (loc <= buffer.size() && loc > 0 && vec.size() > 0)
	{
		vector<string>::iterator vec_it;
		vec_it = vec.begin();

		for (vec_it = vec.begin(); vec_it != vec.end(); vec_it++)
		{
			if (flag)
			{
				performInsert(buffer, *vec_it, loc);
				loc++;
			}
			else
			{
				performAppend(buffer, *vec_it, loc);
				loc++;
			}
		}
	}
	else if (vec.size() < 1)
		cout << "No Data in the clipboard" << endl;
	else
		cout << "Invalid line no for performing paste operation" << endl;
}

/*
*
* Perfom delete on specified range
* @param  buffer: buffer reference as an input
* @param  r1(constant): starting range for line number
* @param  r2(constant): ending range for line number
*/
void LineEditor::performDelete(list<string> &buffer,const int r1,const int r2)
{
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && r1>0)
	{
		int temp_last_line = buffer.size();
		list<string>::iterator it1, it2;
		it1 = buffer.begin();
		it2 = buffer.begin();

		if (r1 != 1)
			advance(it1, r1 - 1);
		advance(it2, r2);

		buffer.erase(it1, it2);
		if (buffer.size() == 0)
			current_line = 0;
		else if (r2 == temp_last_line)
			current_line = r1 - 1;
		else 
			current_line = r1;
	}
	else
	{
		cout << "Invalid size for deletion";
	}
}

/*
*
* Perfom cut and move data to clipboard
* @param  buffer: buffer reference as an input
* @param  vec(clipboard): data is to be placed 
* @param  r1(constant): starting range for line number
* @param  r2(constant): ending range for line number
*/
void LineEditor::performCutClip(list<string> &buffer, vector<string> &vec,const int r1,const int r2)
{
	vec.clear();
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && r1>0)
	{
		list<string>::iterator list_it1, list_it2;
		list_it1 = buffer.begin();
		list_it2 = buffer.begin();

		
		advance(list_it1, r1 - 1);
		advance(list_it2, r2);

		for (list<string>::iterator i = list_it1; i != list_it2; i++)
		{
			vec.push_back(*i);
		}

		// cut Operation
		performDelete(buffer, r1, r2);

	}
	else
	{
		cout << "Wrong Range for copy to clipboard command";
	}
}

/*
*
* Perfom replaces specified range with text 
* @param  buffer: buffer reference as an input
* @param  text: the string which is to be replaced
* @param  r1(constant): starting range for line number
* @param  r2(constant): ending range for line number
*/
void LineEditor::performReplace(list<string> &buffer,const string text,const int r1,const int r2)
{
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && r1>0)
	{
		//performDelete(buffer, r1, r2);
		performInsert(buffer, text, current_line);
	}
	else
		cout << "Invalid range while performing replace";
}

/*
*
* Perfom joins the line range and make it one line
* @param  buffer: buffer reference as an input
* @param  r1(constant): starting range for line number
* @param  r2(constant): ending range for line number
*/
void LineEditor::performJoin(list<string> &buffer,const int r1,const int r2)
{
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && r1>0)
	{
		list<string>::iterator it1, it2;
		it1 = it2 = buffer.begin();
		
		advance(it1, r1 - 1);
		advance(it2, r2);

		string s = "";

		for (list<string>::iterator i = it1; i != it2; i++)
		{
			if (i == it1)
				s += *i;
			else
				s += " " + *i;
		}

		performDelete(buffer, r1, r2);
		performInsert(buffer, s, current_line);
		

	}
	else
		cout << "Error range in performJoin ";
}
/*
*
* Perfom changes the value in specified range
* @param  buffer: buffer reference as an input
* @param  change_what(const): string to be changed
* @param  change_with(const): string to be replaced with
* @param  r1(constant): starting range for line number
* @param  r2(constant): ending range for line number
*/

void LineEditor::performChange(list<string> &buffer,const string change_what,const string change_with,const int r1,const int r2)
{
	if (r1 <= buffer.size() && r2 <= buffer.size() && r1 <= r2 && r1>0)
	{
		int i = 0;
		list<string>::iterator iterator1 = buffer.begin();
		list<string>::iterator iterator2 = buffer.begin();
		if (r1 != 1)
			advance(iterator1, r1 - 1);
		advance(iterator2, r2);

		for (list<string>::iterator it = iterator1; it != iterator2; it++)
		{
			++i;
			string s = *it;
			size_t found = s.find(change_what);
			while (found != string::npos)
			{
				s.replace(found, change_what.length(), change_with);
				found = s.find(change_what, found + 1);
			}
			*it = s;
		}
	}
	else
		cout << "Invalid range for change";
}


void LineEditor::cmdMode(list<string>& sample)
{
	sample.clear();
	string val = "";
	list<string>::iterator it= sample.begin();
	while (getline(cin,val))
	{
		sample.push_back(val);
	}
}


