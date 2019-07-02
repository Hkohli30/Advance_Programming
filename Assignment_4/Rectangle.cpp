#include "Rectangle.h"

/*
* Calculates the Geometric Area
* @retuns (double): Geometric Area of shape
*/
double Rectangle::geometricArea() const
{
	return (height * width);
}

/*
* Calculates the Geometric Perimeter
* @retuns (double): Geometric Perimeter of shape
*/
double Rectangle::geometricPerimeter() const
{
	return (2 * (height + width));
}

/*
* Calculates the Screen Area
* @retuns (int): Screen Area of shape
*/
int Rectangle::screenArea() const
{
	return this->geometricArea();
}

/*
* Calculates the Screen Area
* @retuns (int): Screen Area of shape
*/
int Rectangle::screenPerimeter() const
{
	return (this->geometricPerimeter() - 4);
}

/*
* Returns the height
* @retuns (double): returns the height
*/
double Rectangle::getHeight() const
{
	return height;
}

/*
* returns the width of the shape object
* @retuns (double): returns the width
*/
double Rectangle::getWidth() const
{
	return width;
}

/*
* Draw The shape on the canvas using forechar
* @param canvas(Canvas): canvas object
* @param row(int): rows of the object
* @param col(int): column of the object
* @param foreChar(char): foreground character
* @param backChar(char): background character
*/
void Rectangle::draw(Canvas & canvas, int row, int col, char foreChar, char backChar) const
{
	setFill(canvas, row, col, backChar);
	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			canvas[row + i][col + j] = foreChar;
			//canvas.put(row + i, col + j,foreChar);
		}
	}
}
