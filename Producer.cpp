#include "Producer.h"

IProducer::~IProducer() {}

//************************************************
CProducer::CProducer() {
	_factory = nullptr;
	_player = nullptr;
	_cd = 0;
}

CProducer::~CProducer() {

}

void CProducer::SetFactoryAndPlayer(CPlayer* player, shared_ptr<IFactory> factory)
{
	_factory = factory;
	_player = player;
}

bool CProducer::IsAbleToCreate() {
	return _cd <= 0 && _player->money >= _factory->GetCOST();
}

CTower* CProducer::Create(CPoint* point) {
	if (IsAbleToCreate()) {
		ChangeCD();
		ChangeMoney();
		return _factory->Create(point, _player);
	}
	else {
		return nullptr;
	}
}

void CProducer::ChangeMoney() {
	_player->money -= _factory->GetCOST();
}

void CProducer::ChangeCD() {
	_cd = _factory->GetCD();
}
