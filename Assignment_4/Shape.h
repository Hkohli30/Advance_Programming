
#ifndef SHAPE_H
#define SHAPE_H

#include "Canvas.h"
#include<string>
#include<iostream>
#include<typeinfo>
using namespace std;


static int staticId = 0;	// Static string to provide unique id to every object
class Shape
{
private:
	
	string name, descp;
	int id;

public:
	// constructor and destructor
	Shape(string name, string descp) : name(name), descp(descp),id(++staticId){};
	virtual ~Shape() {};

	// getter
	string getShapeName() const;
	string getShapeDescp() const;
	int getId() const;

	//setter
	void setShapeName(const string name);
	void setShapeDescp(const string descp);

	// returns the details of shape object
	const Shape& toString() const;

	// area and perimeter
	virtual double geometricArea() const= 0;
	virtual double geometricPerimeter() const= 0;

	// screen perimeter and area
	virtual int screenArea() const = 0;
	virtual int screenPerimeter() const = 0;

	// Draw method
	virtual void draw(Canvas& canvas, int row, int col,
		char foreChar = '*', char backChar = ' ') const = 0;
	
	// operator overloading
	friend ostream& operator<<(ostream&, const Shape&);

	// getwidth and getHeight function
	virtual double getHeight() const = 0;
	virtual double getWidth() const = 0;

	// filling the canvas
	void setFill(Canvas& canvas, int row, int col, char character) const;
};


#endif // SHAPE_H

