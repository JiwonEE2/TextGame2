#include "Player.h"

Player::Player(const string& name)
{
	this->name = name;
	attack = 10;
	health = 100;
	experience = 0;
	level = 1;
}

void Player::Move() const
{
}

void Player::LevelUp() const
{
}

void Player::Attack() const
{
}

void Player::Attacked() const
{
}