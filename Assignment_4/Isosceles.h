
#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Shape.h"

class Isosceles : public Shape
{
private:
	double base;
public:
	// Constructor
	Isosceles(string name, string descp, double base)
		: Shape(name, descp), base(base) {};
	virtual ~Isosceles() {};	// Destructor

	// Accessor method 
	double getBase() const;
};


#endif // !ISOSCELES_H


