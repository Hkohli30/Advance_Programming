#include "Oblique.h"

/*
* Calculates the Geometric perimeter
* @retuns (double): Geometric Perimeter of shape
*/
double Oblique::geometricPerimeter() const
{
	double base = getWidth();
	double height = getHeight();
	double op = sqrt((0.25 * base * base) + (height * height));
	//sqrt(0.25 b^2 - h^2)
	return (base + (2 * op));
}

/*
* Calculates the Geometric Area
* @retuns (double): Geometric Area of shape
*/
double Oblique::geometricArea() const
{
	return ((getHeight() * getWidth()) / 2);
}

/*
* Calculates the Screen perimeter
* @retuns (int): Screen Area of shape
*/
int Oblique::screenArea() const
{
	return (getHeight() * getHeight());
}

/*
* Calculates the screen perimeter
* @retuns (int): Screen Perimeter of shape
*/
int Oblique::screenPerimeter() const
{
	return (4 * (getHeight() - 1));
}

/*
* Calculates the height
* @retuns (double): Height of the shape object
*/
double Oblique::getHeight() const
{
	double base = getBase();
	return ((base + 1) / 2);
}

/*
* Returns the width
* @retuns (double): Height of the shape object
*/
double Oblique::getWidth() const
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
void Oblique::draw(Canvas & canvas, int row, int col, char foreChar, char backChar) const
{
	setFill(canvas, row, col, backChar);

	int midPoint = floor(getWidth()/2);
	for(size_t r=0;r<getHeight();++r)
	{
		for(size_t c = midPoint-r;c<=midPoint + r; ++c)
		{
			canvas[row+r][col+c] = foreChar;
		}
	}
	
	
}
