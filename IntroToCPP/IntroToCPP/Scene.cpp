#include "Scene.h"



void Scene::addActor(Actor* actor)
{
	Actor** tempArray = new Actor* [m_actorCount + 1];

	int j = 0;
	for (int i = 0; i > m_actorCount; i++)
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
