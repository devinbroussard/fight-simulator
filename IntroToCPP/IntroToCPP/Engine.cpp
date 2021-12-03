#include "Engine.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_entityIndex = 0;
}

void Engine::run()
{
	start();
	while (!getApplicationShouldClose())
	{
		update();
		draw();
	}
	end();
}

void Engine::start()
{
	Entity devin = Entity('d', 100, 20, 15);
	Entity skeleton = Entity('s', 100, 25, 5);
	Entity troll = Entity('t', 50, 20, 0);

	m_entities[0] = devin;
	m_entities[1] = skeleton;
	m_entities[2] = troll;
	m_entityCount = 3;

	m_fighterOne = &m_entities[0];
	m_fighterTwo = &m_entities[1];
	m_entityIndex = 2;
}

void Engine::update()
{

	if (m_fighterOne->getHealth() <= 0 && m_entityIndex < m_entityCount)
	{
		m_fighterOne = &m_entities[m_entityIndex];
		m_entityIndex++;
	}
	if (m_fighterTwo->getHealth() <= 0 && m_entityIndex < m_entityCount)
	{
		m_fighterTwo = &m_entities[m_entityIndex];
		m_entityIndex++;
	}

	if ((m_fighterOne->getHealth() <= 0 || m_fighterTwo->getHealth() <= 0) && m_entityIndex >= m_entityCount)
	{
		m_applicationShouldClose = true;
		return;
	}

	m_fighterOne->attack(m_fighterTwo);
	m_fighterTwo->attack(m_fighterOne);
}

void Engine::draw()
{
	m_fighterOne->printStats();
	m_fighterTwo->printStats();
	system("pause");
	system("cls");
}

void Engine::end()
{
}
;
