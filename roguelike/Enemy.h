#pragma once

#include <vector>
#include <random>

#include "Player.h"

class Enemy {
public:
    Enemy(std::shared_ptr<Player> playerPtr) : _player{playerPtr} {}
    Enemy(const int xPos, const int yPos, std::shared_ptr<Player> playerPtr) : x{xPos}, y{yPos}, _player{playerPtr} {}
    Enemy(const int xPos, const int yPos, const int hp, std::shared_ptr<Player> playerPtr) : x{xPos}, y{yPos}, health{hp}, _player{playerPtr} {}

	void MoveTowardsPlayer(const std::vector< std::vector<char>>& grid, int colSize, int rowSize);

	int getX() { return x; }
	int getY() { return y; }

	// bool CheckForPlayer(int& playerX, int& playerY);

	int GetAttackDamage();

	void setPosition(const int xPos, const int yPos) {
		x = xPos;
		y = yPos;
	}

	static const char enemySymbol;

private:
	int x{ 0 }, y{ 0 };
	int health{ 10 };
	int maxDamage{ 5 };

	std::random_device rd;
	std::mt19937 mt;

    std::shared_ptr<Player> _player;
	
	bool CheckForAdjacentPlayer();
};