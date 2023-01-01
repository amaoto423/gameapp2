#pragma once
#include"SpriteComponent.h"
#include<vector>
#include "game.h"
#include "Math.h"
class BGSpriteComponent :public SpriteComponent {
public:
	BGSpriteComponent(class Actor* owner, int draworder = 10);
	void Update(float deltatime)override;
	void Draw(SDL_Renderer* renderer)override;
	void SetBGTextures(const std::vector<SDL_Texture*>& textures);
	void SetScreenSize(const Vector2& size) { mScreenSize = size; };
	void SetScrollSpeed(float Speed) { mScreenSpeed = Speed; };
	float GetScrollSpeed() { return mScreenSpeed; }

private:

	struct BGTexture {
		SDL_Texture* mTexture;
		Vector2 mOffSet;
	};
	std::vector<BGTexture> mBGTextures;
	float mScreenSpeed;
	Vector2 mScreenSize;

};