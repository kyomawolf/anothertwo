//
// Created by kyomawolf on 10.02.24.
//

#include <iostream>
#include <exception>
#include "Game.h"


int main() {
	try{
		Game::init();
	
		Game::loadRessources();
	
		Game::mainLoop();

		Game::unloadRessources();

		Game::close();

	} catch( Game::Exception &e ) {
		if (e.location > GAME::Exception::Location::LoadRessouces)
			Game::unloadRessources();
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;

	}
	return EXIT_SUCCESS;
}
