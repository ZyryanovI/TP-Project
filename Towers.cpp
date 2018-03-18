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
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));


    return tower;
}

const int CFactoryNormal::GetCD() {
    return CD;
}

const int CFactoryNormal::GetCOST() {
    return COST;
}

/////

CTower* CFactoryLongRange::Create() {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));

    return tower;
}

const int CFactoryLongRange::GetCD() {
    return CD;
}

const int CFactoryLongRange::GetCOST() {
    return COST;
}

/////

CTower* CFactoryProtective::Create() { //
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));


    return tower;
}

const int CFactoryProtective::GetCD() {
    return CD;
}

const int CFactoryProtective::GetCOST() {
    return COST;
}

//////

CTower* CFactoryMissile::Create() { //
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentActiveSkillMissile());

    return tower;
}

const int CFactoryMissile::GetCD() {
    return CD;
}

const int CFactoryMissile::GetCOST() {
    return COST;
}

/////

CTower* CFactorySupport::Create() { //
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentPassiveSkillSupport());

    return tower;
}

const int CFactorySupport::GetCD() {
    return CD;
}

const int CFactorySupport::GetCOST() {
    return COST;
}

//////

CTower* CFactoryMoving::Create() {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerMoving());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD));
    tower->AddComponent(new CComponentActiveSkillMoving());

    return tower;
}

const int CFactoryMoving::GetCD() {
    return CD;
}

const int CFactoryMoving::GetCOST() {
    return COST;
}

///////

CTower* CFactoryHealer::Create() { //
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentPassiveSkillHeal());

    return tower;
}

const int CFactoryHealer::GetCD() {
    return CD;
}

const int CFactoryHealer::GetCOST() {
    return COST;
}

/////////

CTower* CFactoryEnlarger::Create() { //
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentPassiveSkillEnlarger());


    return tower;
}

const int CFactoryEnlarger::GetCD() {
    return CD;
}

const int CFactoryEnlarger::GetCOST() {
    return COST;
}

//////

CTower* CFactoryGenerator::Create() { //ñäåëàòü
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerGenerate());


    return tower;
}

const int CFactoryGenerator::GetCD() {
    return CD;
}

const int CFactoryGenerator::GetCOST() {
    return COST;
}

///////

CTower* CFactoryBase::Create() { //ñäåëàòü
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(PLAYER));
    tower->AddComponent(new CComponentPosition(POINT));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerGenerate());

    return tower;
}

const int CFactoryBase::GetCD() {
    return CD;
}

const int CFactoryBase::GetCOST() {
    return COST;
}

//*************************************************

IProducer::~IProducer() {}

//************************************************
CProducer::CProducer() {
    _factory = nullptr;
}

CProducer::~CProducer() {

}

void CProducer::SetFactoryAndPlayer(CPlayer* player, IFactory* produser)
{
    _factory = produser;
    _player = player;
}

bool CProducer::IsAbleToCreate() {
    int time = clock();
    time /= CLOCKS_PER_SEC;
    if ((time > _cd_finish) && (_player->money >= _factory->GetCOST())) {
        return true;
    }
    else {
        return false;
    }
}

CTower* CProducer::Create() {
    if(IsAbleToCreate()){
        ChangeCD();
        ChangeMoney();
        return _factory->Create();
    }
    else {
        std::cout << "You can't do that";
        return nullptr;
    }
}

void CProducer::ChangeMoney() {
    _player->money -= _factory->GetCOST();
}

void CProducer::ChangeCD() {

}