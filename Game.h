#IFNDEF GAME_H
#define GAME_H

#include <exception>

#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080

#define TITLE "test"
#define VERSION " 0.0.1"

class Game {
public:
	static void init();

	class Exception : public exception {
		enum Location {Init, LoadRessources, MainLoop, UnloadRessouces, Close};

	}
	
	void loadRessources();
	void mainLoop();
	void unloadRessources();
	void close();
private:
	static Game& instance;

	Game();
	~Game();

};
#endif
