#include "Rhombus.h"

/*
* Calculates the Geometric Area
* @retuns (double): Geometric Area of shape
*/
double Rhombus::geometricArea() const
{
	return (diameter*diameter)/2.0;
}

/*
* Calculates the Geometric Perimeter
* @retuns (double): Geometric Perimeter of shape
*/
double Rhombus::geometricPerimeter() const
{
	return ( 2 * sqrt(2) * diameter);
}

/*
* Calculates the Screen Area
* @retuns (int): screen Area of shape
*/
int Rhombus::screenArea() const
{
	int n = floor(diameter / 2);
	return ((2 * n * (n+1)) + 1);
}

/*
* Calculates the Screen Area
* @retuns (int): Screen Area of shape
*/
int Rhombus::screenPerimeter() const
{
	return ( 2 * (diameter - 1));
}

/*
* returns the height
* @retuns (double): returns the height
*/
double Rhombus::getHeight() const
{
	return diameter;
}

/*
* returns the width
* @retuns (double): returns the width
*/
double Rhombus::getWidth() const
{
	return this->getHeight();
}

/*
* Draw The shape on the canvas using forechar
* @param canvas(Canvas): canvas object
* @param row(int): rows of the object
* @param col(int): column of the object
* @param foreChar(char): foreground character
* @param backChar(char): background character
*/
void Rhombus::draw(Canvas & canvas, int row, int col, char foreChar, char backChar) const
{
	setFill(canvas, row, col, backChar);
	int midPoint = floor(getWidth() / 2);
	int midHeight = floor(getHeight() / 2);
	for (size_t r = 0; r <= midHeight; ++r)
	{
		for (size_t c = midPoint - r; c <= midPoint + r; ++c)
		{
			canvas[row + r][col + c] = foreChar;
		}
	}
	int i = 0;
	for (size_t r = midHeight + 1; r < getHeight(); ++r)
	{
		++i;
		for (size_t c = i; c < getWidth() - i; ++c)
		{
			canvas[row + r][col + c] = foreChar;
		}
	}

}
