#include "Engine.h"
#include "StartScene.h"
#include "FightScene.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;

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
		update();
		draw();
	}
	end();
}

void Engine::addScene(Scene* scene)
{
}

void Engine::start()
{
	StartScene* startScene = new StartScene();
	FightScene* fightScene = new FightScene();

	addScene(fightScene);
	addScene(startScene);

	m_scenes[m_currentSceneIndex]->start();
}

void Engine::update()
{
	m_scenes[m_currentSceneIndex]->update();
}

void Engine::draw()
{
	m_scenes[m_currentSceneIndex]->draw();
}

void Engine::end()
{
	m_scenes[m_currentSceneIndex]->end();
}
;
