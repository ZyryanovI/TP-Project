#include <vector>

#include "AllClasses.h"
#include "Tower.h"
#include "TowerComponents.h"

IComponent::~IComponent() {}
IFactory::~IFactory() {}

void CTower::AddComponent(IComponent* comp) {
	components.push_back(comp);
}

//-----------------------------------------------------------------------

CTower* CFactoryNormal::Create() {
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryNormal::GetCD()
{
	return CD;
}

const int CFactoryNormal::GetCOST()
{
	return COST;
}

//*************************************************

IProducer::~IProducer()
{}

//************************************************
CProducer::CProducer()
{
	_factory = nullptr;
}

CProducer::~CProducer()
{

}

void CProducer::SetFactoryAndPlayer(CPlayer* player, IFactory* produser)
{
	_factory = produser;
	_player = player;
}

bool CProducer::IsAbleToCreate()
{
	int time = clock();
	time /= CLOCKS_PER_SEC;
	if ((time > _cd_finish) && (_player->money >= _factory->GetCOST()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

CTower* CProducer::Create()
{
	if(IsAbleToCreate()) 
	{
		ChangeCD();
		ChangeMoney();
		return _factory->Create();
	}
	else
	{
		std::cout << "You can't do that";
		return nullptr;
	}
}

void CProducer::ChangeMoney()
{
	_player->money -= _factory->GetCOST();
}

void CProducer::ChangeCD()
{
	int time = clock();
	time /= CLOCKS_PER_SEC;
	_cd_finish = time + _factory->GetCD();
}
