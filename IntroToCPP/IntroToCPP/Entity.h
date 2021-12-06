#pragma once
#include "Actor.h"

class Entity :
	public Actor
{
public:
	Entity();
	Entity(char name[], float health, float attackPower, float defensePower);

	float getHealth() { return m_health; }
	float getAttackPower() { return m_attackPower; }
	float getDefensePower() { return m_defensePower; }

	float takeDamage(float damageAmount);
	float attack(Entity* entity);
	void printStats();

private:
		float m_health;
		float m_attackPower;
		float m_defensePower;
};