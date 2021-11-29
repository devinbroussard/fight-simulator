#include "Entity.h";

	Entity::Entity(char icon, float health, float attackPower, float defensePower)
	{
		m_icon = icon;
		m_health = health;
		m_attackPower = attackPower;
		m_defensePower = defensePower;
	}

	float Entity::takeDamage(float damageAmount)
	{
		float damageTaken = damageAmount * (100 - getDefensePower()) / 100; 

		if (damageTaken < 0) damageTaken = 0;

		m_health -= damageTaken;

		if (m_health < 0) m_health = 0;
	}

	float Entity::attack(Entity entity)
	{
		return entity.takeDamage(getAttackPower());
	}