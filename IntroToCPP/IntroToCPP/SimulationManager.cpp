#include "SimulationManager.h"
#include "Actor.h"
#include "Engine.h"

SimulationManager::SimulationManager() :
	Actor::Actor("Simulation Manager")
{
	m_entityCount = 0;
}

SimulationManager::~SimulationManager()
{
	delete m_entities;
}

void SimulationManager::start()
{
	Entity* devin = new Entity("Devin", 100, 40, 15);
	Entity* skeleton = new Entity("Skeleton", 100, 20, 5);
	Entity* goblin = new Entity("Goblin", 100, 30, 0);

	m_entities = new Entity*[3];
	m_entities[0] = devin;
	m_entities[1] = skeleton;
	m_entities[2] = goblin;
	m_entityCount = 3;
}

void SimulationManager::update()
{
	if (!m_fighterOne->isAlive() && stillEntitiesLeft())
	{
		m_fighterOne = m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	
	if (!m_fighterTwo->isAlive() && stillEntitiesLeft())
	{
		m_fighterTwo = m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if ((!m_fighterOne->isAlive() || m_fighterTwo->isAlive()) && !stillEntitiesLeft())
	{
		Engine::setApplicationShouldClose(true);
	}
}

void SimulationManager::draw()
{
	m_fighterOne->draw();
	std::cout << '\n';
	m_fighterTwo->draw();
}

