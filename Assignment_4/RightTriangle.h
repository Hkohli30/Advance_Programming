#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Isosceles.h"

class RightTriangle : public Isosceles
{

public:
	// Constructor
	RightTriangle(double length, string descp = "Triangle Class"
		, string name = "Triangle") : Isosceles(name, descp, length) {};
	// Destructor
	~RightTriangle() {};

	// Screen and geometric perimeter and area
	double geometricPerimeter() const override;
	double geometricArea() const override;

	int screenArea() const override;
	int screenPerimeter() const override;

	// getter

	double getHeight() const override;
	double getWidth() const override;

	// Draw
	void draw(Canvas& canvas, int row, int col,
		char foreChar = '*', char backChar = ' ') const override;

};
#endif // !RIGHTTRIANGLE_H

