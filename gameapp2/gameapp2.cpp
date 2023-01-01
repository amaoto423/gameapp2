#include"SDL.h"
#include "game.h"
int main(int argc, char** argv) {
	// 初期化
	Game game;
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	
	game.Shutdown();

	return 0;
}