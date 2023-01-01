#include"actor.h"
#include "game.h"
#include "component.h"
#include <algorithm>
Actor::Actor(Game* game)
	:mState(EActive)
	, mPosition(Vector2::Zero)
	, mScale(1.0f)
	, mRotation(0.0f)
	, mGame(game)
{
	mGame->AddActor(this);
}


Actor::~Actor(){
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}
void Actor::UpdateComponent(float deltaTime) {
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}
void Actor::Update(float deltaTime){
	if (mState == EActive)
	{
		UpdateComponent(deltaTime);
		UpdateActor(deltaTime);
	}
}



void Actor::RemoveComponent(Component* component){
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
void Actor::addComponent(Component* component) {
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (;
		iter != mComponents.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	mComponents.insert(iter, component);
}

void Actor::UpdateActor(float deltaTime)
{
}