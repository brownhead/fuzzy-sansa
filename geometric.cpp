#include "geometric.hpp"

Point::Point(): x(0), y(0){
	// Empty
}


Point::Point(int x, int y): x(x), y(y){
	// Empty
}


void set_points(Point &dude, int x, int y){
	dude.x = x;
	dude.y = y;
}
