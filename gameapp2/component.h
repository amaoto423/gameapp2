#pragma once


class Component {
public:
	Component(class Actor* owner,int updateOder=100);
	virtual ~Component();
	virtual void Update(float deltatime);
	int GetUpdateOrder()const { return mUpdateOrder; }
protected:
	class Actor* mOwner;
	int mUpdateOrder;
};