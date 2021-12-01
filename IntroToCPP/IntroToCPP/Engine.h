#pragma once
#include "Entity.h"

class Engine
{
public:
	Engine();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; };
	static void setApplicationShouldCloose(bool value) { m_applicationShouldClose = value; };

	void run();

private:
	static bool m_applicationShouldClose;
	Entity m_entities[3];
	Entity m_fighterOne;
	Entity m_fighterTwo;
	int m_entityCount;
	int m_entityIndex;

	void start();
	void update();
	void draw();
	void end();
};