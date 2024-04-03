#include "Game.h"
#include <filesystem>
#include <iostream>
#include <thread>
#include <dlfcn.h>


class Ressource symbolHandler(std::string pathName) {
    //todo move into unique ptr
    Ressource library;

    std::cout << "open plugin" << std::endl;
    void* pluginhandle = dlopen(pathName.c_str(), RTLD_NOW | RTLD_LOCAL);
    std::cout << "fetching initializer symbol" << std::endl;
    *(void **)(&library.Initializer) = dlsym(pluginhandle, "Initialize");
    std::cout << "finished loading plugin" << std::endl;
}

//loads dynamic libraries, can fail, if nothing is found, unloadable libs are ignored, throwing a warning
void actualLoad(std::vector<Ressource>& game, bool& finshedLoading, size_t amount, int& loaded, std::filesystem::path targetpath) {
    
    for (auto& idx : std::filesystem::recursive_directory_iterator{targetpath}) {
        if (idx.is_regular_file() && idx.path().extension() == ".so") {
            std::cout << "found a target file: " << idx << std::endl;
            symbolHandler(idx.path());
            loaded++;
        }
    }
    
    // for (auto i = 0; i < amount; i++) {
	// 	std::cout << "loading..." << std::endl;
	// 	Ressource temp;
	// 	game.emplace_back(temp);
	// 	std::this_thread::sleep_for(std::chrono::seconds(2));
	// 	loaded++;
	// }
	finshedLoading = true;
	return;
}
