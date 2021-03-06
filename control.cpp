#include "Control.hpp"
#include <iostream>
using namespace std;

Control::Control (int dude_x, int dude_y)
	:dude_x(dude_x), dude_y(dude_y)
{
}

void Control::print_full_map (char map[][80]) const //done
{
	int spot;
	for (unsigned int r = 0; r < 80; r++)
	{
		for (unsigned int c = 0; c < 80; c++)
		{
			cout << map[r][c];
			if (map[dude_x][dude_y] == '#')
			{
				spot = 0;
			}
			if (map[dude_x][dude_y] == '%')
			{
				spot = 1;
			}
			map[dude_x][dude_y] = '@';
		}
		cout << endl;
	}
	if (spot == 0)
	{
		map[dude_x][dude_y] = '#';
	}
	else if (spot == 1)
	{
		map[dude_x][dude_y] = '%';
	}
}


void Control::move_up(char map[][80]) //
{
	if (valid_move(map, 0))
	{
		dude_x -= 1;
	}
}


void Control::move_down(char map[][80]) //
{
	if (valid_move(map, 1))
	{
		dude_x += 1;
	}
}


void Control::move_left(char map[][80]) //
{
	if (valid_move(map, 2))
	{
		dude_y -= 1;
	}
}


void Control::move_right(char map[][80]) //done
{
	if (valid_move(map, 3))
	{
		dude_y += 1;
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


bool Control::valid_move(char map[][80], int direction){
	if(direction == 0 && (map[dude_x - 1][dude_y] == '#' || map[dude_x - 1][dude_y] == '%')) // Up
		return true;

	else if(direction == 1 && (map[dude_x+1][dude_y] == '#' || map[dude_x+1][dude_y] == '%')) // Down
		return true;

	else if(direction == 2 && (map[dude_x][dude_y - 1] == '#' || map[dude_x][dude_y - 1] == '%')) // Left
		return true;

	else if(direction == 3 && (map[dude_x][dude_y + 1] == '#' || map[dude_x][dude_y + 1] == '%')) // Right
		return true;

	else
		return false;
}
