#include "Canvas.h"


/*
* Canvas constructor of the canvas class
*/
Canvas::Canvas(int row, int col, char fillch)
{
	for (int i = 0; i < row; i++)
	{
		vector<char> row_vec;
		for (int j = 0; j < col; j++)
		{
			row_vec.push_back(' ');
		}
		cells.push_back(row_vec);
	}
}


/*
* Overloaded Operator for canvas object
* @param : index(int): index value to be accessed
* @return : returns the vector of characters
*/
vector<char>& Canvas::operator[](const int index)
{
	return cells[index];
}

/*
* Overloaded Operator for canvas object
* @param : index(int): index value to be accessed
* @return : returns the const vector of characters
*/
const vector<char>& Canvas::operator[](const int index) const
{
	return cells[index];
}

/*
* Put the character in the corresponding row and column of the canvas 
* @param : r(int): row(th) element
* @param : c(int): column(th) element
* @param : ch(char): character value
*/
void Canvas::put(int r, int c, char ch)
{
	if (inBound(r, c))
	{
		cells[r][c] = ch;
	}
}

/*
* Checks the bounds of the canvas
* @param : row(int): row(th) element
* @param : col(int): column(th) element
*/
bool Canvas::inBound(const int row, const int col)
{
	if (row < cells.size() && row >= 0)
	{
		if (col < cells[row].size() && row >= 0)
		{
			return true;
		}
	}
	return false;
}

/*
* returns the width of the canvas
* @retuns (int): width of canvas
*/
int Canvas::getWidth() const
{
	return cells[0].size();
}

/*
* clears the canvas
* @param : fillch(char) fills the canvas with empty value ' '
*/
void Canvas::clear(char fillch)
{
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[i].size(); j++)
		{
			cells[i][j] = fillch;
		}
	}
}

/*
* returns the height of the canvas
* @retuns (int): height of canvas
*/
int Canvas::getHeight() const
{
	return cells.size();
}

/*
* Operator overloading for canvas object
* @param out(ostream): Output stream for object
* @param canvas(Canvas): Canvas object 
* @return (Ostream&): to facilitate multiple excertion operation
*/
ostream& operator<<(ostream& out, const Canvas& canvas)
{
	for (size_t i = 0; i < canvas.cells.size(); i++)
	{
		for (size_t j = 0; j < canvas.cells[i].size(); j++)
		{
			out << canvas[i][j];
		}
		out << endl;
	}
	return out;
}
