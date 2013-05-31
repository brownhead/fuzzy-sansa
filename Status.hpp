#pragma once

#include <iostream>
#include <vector>
#include "Item.cpp"

using namespace std;

class Status
{
	private:
		int health;
		vector<Item*> item;
		int num_of_items;
	public:
		Status();
		void add_item(int);
		void print_armor();
		void print_health();
};