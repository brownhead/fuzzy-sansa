#pragma once

struct Point{
	int x;
	int y;

	Point();
	Point(int, int);
};

struct Size{
	int x;
	int y;
};

void set_points(Point &, int, int);
