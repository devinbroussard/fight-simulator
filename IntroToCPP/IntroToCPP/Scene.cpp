#include "Scene.h"



Scene::Scene()
{
	m_started = false;
	m_actorCount = 0;
	m_actors = new Actor*[0];
}

Scene::~Scene()
{
	delete m_actors;
}

void Scene::addActor(Actor* actor)
{
	Actor** tempArray = new Actor* [m_actorCount + 1];

	int j = 0;
	for (int i = 0; i < m_actorCount; i++)
	{
		tempArray[j] = m_actors[i];
		j++;
	}
	tempArray[j] = actor;

	m_actorCount++;
	m_actors = tempArray;
}

bool Scene::removeActor(Actor* actor)
{
	bool actorRemoved = false;
	Actor** tempArray = new Actor * [m_actorCount - 1];

	int j = 0;
	for (int i = 0; i < m_actorCount; i++)
	{
		tempArray[j] = m_actors[i];

		if (m_actors[i] != actor)
			actorRemoved = true;

		j++;
	}

	if (actorRemoved)
	{
		delete m_actors;
		m_actors = tempArray;
	}

	return actorRemoved;
}

void Scene::update()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (!m_actors[i]->getStarted())
			m_actors[i]->start();
		m_actors[i]->update();
	}
}

void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->draw();
	}
}

void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->end();
	}
}
