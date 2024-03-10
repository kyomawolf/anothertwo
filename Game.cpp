#include "Game.h"
#include <raylib-ccp.hpp>

Gamenit() {
	if (instance == nullptr)
		instance = Game();
	else
	window = raylib::Window(RESOLUTION_X, RESOLUTION_Y, TITLE + VERSION);

}

Game::Game() {}

void Game::mainLoop() {


	while (!window.WindowShouldClose()) {
		Game
	
	}
}

