#include "Entity.h";
#include "Scene.h";
#include <iostream>

	Entity::Entity(char icon, float health, float attackPower, float defensePower)
	{
		m_icon = icon;
		m_health = health;
		m_attackPower = attackPower;
		m_defensePower = defensePower;
	}

	Entity::Entity()
	{
		m_icon = '\0';
		m_health = 0;
		m_attackPower = 0;
		m_defensePower = 0;
	}

	float Entity::takeDamage(float damageAmount)
	{
		float damageTaken = damageAmount * (100 - getDefensePower()) / 100; 

		if (damageTaken < 0) damageTaken = 0;

		m_health -= damageTaken;

		if (m_health < 0) m_health = 0;

		return damageTaken;
	}

	float Entity::attack(Entity* entity)
	{
		return entity->takeDamage(getAttackPower());
	}

	void Entity::printStats()
	{
		std::cout << m_icon << std::endl;
		std::cout << "Health: " << m_health << std::endl;
		std::cout << "Attack Power: " << m_attackPower << std::endl;
		std::cout << "Defense Power: " << m_defensePower << std::endl;
	}
