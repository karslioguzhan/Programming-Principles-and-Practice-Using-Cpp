#include "Point.h"

Point::Point():
	x{0}, y{0}
{
}

Point::Point(int inputX, int inputY):
	x{inputX}, y{inputY}
{
}

void Point::setX(int newX)
{
	x = newX;
}

void Point::setY(int newY)
{
	y = newY;
}

bool Point::operator==(const Point& second)
{
	return ((this->x == second.x) && (this->y == second.y));
}

bool Point::operator!=(const Point& second)
{
	return !(*this == second);
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}
