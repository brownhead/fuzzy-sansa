#pragma once

#include <iostream>
#include <vector>
#include "Item.hpp"

using namespace std;

class Status
{
	private:
		int health;
		vector<Item*> item;
	public:
		Status();
		void add_item(int);
		void print_armor();
		void print_health();
};
