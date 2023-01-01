#pragma once
#include "Math.h"
#include<vector>
#include "game.h"
class Actor {
public:
	enum State {
		EActive,EPaused,EDead
	};
	Actor(class Game* game);
	virtual ~Actor();
	void Update(float deltaTime);
	void UpdateComponent(float deltaTime);
	virtual void UpdateActor(float deltaTime);
	//�Q�b�^�[�E�Z�b�^�[
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }


	void addComponent(class Component* component);
	void RemoveComponent(class Component* component);
private:
	State mState;
	Vector2 mPosition;
	float mScale;
	float mRotation;
	std::vector<class Component*> mComponents;
	class Game* mGame;
};
