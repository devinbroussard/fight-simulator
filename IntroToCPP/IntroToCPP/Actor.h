#pragma once

class Actor
{
public:
	Actor(const char* name) { m_name = name; m_started = false; }
	~Actor() {}

	const char* getName() { return m_name; }
	bool getStarted() { return m_started; }

	virtual void start() { m_started = true; }
	virtual void update() {};
	virtual void draw() {};
	virtual void end() {};

private:
	const char* m_name;
	bool m_started;
};