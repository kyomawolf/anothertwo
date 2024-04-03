//
// Created by kyomawolf on 10.02.24.
//

#include <raylib-cpp.hpp>
#include <iostream>
#include <exception>
#include "Game.h"


int main() {
	try{
		auto instance = Game::init();
	
		instance.loadRessources();
	
		instance.mainLoop();

		instance.unloadRessources();

		instance.close();

	} catch( Game::Exception &e ) {
		if (e.location > Game::Exception::Location::lLoadRessources) {}
			// Game::unloadRessources();
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;

	}
	return EXIT_SUCCESS;
}
