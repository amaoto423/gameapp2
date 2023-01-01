#include"AnimSpriteComponent.h"
#include "Math.h"
#include"SpriteComponent.h"
AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
{
}

void AnimSpriteComponent::Update(float deltatime) {
	SpriteComponent::Update(deltatime);
	if (mAnimTextures.size() > 0) {
		mCurrFrame += mAnimFPS * deltatime;
		while (mCurrFrame >= mAnimTextures.size()) {
			mCurrFrame -= mAnimTextures.size();
		}
		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
	}
}
void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}
