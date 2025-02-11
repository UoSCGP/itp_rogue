#pragma once

#include "Inventory.h"

class Player
{
public:
	void DoAttack();
	int damageDelt = 0;
	int health{ 100 };

	void PickUpItem();
	std::vector<int>  GetInventoryStats();

	void PrintItems(ItemType toPrint);

	void EquipArmour(int selection);
private:
	Inventory _inventory;
	ArmourItem* _currentArmour{ nullptr };
};

