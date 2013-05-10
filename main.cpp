#include "map_generation.hpp"
#include "control.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;




void print_map(char map[80][80], Control position, Size view) {

	for (int i = position.get_X(map) - view.x/2; i <= position.get_X(map) + view.x/2; ++i) {
		for (int j = position.get_Y(map) - view.y/2; j <= position.get_Y(map) + view.y/2; ++j) {
			if(i == position.get_X(map) && j == position.get_Y(map)){
				cout  << '@' << " ";
			}
			else
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
}

class Status
{
	private:
		int health;
	public:
		Status();
		void print_health(char map[80][80]);
};

Status::Status()
	:health(100)
{
}
	
void Status::print_health(char map[80][80])
{
	//health: 100
	cout << "Health: " << health << endl;
}

void player_interface(Control position, char map[][80], Size view, Status life_points)
{
	char input;
	while (cin >> input && (input != 'Q' || input != 'q'))
	{
		if (input == 'W' || input == 'w') //UP 
		{
			position.move_up(map);
		}
		if (input == 'A' || input == 'a') //LEFT
		{
			position.move_left(map);
		}
		if (input == 'S' || input == 's') //DOWN
		{
			position.move_down(map);
		}
		if (input == 'D' || input == 'd') //UP 
		{
			position.move_right(map);
		}
		print_map(map, position,view);
		//position.print_full_map(map);
		if (input == 'M' || input == 'm')
		{
			position.print_full_map(map);
			life_points.print_health(map);
		}
	}
	cout << endl;
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

	Size view;
	view.x = 10;
	view.y = 10;

	Control position(x, y); //starting position for dude
	Point dude_location;

	map_variables(map); //GENERATES THE MAP
	map[x][y] = '#';

	set_points(dude_location, position.get_X(map), position.get_Y(map));
	print_map(map, position, view);
	cout << endl;
	Status life_points;
	player_interface(position, map, view, life_points);

	return 0;
}

