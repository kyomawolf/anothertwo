#include "Game.h"
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <future>

Game* Game::instance {new Game()};

Game& Game::init() {
	std::cout << "init in" << std::endl;
	if (instance == nullptr)
		Game::instance = new Game();
	std::cout << "init out";
	return *Game::instance;

}

Game::~Game()
{
		std::cout << "game deconstruct" << std::endl;

}

Game::Game() : window(RESOLUTION_X, RESOLUTION_Y, std::string(TITLE) + VERSION) {
	window.SetTargetFPS(60);
	std::cout << "game construct" << std::endl;
	// determine amount of modules to load
}


//checks for the correct path and if the expected files are there, can fail the program
std::filesystem::path filesystemCheck() {
    //only works on linux (windows use NULL)
    auto value = std::filesystem::canonical("/proc/self/exe");
    value.remove_filename();
    value.append(MODULE_PATH_GAME);
    if (!std::filesystem::is_directory(value)) {}
        //todo return failure
    std::cout << value << std::endl;
    return value;
}


size_t getFileAmount(std::filesystem::path& libPath) {
    size_t fileCounter = 0;
    for (auto& idx : std::filesystem::recursive_directory_iterator{libPath}) {
        std::cout << idx.path() << std::endl;
        std::cout << idx.path().extension() << std::endl;
        if (idx.is_regular_file() && idx.path().extension() == ".so") {
            fileCounter++;
        }
    }
    return fileCounter;
}

//todo implement fail, when some loading goes wrong
void Game::loadRessources()
{
	using namespace std::chrono_literals;
	std::cout << "load ressources" << std::endl;
	raylib::Rectangle rec;
	rec.SetHeight(10);
	rec.SetWidth(10);

	auto libPath = filesystemCheck();
    ressourceAmount = getFileAmount(libPath);
	bool once = false;

	// auto loadingThread = std::thread(actualLoad, std::ref(ressourceList), std::ref(finishedLoading), ressourceAmount, std::ref(loaded), libPath);
	std::packaged_task<int()> loadingThread(std::bind(actualLoad, std::ref(ressourceList), std::ref(finishedLoading), ressourceAmount, std::ref(loaded), libPath));
	auto promised = loadingThread.get_future();

	loadingThread();
	while ((ressourceAmount != loaded) && !window.ShouldClose() && !(promised.wait_for(1ms) == std::future_status::ready)) {
		if (once == false) {
			std::cout << "entered loop" << std::endl;
			once = true;
		}
		window.BeginDrawing();
		window.ClearBackground(raylib::Color::RayWhite());
		for (int i = 0; i < loaded; i++) {
			// use textures instead
			DrawRectangle(100 + (i * 100), 200, rec.width, rec.height, raylib::Color::Red());
		}
		window.EndDrawing();

	}
	std::cout << "exited loop" << std::endl;
	window.BeginDrawing();
		window.ClearBackground(raylib::Color::RayWhite());
		for (int i = 0; i < loaded; i++) {
			// use textures instead
			DrawRectangle(100 + (i * 100), 200, rec.width, rec.height, raylib::Color::Red());
		}
		window.EndDrawing();
	// loadingThread.join();
	exit(EXIT_SUCCESS);
}

void Game::mainLoop()
{
	std::cout << "mainLoop in" << std::endl;

    while (!window.ShouldClose()) {
		// here loop through ressource list and call loop function
	}
	std::cout << "mainLoop out" << std::endl;
}

void Game::unloadRessources()
{
	// unload shared libs, dlcclose all handles
}

void Game::close()
{
	unloadRessources();
}

Game::Exception::Exception(enum Location loc) : location(loc) {}

Ressource::~Ressource() {
	// if (dynamicLib != nullptr)
	// 	delete dynamicLib;
	// dynamicLib = nullptr;
}
