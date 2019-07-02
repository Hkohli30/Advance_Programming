#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Shape.h"
#include <cmath>

class Rhombus : public Shape
{

private:
	double diameter;
public:
	// constructor
	Rhombus(double diameter, string descp = "Class Rhombus",
		string name = "Rhombus") : diameter(fmod(diameter,2.0) ? diameter : (diameter + 1))
		, Shape(name, descp) {};

	// Destructor
	~Rhombus() {};

	// Override methods

	// Geometric and screen area and perimeter
	double geometricArea() const override;
	double geometricPerimeter() const override;

	int screenArea() const override;
	int screenPerimeter() const override;

	// override getters

	double getHeight() const override;
	double getWidth() const override;

	// Draw
	void draw(Canvas& canvas, int row, int col,
		char foreChar = '*', char backChar = ' ') const override;
	
};

#endif // !RHOMBUS_H

