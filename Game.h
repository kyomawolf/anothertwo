#ifndef GAME_H
#define GAME_H

#include <exception>
#include <raylib-cpp.hpp>
#include <memory>
#include <filesystem>
#include "include/IDynamic.h"

#define RESOLUTION_X 800
#define RESOLUTION_Y 400

#define TITLE "test"
#define VERSION " 0.0.1"

#define MODULE_PATH_GAME "modules"

class Ressource {
public:
	~Ressource();
	IDynamic* (*Initializer)(raylib::Window& window);
	IDynamic* dynamicLib;
};

class Game {
public:
	static Game& init();
	~Game();

	class Exception : public std::exception {
	public:
		enum Location {Init, lLoadRessources, MainLoop, UnloadRessouces, Close};
		explicit Exception(enum Location loc);
		Location location;
	};
	
	void loadRessources();
	void mainLoop();
	void unloadRessources();
	void close();
	// static void actualLoad();
private:
	std::vector<Ressource> ressourceList{};
	size_t ressourceAmount {0};
	int loaded {0};
	bool finishedLoading{false};
	raylib::Window window;
	static Game* instance;
	Game();

};

int actualLoad(std::vector<Ressource>& game, bool& finshedLoading, size_t amount, int& loaded, std::filesystem::path target);

#endif
