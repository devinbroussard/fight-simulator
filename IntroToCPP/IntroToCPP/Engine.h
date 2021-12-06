#pragma once
#include "Entity.h"

class Engine
{
public:
	Engine();
	~Engine();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; };
	static void setApplicationShouldCloose(bool value) { m_applicationShouldClose = value; };

	void run();

private:
	static bool m_applicationShouldClose;
	Entity m_entities[3];
	Entity* m_fighterOne;
	Entity* m_fighterTwo;
	int m_entityCount;
	int m_entityIndex;
	//Entity ** m_entities = new Entity * [5];

	void start();
	void update();
	void draw();
	void end();
};