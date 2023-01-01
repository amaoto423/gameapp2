#include"Ship.h"
#include"AnimSpriteComponent.h"
#include"game.h"
#include"vector"
Ship::Ship( Game* game) :Actor(game), mRightSpeed(0.0f), mDownSpeed(0.0f) {
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};
	asc->SetAnimTextures(anims);
}

void Ship::UpdateActor(float deltatime) {
	Actor::UpdateActor(deltatime);
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltatime;
	pos.y += mDownSpeed * deltatime;
	SetPosition(pos);
}

void Ship::ProcessKeyBoard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
}
