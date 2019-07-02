
#ifndef  RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double height, width;

public:
	// constructor
	Rectangle(double width, double height,
		string descp = "Class Rectangle", string name = "Rectangle")
		: width(width), height(height), Shape(name, descp) {};
	// Destructor
	~Rectangle() {};

	// Override methods
	// Geometric and screen area
	double geometricArea() const override;
	double geometricPerimeter() const override;
	
	int screenArea() const override;
	int screenPerimeter() const override;

	// override getters

	double getHeight() const override;
	double getWidth() const override;

	// draw method
	void draw(Canvas& canvas, int row, int col,
		char foreChar = '*', char backChar = ' ') const override;

};

#endif // ! RECTANGLE_H

