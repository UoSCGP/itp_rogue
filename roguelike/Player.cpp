#include "Player.h"

#include <stdlib.h>
#include <iostream>

void Player::DoAttack(int x, int y) {
	int damageDelt = rand() % 11;

	std::cout << damageDelt;
}

void Player::ReceiveAttack(Enemy& enemy)
{
	// We've just taken damage from an enemy.
	_isDamaged = true;

	_lastDamage = enemy.GetAttackDamage();
	_health -= _lastDamage;
}

void Player::CheckForDamage(Enemy& enemy)
{
	_isDamaged = enemy.CheckForPlayer(x, y);

	if (_isDamaged)
	{
		ReceiveAttack(enemy);
	}
}

void Player::ResetDamageState()
{
	_isDamaged = false;
	_lastDamage = 0;
}

