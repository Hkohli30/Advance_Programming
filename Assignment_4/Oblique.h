#ifndef OBLIQUE_H
#define OBLIQUE_H
#include "Isosceles.h"
#include <cmath>
class Oblique : public Isosceles
{

public:
	// constructor
	Oblique(double base, string descp = "Oblique Class",
		string name = "Oblique") : 
		Isosceles(name, descp,fmod(base,2.0) == 0 ? (base+1):base ){};

	// Destructor
	~Oblique() {};

	// Perimeter and area Geometric
	double geometricPerimeter() const override;
	double geometricArea() const override;

	// Perimeter and area Screen
	int screenArea() const override;
	int screenPerimeter() const override;

	// getters
	double getHeight() const override;
	double getWidth() const override;

	// Draw
	void draw(Canvas& canvas, int row, int col,
		char foreChar = '*', char backChar = ' ') const override;


};
#endif // !OBLIQUE_H
