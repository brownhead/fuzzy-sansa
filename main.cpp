#include "map_generation.h"
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

	for (unsigned int i = dude_location.x - view.x/2; i <= dude_location.x + view.x/2; ++i) {
		for (unsigned int j = dude_location.y - view.y/2; j <= dude_location.y + view.y/2; ++j) {
			if(i == dude_location.x && j == dude_location.y){
				cout  << '@' << " ";
			}
			else
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
}

class Control
{
	private:
		int dude_x;
		int dude_y;
	public:
		Control(int, int);
		void print_full_map (char map[][80]) const;
		int get_X(const char map[][80]);
		int get_Y(const char map[][80]);
		void move_right (char map[][80]);
		void move_down (char map[][80]);
		void move_left (char map[][80]);
		void move_up (char map[][80]);
};


Control::Control (int dude_x, int dude_y)
	:dude_x(dude_x), dude_y(dude_y)
{
}

void Control::print_full_map (char map[][80]) const //done
{
	map[dude_x][dude_y] = '@';
	for (unsigned int r = 0; r < 80; r++)
	{
		for (unsigned int c = 0; c < 80; c++)
		{
			cout << map[r][c];
		}
		cout << endl;
	}
}

void Control::move_right(char map[][80]) //done
{
	if (map[dude_x][dude_y + 1] == '#' || map[dude_x][dude_y + 1] == '%')
	{
		dude_y += 1;
	}
}

void Control::move_down(char map[][80]) //
{
	if (map[dude_x+1][dude_y] == '#' || map[dude_x+1][dude_y] == '%')
	{
		dude_x += 1;
	}
}

void Control::move_left(char map[][80]) //
{
	if (map[dude_x][dude_y - 1] == '#' || map[dude_x][dude_y - 1] == '%')
	{
		dude_y -= 1;
	}
}

void Control::move_up(char map[][80]) //
{
	if (map[dude_x - 1][dude_y] == '#' || map[dude_x - 1][dude_y] == '%')
	{
		dude_x -= 1;
	}
}

int Control::get_X(const char map[][80])
{
	return dude_x;
}

int Control::get_Y(const char map[][80])
{
	return dude_y;
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

