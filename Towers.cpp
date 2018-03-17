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

/////

CTower* CFactoryLongRange::Create() {
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

const int CFactoryLongRange::GetCD()
{
	return CD;
}

const int CFactoryLongRange::GetCOST()
{
	return COST;
}

/////

CTower* CFactoryProtective::Create() { //
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

const int CFactoryProtective::GetCD()
{
	return CD;
}

const int CFactoryProtective::GetCOST()
{
	return COST;
}


/////

CTower* CFactorySupport::Create() { //
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentPassiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactorySupport::GetCD()
{
	return CD;
}

const int CFactorySupport::GetCOST()
{
	return COST;
}

//////

CTower* CFactoryMoving::Create() {
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));
	tower->AddComponent(new CComponentActiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryMoving::GetCD()
{
	return CD;
}

const int CFactoryMoving::GetCOST()
{
	return COST;
}

///////

CTower* CFactoryHealer::Create() { //
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentPassiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryHealer::GetCD()
{
	return CD;
}

const int CFactoryHealer::GetCOST()
{
	return COST;
}

/////////

CTower* CFactoryEnlarger::Create() { //
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentPassiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryEnlarger::GetCD()
{
	return CD;
}

const int CFactoryEnlarger::GetCOST()
{
	return COST;
}

//////

CTower* CFactoryGenerator::Create() { //сделать
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentPassiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryGenerator::GetCD()
{
	return CD;
}

const int CFactoryGenerator::GetCOST()
{
	return COST;
}

///////

CTower* CFactoryBase::Create() { //сделать
	CTower* tower = new CTower;

	tower->AddComponent(new CComponentHealth(HP));
	tower->AddComponent(new CComponentAccessory(PLAYER));
	tower->AddComponent(new CComponentPosition(POINT));
	tower->AddComponent(new CComponentGraphic());
	tower->AddComponent(new CComponentPower());
	tower->AddComponent(new CComponentPassiveSkill());
	tower->AddComponent(new CComponentCD(CD));
	tower->AddComponent(new CComponentCost(COST));

	return tower;
}

const int CFactoryBase::GetCD()
{
	return CD;
}

const int CFactoryBase::GetCOST()
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
