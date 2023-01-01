#pragma once
#include "actor.h"
class Ship :public Actor {
public:
	Ship(class Game* game);
	void UpdateActor(float deltatime)override;
	void ProcessKeyBoard(const uint8_t* state);
	float GetRightSpeed() { return mRightSpeed; }
	float GetDownSpeed() { return mDownSpeed; }
private:
	float mRightSpeed;
	float mDownSpeed;

};