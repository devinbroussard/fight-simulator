#pragma once
#include "Entity.h"
#include "Scene.h"

class Engine
{
public:
	Engine();
	~Engine();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; };
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; };
	static Scene* getCurrentScene() { return m_scenes[m_currentSceneIndex]; }
	static void setCurrentScene(int index) { m_currentSceneIndex = index; }

	void run();
	static void addScene(Scene* scene);

private:
	static bool m_applicationShouldClose;
	static Scene** m_scenes;
	static int m_sceneCount;
	static int m_currentSceneIndex;

	void start();
	void update();
	void draw();
	void end();
};