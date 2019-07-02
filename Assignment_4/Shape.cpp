
// Shape class cpp implementation
#include "Shape.h"
#include<iomanip>
#include<typeinfo>
// Getters
/*
* This method returns the name of the shape 
* @return : returns the name of the shape
*/
string Shape::getShapeName() const
{
	return name;
}

/*
* This method returns the description of the shape
* @return : returns the description of the shape
*/
string Shape::getShapeDescp() const
{
	return descp;
}

int Shape::getId() const
{
	return id;
}

/*
* This method returns the id of the shape
* @return : returns the id of the shape
*/

// Setters

/*
* This sets the name of the object to the argumented value
* @param name(const string) : string that sets the name 
*								attribute of the object
*/
void Shape::setShapeName(const string name)
{
	this->name = name;
}

/*
* This sets the description of the object to the argumented value
* @param descp(const string) : string that sets the description
*								attribute of the object
*/
void Shape::setShapeDescp(const string descp)
{
	this->descp = descp;
}

/*
* To String method which prints the details of the invoking object
*/
const Shape& Shape::toString() const
{
	return *this;
}

/*
* Overloaded operator to display the detailed information of the invoking object
* @param out(ostream) : sets the value in the ostream object
* @param shape(Shape) : Shape object 
* @return ostream: object
*/
ostream& operator<<(ostream &out, const Shape &shape)
{
	out <<fixed<< setprecision(0);
	out << "Shape Information \n" << "--------------------\n";
	out <<setw(23)<<left<< "Static Type: " <<setw(23)<<left<< typeid(&shape).name() << endl;
	out <<setw(23)<<left<< "Dynamic Type: " <<setw(23)<<left<< typeid(shape).name() << endl;
	out << setw(23) << left << "Shape Name: " <<setw(23)<<left<< shape.getShapeName() << endl;
	out << setw(23) << left << "Description: " << setw(23) << left << shape.getShapeDescp() << endl;
	out << setw(23) << left << "ID: " << setw(23) << left << shape.getId() << endl;
	out << setw(23) << left << "B. box width: " << setw(23) << left << shape.getWidth() << endl;
	out << setw(23) << left << "B. box height: " << setw(23) << left << shape.getHeight() << endl;
	out << setw(23) << left << "Screen Area: " << setw(23) << left << shape.screenArea() << endl;
	out << setw(23) << left << "Geometric Area: " << setw(23) << left << setprecision(2)<< shape.geometricArea() << endl;
	out << setw(23) << left << "Screen Perimeter: " << setw(23) << left << shape.screenPerimeter() << endl;
	out << setw(23) << left << "Geometric Perimeter: " << setw(23) << left <<setprecision(2)<< shape.geometricPerimeter() << endl;

	return out;
}

/*
* sets the filling value for the canvas 
* @param canvas(Canvas) : canvas object
* @param row(int) : size of the row
* @param col(int) : size of the col
* @param character: character which will fill the canvas
*								
*/
void Shape::setFill(Canvas & canvas, int row, int col, char character) const
{
	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			canvas[row + i][col + j] = character;
		}
	}
}
