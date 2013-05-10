#include "map_generation.hpp"
#include "control.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


struct Point{
	int x;
	int y;
};

struct Size{
	int x;
	int y;
};


void set_points(Point &dude, int x, int y){
	dude.x = x;
	dude.y = y;
}

void print_map(char map[80][80], Point dude_location, Size view) {

	for (int i = dude_location.x - view.x/2; i <= dude_location.x + view.x/2; ++i) {
		for (int j = dude_location.y - view.y/2; j <= dude_location.y + view.y/2; ++j) {
			if(i == dude_location.x && j == dude_location.y){
				cout  << '@' << " ";
			}
			else
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
}

int main()
{
	srand(time(NULL));

	int x = 40;
	int y = 40;

	cout << "Welcome to fuzzy-sansa!\n";

	char map[80][80];

	for (unsigned int i = 0; i < 80; ++i) {
		for (unsigned int j = 0; j < 80; ++j) {
			map[i][j] = '.';
		}
	}

	map_variables(map);


	Control position(x, y); //starting position for dude
	Point dude_location;

	Size view;
	view.x = 10;
	view.y = 10;

	set_points(dude_location, position.get_X(map), position.get_Y(map));
	print_map(map, dude_location, view);
	cout << endl;
	position.print_full_map(map);

	return 0;
}

