#pragma once
#include "Tower.h"

class IProducer {
public:
	virtual ~IProducer();
	virtual void SetFactoryAndPlayer(CPlayer* player, shared_ptr<IFactory> factory) = 0;
	virtual bool IsAbleToCreate() = 0;
	virtual CTower* Create(CPoint*) = 0;
};

class CProducer : public IProducer {
public:
	CProducer();
	~CProducer();

	void SetFactoryAndPlayer(CPlayer* player, shared_ptr<IFactory> factory);

	bool IsAbleToCreate();

	CTower* Create(CPoint* point);


private:
	void ChangeMoney();
	void ChangeCD();
	shared_ptr<IFactory> _factory;
	CPlayer* _player;
	double _cd;
};