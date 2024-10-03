#include"Game.h"
#include"SceneManager.h"
#include"Player.h"

int main() {
	Player player;
	Game game(&player);

	game.StartGame();
}