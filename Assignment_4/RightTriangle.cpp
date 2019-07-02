#include "RightTriangle.h"
#include<sstream>

/*
* Calculates the Geometric Perimeter
* @retuns (double): Geometric perimeter of shape
*/
double RightTriangle::geometricPerimeter() const
{
	return ( (2 + sqrt(2)) * getHeight());
}

/*
* Calculates the Geometric Area
* @retuns (double): Geometric Area of shape
*/
double RightTriangle::geometricArea() const
{
	return ((getHeight() * getWidth()) / 2);
}

/*
* Calculates the screen Area
* @retuns (int): Screen Area of shape
*/
int RightTriangle::screenArea() const
{
	double height = getHeight();
	return ((height * (height + 1))/2);
}


/*
* Calculates the screen Area
* @retuns (int): Screen Area of shape
*/
int RightTriangle::screenPerimeter() const
{
	return (3 * (getHeight() - 1));
}

/*
* returns the height
* @retuns (double): returns the height
*/
double RightTriangle::getHeight() const
{
	return getBase();
}

/*
* returns the width
* @retuns (double): returns the width
*/
double RightTriangle::getWidth() const
{
	return getBase();
}


/*
* Draw The shape on the canvas using forechar
* @param canvas(Canvas): canvas object
* @param row(int): rows of the object
* @param col(int): column of the object
* @param foreChar(char): foreground character
* @param backChar(char): background character
*/
void RightTriangle::draw(Canvas & canvas, int row, int col, char foreChar, char backChar) const
{
	setFill(canvas, row, col, backChar);
	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			canvas[row + i][col + j] = foreChar;
		}
	}
}
