#include "Item.hpp"

Item::Item()
	:weight(0), item_type(1)
{
}

Item::Item(int itemtype)
	:weight(0), item_type(itemtype)
{
}


string Armor::where_does_this_go()
{
	switch (body_part) 
	{
			case 0:
				item_type = 1;
				return "Head";
			case 1:
				item_type = 2;
				return "Chest";
			case 2:
				item_type = 3;
				return "Feet";
			case 3:
				item_type = 4;
				return "Hands";
	}
	return "None";
}

void Armor::armor_traits()
{
	if (item_type == 1)
	{
		cout << "Helmet" << endl;
		print_stats();
	}
	if (item_type == 2)
	{
		cout << "Chest" << endl;
		print_stats();
	}
	if (item_type == 3)
	{
		cout << "Feet" << endl;
		print_stats();
	}
	if (item_type == 4)
	{
		cout << "Hands" << endl;
		print_stats();
	}

}

void Armor::print_stats()
{
	if (bonus_health > 0)
	{
		cout << "Bonus Health: " << bonus_health << endl;
	}
	if (defense > 0)
	{
		cout << "Defense: " << defense << endl;
	}
	if (weight > 0)
	{
		cout << "Weight of item: " << weight << endl;
	}
	if (bonus_damage > 0)
	{
		cout << "Bonus damage: " << bonus_damage << endl;
	}
}

void Armor::generate_stats()
{

	bonus_health = rand()%4;
	bonus_damage = rand()%7;
	defense = rand()%3;
}

