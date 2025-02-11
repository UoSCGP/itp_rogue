#include "Player.h"

#include <stdlib.h>
#include <iostream>

// Attack an enemy.
void Player::DoAttack(int x, int y) {
	int damageDelt = rand() % 11;

	std::cout << damageDelt;
}

// This should be on the enemy class.
void Player::CheckForPlayer(Enemy& enemy)
{
	_isDamaged = enemy.CheckForPlayer(_x, _y);

	if (_isDamaged)
	{
		ReceiveAttack(enemy);
	}
}

// Receive an attack from an enemy. 
void Player::ReceiveAttack(Enemy& enemy)
{
	// We've just taken damage from an enemy.
	_isDamaged = true;

	_lastDamage = enemy.GetAttackDamage();
	_health -= _lastDamage;
}


void Player::ResetDamageState()
{
	_isDamaged = false;
	_lastDamage = 0;
}

