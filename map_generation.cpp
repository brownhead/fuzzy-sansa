#include <cstdlib>

//generates halls
void hall_generation (char map[80][80], int &x, int &y, int &face_direction, 
						int rand_value)
{
	int rand_value2 = rand()%4+4; //lengths of halls tweak for larger/smaller halls
	if (rand_value == 0) // UP
	{
		for (short unsigned int i = 0; i < rand_value2; i++)
		{
			if (x < 8 || y < 8 || x > 72 || y > 72) //too prevent segmentations
			{
				break;
			}
			else
			{
				x--;
				map[x][y] = '#';
			}
		}
		face_direction = 0;
	}
	if (rand_value == 1) //right
	{
		for (short unsigned int i = 0; i < rand_value2; i++)
		{
			if (x < 8 || y < 8 || x > 72 || y > 72)
			{
				break;
			}
			y++;
			map[x][y] = '#';
		} 
	face_direction = 1;
	}

	if (rand_value == 2) //down
	{
		for (short unsigned int i = 0; i < rand_value2; i++)
		{
			if (x < 8 || y < 8 || x > 72 || y > 72)
			{
				break;
			}
			else
			{
				x++;
				map[x][y] = '#';
			}
		} 
		face_direction = 2;
	}
	if (rand_value == 3) //left
	{
		for (short unsigned int i = 0; i < rand_value2; i++)
		{
			if (x < 8 || y < 8 || x > 72 || y > 72)
			{
				break;
			}
			else
			{
				y--;
				map[x][y] = '#';
			}
		} 
		face_direction = 3;
	}
}

//generated halls leaving rooms
void room_hall_out (char map[80][80], int &x, int &y, int &face_direction,
						 int &hall_out, int room_size_L, int room_size_R)
{
	//helps avoid most of hall and room overlaps
	if (face_direction == 0)
	{
		//prevents so choice is not opposite to out direction of hall
		while (hall_out == 2) 
		{
			hall_out = rand()%4;
		}
	}
	if (face_direction == 1)
	{
		while (hall_out == 3)
		{
			hall_out = rand()%4;
		}
	}
	if (face_direction == 2)
	{
		while (hall_out == 0)
		{
			hall_out = rand()%4;
		}
	}
	if (face_direction == 3)
	{
		while (hall_out == 1)
		{
			hall_out = rand()%4;
		}
	}
	//set new position for hall leaving room depending on rand number
	if (hall_out == 0)
	{
		x -= room_size_L;
	}
	if (hall_out == 1)
	{
		y += room_size_L;
	}
	if (hall_out == 2)
	{
		x += room_size_L;
	}
	if (hall_out == 3)
	{
		y -= room_size_L;
	}
	//generates depending on hall_out
	hall_generation(map, x, y, face_direction, hall_out);
}

//generates rooms
void room_generation(char map[80][80], int &x,int &y, int &face_direction,
						 int &hall_out, int room_size_L, int room_size_R)
{
	int rand_direction = rand()%4;
	//fix for position of room when generating a new room
	if (face_direction == 0) //UP move x, y 
	{
		x -= room_size_R;
	}
	if (face_direction == 1) //RIGHT move x,y DONE
	{
		y += room_size_R;
	}
	if (face_direction == 2) //DOWN move x,y DONE
	{
		x += room_size_R;
	}
	if (face_direction == 3) //LEFT move x,y DONE
	{
		y -= room_size_R;
	}

	for (int r = (x - 2); r < (3+x); r++) //row D U
	{
		for (int c =(y - 2); c < (3+y); c++) //column L R
		{
			//this prevented most if not all segmentation faults
			if (r > 0 && c > 0 && r < 80 && c < 80) 
			{
				map[r][c] = '%';
			}
		}
    }

    //decides the exit of the room
    if (rand_direction == 0) //hall exit is UP
    {
    	hall_out = 0;
    }
    if (rand_direction == 1) //hall exit is RIGHT
    {
    	hall_out = 1;
    }
    if (rand_direction == 2) //hall exit is DOWN
    {
    	hall_out = 2;
    }
    if (rand_direction == 3) //hall exit is LEFT
    {
    	hall_out = 3;
    }
    room_hall_out (map, x, y, face_direction, hall_out, room_size_L, 
    													room_size_R);
}

//uses hall_generation and room_generation to generate
void map_generation (char map[80][80], int &x, int &y, int &face_direction,
						int room_size_L, int room_size_R)
{
	//you can increase probablitity of halls by adjusting this %num.
	int	rand_value = rand()%4;
	int hall_out = -1;
	//0 = up, 1 = right, 2 = down, 3 = left
	if (rand_value != 3) //must be 1 lower than %#
	{
		rand_value = rand()%4;
		hall_generation(map, x, y, face_direction, rand_value);
	}
	if (rand_value == 3) //must be l lower than %#
	{
		room_generation(map,x,y,face_direction, hall_out, room_size_L,
							 room_size_R);
	}
}

void update_rooms(char map[80][80])
{	
	//updates room x5 could cause lag but highly doubt it
	//a way to clean up the map and make it neater
	//need to learn a better method in future
	for (int i= 0; i < 5; i++ )
	{
		for (short unsigned int i = 1; i < 79; ++i)
		{
			for (short unsigned int j = 1; j < 79; ++j) 
			{
				int count = 0;
				int count1 = 0;
				int count2 = 0;
				if(map[i-1][j-1] == '#' || map[i-1][j-1] == '%')
				{	
					++count;
				} 
				if(map[i-1][j] == '#' || map[i-1][j] == '%')
				{
					++count;
				} 
				if(map[i-1][j+1] == '#' || map[i-1][j+1] == '%')
				{
					++count;
				} 
				if(map[i][j-1] == '#' || map[i][j-1] == '%')
				{
					++count;
				} 
				if(map[i][j+1] == '#' || map[i][j+1] == '%')
				{
					++count;
				} 
				if(map[i+1][j-1] == '#' || map[i+1][j-1] == '%' )
				{
					++count;
				} 
				if(map[i+1][j] == '#' || map[i+1][j] == '%')
				{
					++count;
				} 
				if(map[i+1][j+1] == '#' || map[i+1][j+1] == '%' )
				{
					++count;
				} 
				if(map[i][j] == '#' || map[i][j] == '%')
				{
					++count;
				}
				//to make the map a little more cleaner (not sure if it matters)
				if(map[i-1][j-1] == '.')
				{	
					++count2;
				} 
				if(map[i-1][j] == '.')
				{
					++count2;
				} 
				if(map[i-1][j+1] == '.')
				{
					++count2;
				} 
				if(map[i][j-1] == '.')
				{
					++count2;
				} 
				if(map[i][j+1] == '.')
				{
					++count2;
				} 
				if(map[i+1][j-1] == '.')
				{
					++count2;
				} 
				if(map[i+1][j] == '.')
				{
					++count2;
				} 
				if(map[i+1][j+1] == '.')
				{
					++count2;
				} 
				if(map[i][j] == '.')
				{
					++count2;
				}
				//BL
				if(map[i-1][j] == '%' && map[i][j+1] == '%' && 
									map[i-1][j+1] == '%' && map[i][j] == '#')
				{
					++count1;
				} 
				//BR
				if(map[i-1][j-1] == '%' && map[i-1][j] == '%' && 
									  map[i][j-1] == '%' && map[i][j] == '#')
				{
					++count1;
				} 
				//TR
				if(map[i+1][j-1] == '%' && map[i+1][j] == '%' && 
									  map[i][j-1] == '%' && map[i][j] == '#')
				{
					++count1;
				} 
				//TL
				if(map[i+1][j+1] == '%' && map[i][j+j] == '%' && 
									  map[i+1][j] == '%' && map[i][j] == '#')
				{
					++count1;
				} 
				if (count > 5)
				{
					map[i][j] = '%';
				}
				if (count1 == 1 && count2 > 2)
				{
					map[i][j] = '%';
				}
			}
		}
	}
}

void map_variables(char map[80][80])
{
	int x = 40; //start position of X
	int y = 40; //start position of Y
	int total_tiles = 20; //number of turns taken. Note: size of map
	int tile_count = 0;
	int face_direction = -1;
	//room_size_R + room_size_L = one side of the room box 3+2 = 5 so 5x5
	int room_size_R = 3; 
	int room_size_L = 2;
	while (tile_count < total_tiles)
	{
		tile_count++;
		map_generation(map, x, y, face_direction, room_size_L, room_size_R);
	}
	update_rooms(map);
}