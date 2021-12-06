#include "StartScene.h"
#include "Engine.h"
#include <iostream>
#include <ctype.h>

void StartScene::draw()
{
	std::cout << "Would you like to start the simulation?\n";
	std::cout << "1. Yes\n";
	std::cout << "2. No\n";
	std::cout << "\n> ";
}

void StartScene::update()
{
	char input;
	std::cin >> input;
	
	if (input == '1')
		Engine::setCurrentScene(1);
	else if (input == '2')
		Engine::setApplicationShouldClose(true);

}

