#pragma once
#include <iostream>

// Drill 1
class Point
{
public:
	Point();
	Point(int inputX, int inputY);
	void setX(int newX);
	void setY(int newY);
	bool operator==(const Point& second);
	bool operator!=(const Point& second);
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};

