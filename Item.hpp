#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Item
{
	public:
		int weight; 
		int item_type;
	public:
		Item();
		Item(int);
};

class Armor : public Item
{
	private:
		int bonus_health;
		int defense;
		int body_part;
		int bonus_damage;

	public:
		string where_does_this_go();
		void armor_traits();
		void print_stats();
		void generate_stats();
};
