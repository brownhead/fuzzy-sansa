#pragma once

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
