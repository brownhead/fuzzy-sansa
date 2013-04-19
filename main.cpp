#include <iostream>

using namespace std;

void print_map(char map[80][80]) {
	for (unsigned int i = 0; i < 80; ++i) {
		for (unsigned int j = 0; j < 80; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main()
{
	cout << "Welcome to fuzzy-sansa!";

	char map[80][80];

	for (unsigned int i = 0; i < 80; ++i) {
		for (unsigned int j = 0; j < 80; ++j) {
			map[i][j] = '.';
		}
	}

	print_map(map);

	return 0;
}