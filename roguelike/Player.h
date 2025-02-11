#pragma once

#include "Enemy.h"
class Player
{
private:
	int _x{ 0 };
	int _y{ 0 };

	int _lastDamage{ 0 };
	bool _isDamaged{ false };
	
	int _health{ 100 };
public:
	// Position
	int GetX() const { return _x; }
	int GetY() const { return _y; }

	void SetX(int newX) { _x = newX; }
	void SetY(int newY) { _y = newY; }

	// Health
	int GetHealth() const { return _health; }
	bool IsDamaged() const { return _isDamaged; }
	int GetLastDamageAmount() const { return _lastDamage; }

	// Attacking
	void DoAttack(int x, int y);

	// Receiving attack
	void ReceiveAttack(Enemy& enemy);
	void CheckForDamage(Enemy& enemy);

	void ResetDamageState();

	int damageDelt = 0;
};

