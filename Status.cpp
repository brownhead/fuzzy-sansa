#include "Status.hpp"

Status::Status() 
	:health(100)
{
}

	
void Status::print_health()
{
	cout << "Health: " << health << endl;
}

void Status::add_item(int itemtype)
{
	Armor *temp0 = 0;
	if (itemtype <= 4)
	{
		item.push_back(new Armor);
	}
	Item new_item(itemtype);
	*(item.at(item.size()-1)) = new_item;
	temp0 = static_cast <Armor *> (item.at(item.size()-1));
	temp0 -> generate_stats();
}

void Status::print_armor()
{
	Armor *temp = 0;
	//add_item(2);
	//cout << item.size() << endl;
	for (unsigned i = 0; i < item.size(); i++)
	{
		temp = static_cast <Armor *>(item.at(i));
		//cout << temp -> item_type << endl;
		if (temp -> item_type == 1)
		{
			temp -> armor_traits();
		}
		if (temp -> item_type == 2)
		{
			temp -> armor_traits();
		}
		if (temp -> item_type == 3)
		{
			temp -> armor_traits();
		}
		if (temp -> item_type == 4)
		{
			temp -> armor_traits();
		}
	}
}
