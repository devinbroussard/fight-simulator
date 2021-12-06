#include "Engine.h"
#include "StartScene.h"
#include "FightScene.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;
int Engine::m_sceneCount = 0;
int Engine::m_currentSceneIndex = 0;
Scene** Engine::m_scenes = new Scene * [0];

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::run()
{
	start();
	while (!getApplicationShouldClose())
	{
		draw();
		update();
	}
	end();
}

void Engine::addScene(Scene* scene)
{
	Scene** tempArray = new Scene*[m_sceneCount + 1];

	int j = 0;
	for (int i = 0; i < m_sceneCount; i++)
	{
		tempArray[j] = m_scenes[i];
		j++;
	}
	tempArray[j] = scene;

	m_scenes = tempArray;
}

void Engine::start()
{
	StartScene* startScene = new StartScene();

	addScene(startScene);

	m_scenes[m_currentSceneIndex]->start();
}

void Engine::update()
{
	m_scenes[m_currentSceneIndex]->update();
}

void Engine::draw()
{
	system("cls");
	m_scenes[m_currentSceneIndex]->draw();
}

void Engine::end()
{
	m_scenes[m_currentSceneIndex]->end();
}
;
