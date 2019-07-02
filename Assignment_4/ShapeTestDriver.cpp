#include <iostream>
#include "Canvas.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Oblique.h"
#include "RightTriangle.h"

/*
* Author Himanshu Kohli
*/

using std::cout;
using std::cin;
using std::endl;

// function prototypes
void drawHouseEalrlyBinding();
void drawHouseLateBinding();

int main()
{
	drawHouseEalrlyBinding();
	drawHouseLateBinding();
	return 0;
}

void drawHouseEalrlyBinding()
{
	// draw a house front view on a 50-column and 50-row titles Canvas
	Canvas poster(50, 50);

	std::string title("a geometric house: front view");
	int pos = 8;
	for (auto ch : title)
	{
		poster.put(0, pos, ch);
		++pos;
	}

	Oblique roof(41, "house roof");
	roof.draw(poster, 1, 1, '/');// house roof

	Rectangle chimney(2, 10, "chimeny on the roof");
	chimney.draw(poster, 8, 4, '/'); // chimeny on the roof

	Rectangle skylightFrame(9, 5, "frame around skylight");
	skylightFrame.draw(poster, 11, 17, 'h');// frame around skylight

	Rectangle skylight(7, 3, "skylight on the roof");
	skylight.draw(poster, 12, 18, ' '); // skylight on the roof

	Rectangle frontWall(41, 22, "front wall");
	frontWall.draw(poster, 23, 1, ':');  // front wall

	Rectangle top_bottom_left_brackets(21, 1, "top and bottom left square brackets");
	top_bottom_left_brackets.draw(poster, 22, 1, '['); // top left square brackets
	top_bottom_left_brackets.draw(poster, 44, 1, '['); // bottom left square brackets

	Rectangle top_bottom_right_brackets(20, 1, "top  and bottom right square brackets");
	top_bottom_right_brackets.draw(poster, 22, 22, ']'); // top right square brackets
	top_bottom_right_brackets.draw(poster, 44, 22, ']');// bottom right square brackets

	Rectangle right_wall_brackets(2, 22, "right wall brackets");
	right_wall_brackets.draw(poster, 23, 40, ']'); // right wall brackets

	Rectangle left_wall_brackets(2, 22, "left wall brackets");
	left_wall_brackets.draw(poster, 23, 1, '['); // left wall brackets

	Rectangle rightDoor(6, 7, "front right door");
	rightDoor.draw(poster, 36, 30, '-');// front left door

	Rectangle rightDoorFrame(1, 7, "front right door hinge");
	rightDoorFrame.draw(poster, 36, 35, 'H');// front left door

	Rectangle leftDoor(6, 7, "front left door");
	leftDoor.draw(poster, 36, 23, '-');// front left door

	Rectangle leftDoorFrame(1, 7, "front left door hinge");
	leftDoorFrame.draw(poster, 36, 22, 'H');// front left door

	Rectangle doorsMiddle(2, 7, "vertical center panel between front doors");
	doorsMiddle.draw(poster, 36, 28, '|'); // vertical center panel between front doors

	Rectangle doorTopBottomBar(14, 1, "door top and bottom bar");
	doorTopBottomBar.draw(poster, 35, 22, 'H'); // door top bar
	doorTopBottomBar.draw(poster, 43, 22, '='); // door bottom bar

	Rectangle doorKnobs(2, 1, "door knobs");
	doorKnobs.draw(poster, 40, 28, 'O'); // vertical center panel between front doors

										 // Triagle windows above front door
	Oblique Triagle_above_front_door(8, "triagle door top");
	Triagle_above_front_door.draw(poster, 24, 22, '*'); // triagle door top

	Rectangle doggyDoor = Rectangle(4, 3, "doggy door");
	doggyDoor.draw(poster, 40, 3, '~');// doggy door

	Rhombus diamond_shape_window_on_front_wall(7, "diamond shape window on front wall");
	diamond_shape_window_on_front_wall.draw(poster, 25, 4, 'o', ':');// diamond shape window on front wall

	Rectangle StairSlash(41, 1, "front stairs slashes");
	StairSlash.draw(poster, 45, 1, '\\'); // row of front stairs slashes
	StairSlash.draw(poster, 46, 2, '\\'); // row of front stairs slashes
	StairSlash.draw(poster, 47, 3, '\\'); // row of front stairs slashes
	StairSlash.draw(poster, 48, 4, '\\'); // row of front stairs slashes

	Rectangle pole(1, 12, "flag pole");
	pole.draw(poster, 10, 41, 'i'); // flag pole

	RightTriangle flag(6, "flag");
	flag.draw(poster, 11, 42, '\\'); // flag

	cout << poster << endl;
	cout << chimney << endl;
	cout << roof << endl;
	cout << skylightFrame << endl;
	cout << skylight << endl;
	cout << frontWall << endl;
	cout << top_bottom_left_brackets << endl;
	cout << top_bottom_right_brackets << endl;
	cout << top_bottom_right_brackets << endl;
	cout << top_bottom_left_brackets << endl;
	cout << leftDoor << endl;
	cout << rightDoor << endl;
	cout << leftDoorFrame << endl;
	cout << rightDoorFrame << endl;
	cout << doorsMiddle << endl;
	cout << Triagle_above_front_door << endl;
	cout << doggyDoor << endl;
	cout << diamond_shape_window_on_front_wall << endl;
	cout << StairSlash << endl;
	cout << pole << endl;
	cout << flag << endl;
}

void drawHouseLateBinding()
{
	// draw a house front view on a 50-column and 50-row titles Canvas
	Canvas poster(50, 50);

	std::string title("a geometric house: front view");
	int pos = 8;
	for (auto ch : title)
	{
		poster.put(0, pos, ch);
		++pos;
	}

	Shape* shapePtr{ nullptr }; // a pointer to draw any shape

	Oblique roof(41, "house roof");
	shapePtr = &roof;
	shapePtr->draw(poster, 1, 1, '/');// house roof

	Rectangle chimney(2, 10, "chimeny on the roof");
	shapePtr = &chimney;
	shapePtr->draw(poster, 8, 4, '/'); // chimeny on the roof

	Rectangle skylightFrame(9, 5, "frame around skylight");
	shapePtr = &skylightFrame;
	shapePtr->draw(poster, 11, 17, 'h');// frame around skylight

	Rectangle skylight(7, 3, "skylight on the roof");
	shapePtr = &skylight;
	shapePtr->draw(poster, 12, 18, ' '); // skylight on the roof

	Rectangle frontWall(41, 22, "front wall");
	shapePtr = &frontWall;
	shapePtr->draw(poster, 23, 1, ':');  // front wall

	Rectangle top_bottom_left_brackets(21, 1, "top and bottom left square brackets");
	shapePtr = &top_bottom_left_brackets;
	shapePtr->draw(poster, 22, 1, '['); // top left square brackets
	shapePtr->draw(poster, 44, 1, '['); // bottom left square brackets

	Rectangle top_bottom_right_brackets(20, 1, "top  and bottom right square brackets");
	shapePtr = &top_bottom_right_brackets;
	shapePtr->draw(poster, 22, 22, ']'); // top right square brackets
	shapePtr->draw(poster, 44, 22, ']');// bottom right square brackets

	Rectangle right_wall_brackets(2, 22, "right wall brackets");
	shapePtr = &right_wall_brackets;
	shapePtr->draw(poster, 23, 40, ']'); // right wall brackets

	Rectangle left_wall_brackets(2, 22, "left wall brackets");
	shapePtr = &left_wall_brackets;
	shapePtr->draw(poster, 23, 1, '['); // left wall brackets

	Rectangle rightDoor(6, 7, "front right door");
	shapePtr = &rightDoor;
	shapePtr->draw(poster, 36, 30, '-');// front left door

	Rectangle rightDoorFrame(1, 7, "front right door Frame");
	shapePtr = &rightDoorFrame;
	shapePtr->draw(poster, 36, 35, 'H');// front left door

	Rectangle leftDoor(6, 7, "front left door");
	shapePtr = &leftDoor;
	shapePtr->draw(poster, 36, 23, '-');// front left door

	Rectangle leftDoorFrame(1, 7, "front left door Frame");
	shapePtr = &leftDoorFrame;
	shapePtr->draw(poster, 36, 22, 'H');// front left door

	Rectangle doorsMiddle(2, 7, "vertical center panel between front doors");
	shapePtr = &doorsMiddle;
	shapePtr->draw(poster, 36, 28, '|'); // vertical center panel between front doors

	Rectangle doorTopBottomBar(14, 1, "door top and bottom bar");
	shapePtr = &doorTopBottomBar;
	shapePtr->draw(poster, 35, 22, 'H'); // door top bar
	shapePtr->draw(poster, 43, 22, '='); // door bottom bar

	Rectangle doorKnobs(2, 1, "door knobs");
	shapePtr = &doorKnobs;
	shapePtr->draw(poster, 40, 28, 'O'); // vertical center panel between front doors

										 // Triagle windows above front door
	Oblique Triagle_above_front_door(8, "triagle door top");
	shapePtr = &Triagle_above_front_door;
	shapePtr->draw(poster, 24, 22, '*'); // triagle door top

	Rectangle doggyDoor = Rectangle(4, 3, "doggy door");
	shapePtr = &doggyDoor;
	shapePtr->draw(poster, 40, 3, '~');// doggy door

	Rhombus diamond_shape_window_on_front_wall(7, "diamond shape window on front wall");
	shapePtr = &diamond_shape_window_on_front_wall;
	shapePtr->draw(poster, 25, 4, 'o', ':');// diamond shape window on front wall

	Rectangle StairSlash(41, 1, "stair slash"); // a row of  stair slashes
	shapePtr = &StairSlash;
	shapePtr->draw(poster, 45, 1, '\\'); // row of front stairs slashes
	shapePtr->draw(poster, 46, 2, '\\'); // row of front stairs slashes
	shapePtr->draw(poster, 47, 3, '\\'); // row of front stairs slashes
	shapePtr->draw(poster, 48, 4, '\\'); // row of front stairs slashes

	Rectangle pole(1, 12, "flag pole");
	shapePtr = &pole;
	shapePtr->draw(poster, 10, 41, 'i'); // flag pole

	RightTriangle flag(6, "flag");
	shapePtr = &flag;
	shapePtr->draw(poster, 11, 42, '\\'); // flag


	cout << poster << endl;
	//cout << chimney << endl;
	//cout << roof << endl;
	//cout << skylightFrame << endl;
	//cout << skylight << endl;
	//cout << frontWall << endl;
	//cout << top_bottom_left_brackets << endl;
	//cout << top_bottom_right_brackets << endl;
	//cout << top_bottom_right_brackets << endl;
	//cout << top_bottom_left_brackets << endl;
	//cout << leftDoor << endl;
	//cout << rightDoor << endl;
	//cout << leftDoorFrame << endl;
	//cout << rightDoorFrame << endl;
	//cout << doorsMiddle << endl;
	//cout << Triagle_above_front_door << endl;
	//cout << doggyDoor << endl;
	//cout << diamond_shape_window_on_front_wall << endl;
	//cout << StairSlash << endl;
	//cout << pole << endl;
	//cout << flag << endl;
}
