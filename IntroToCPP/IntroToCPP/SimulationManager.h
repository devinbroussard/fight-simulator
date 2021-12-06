#pragma once
#include "Actor.h"
#include "Entity.h"
#include <iostream>

class SimulationManager :
	public Actor
{
public:
	SimulationManager();
	~SimulationManager();

	void start() override;
	void update() override;
	void draw() override;

private:
	Entity** m_entities;
	Entity* m_fighterOne;
	Entity* m_fighterTwo;
	int m_currentFighterIndex;
	int m_entityCount;

	bool stillEntitiesLeft() { return m_currentFighterIndex < m_entityCount; }
};

