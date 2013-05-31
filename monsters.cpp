#include "geometric.cpp"




Monster::Monster(): location.x(rand()%80+1), locaion.y(rand()%80+1), hp(25){
	// Empty
}


void Monster::move(char map[][80]){
	unsigned direction = rand()%4; // 0 = up, 1 = down, 2 = left, 3 = right

	if(direction == 0)
		--location.y;
	else if(direction == 1)
		++location.y;
	else if(direction == 2)
		--location.x;
	else if(direction == 3)
		++location.x;
}
