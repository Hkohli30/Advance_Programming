#ifndef  CANVAS_H
#define CANVAS_H
#include<iostream>
#include<vector>
using namespace std;

class Canvas
{
private:
	vector<vector<char>> cells;	// character holder for canvas
public:
	Canvas(int row, int col, char fillch = ' ');

	virtual ~Canvas() {};
	
	// Operator overloading
	vector<char>& operator[](const int index);	// Read and Write
	const vector<char>& operator[](const int index) const; // Read only

	// Put method to place character in the canvas matrix
	void put(int r, int c, char ch = '*');
	// Chaecks the bounds of the row and columns
	bool inBound(const int row, const int col);

	// Get height and width of the canvas
	int getHeight() const;
	int getWidth() const;

	// Clear the filling character
	void clear(char fillch = ' ');
	
	// Operator overloading for printing canvas object
	friend ostream& operator<<(ostream&out,const Canvas& canvas);
};
#endif // ! CANVAS_H
