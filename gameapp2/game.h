#pragma once
#include<SDL.h>
#include<vector>
#include<unordered_map>
#include"SpriteComponent.h"
#include<string>

class Game {
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	void RemoveActor(class Actor* actor);
	void AddActor(class Actor* actor);
	SDL_Texture* GetTexture(const std::string& fileName);
private:
	void GenerateOutput();
	void ProcessInput();
	void UpdateGame();

	void LoadData();
	void UnloadData();
	SDL_Window* mWindow;
	bool mIsRunning;
	bool mUpdatingActors;
	Uint32 mTickCount;
	SDL_Renderer* mRenderer;
	std::unordered_map<std::string, SDL_Texture*>mTextures;
	std::vector<class Actor*> mActors, mPendingActors;
	std::vector<class SpriteComponent*> mSprites;
	class Ship* mShip;
};