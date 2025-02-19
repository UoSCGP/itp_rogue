#include "Enemy.h"

#include "Grid.h"


const char Enemy::enemySymbol = '!';

void Enemy::MoveTowardsPlayer(const std::vector< std::vector<char>>& grid, int colSize, int rowSize)
{
	// move right towards player
	if (x < _player->GetX())
	{
		if ((x < rowSize - 1) &&
			(grid[x + 1][y] != Grid::wallSymbol))
		{
			x++;
			return;
		}
	}

	if (x > _player->GetX()) 
	{	
		if ((x > 1) &&
			(grid[x - 1][y] != Grid::wallSymbol))
		{
			x--;
			return;
		}
	}

	if (y < _player->GetY())
	{
		if ((y < colSize - 1) &&
			(grid[x][y + 1] != Grid::wallSymbol))
		{
			y++;
			return;
		}
	}

	if (y > _player->GetY())
	{
		if ((y > 1) &&
			(grid[x][y - 1] != Grid::wallSymbol))
		{
			y--;
			return;
		}
	}
}

bool Enemy::CheckForAdjacentPlayer() 
{
	const int xDifference = abs(getY() - _player->GetX());
	const int yDifference = abs(getX() - _player->GetY());

	return (xDifference == 1 && yDifference == 0) || (xDifference == 0 && yDifference == 1);
}

int Enemy::GetAttackDamage() 
{
	// Return random value between 1 and this->maxDamage.
	std::uniform_int_distribution<> attackRange(1, this->maxDamage);

	return attackRange(this->mt);
}