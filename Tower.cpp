#include <vector>

#include "AllClasses.h"
#include "Tower.h"
#include "TowerComponents.h"

IComponent::~IComponent() {}
IFactory::~IFactory() {}

void CTower::AddComponent(IComponent* comp) {
    components.push_back(unique_ptr<IComponent>(comp));
}

//-----------------------------------------------------------------------

CTower* CFactoryNormal::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD));

    return tower;
}

const int CFactoryNormal::GetCD() {
    return CD;
}

const int CFactoryNormal::GetCOST() {
    return COST;
}

/////

CTower* CFactoryLongRange::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD));

    return tower;
}

const int CFactoryLongRange::GetCD() {
    return CD;
}

const int CFactoryLongRange::GetCOST() {
    return COST;
}

/////

CTower* CFactoryProtective::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());


    return tower;
}

const int CFactoryProtective::GetCD() {
    return CD;
}

const int CFactoryProtective::GetCOST() {
    return COST;
}

//////

CTower* CFactoryMissile::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentActiveSkillMissile(SKILL_CD));

    return tower;
}

const int CFactoryMissile::GetCD() {
    return CD;
}

const int CFactoryMissile::GetCOST() {
    return COST;
}

/////

CTower* CFactorySupport::Create(CPoint* point, CPlayer* player) { 
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentTargetSkillSupport(RADIUS, MULTIPLY));

    return tower;
}

const int CFactorySupport::GetCD() {
    return CD;
}

const int CFactorySupport::GetCOST() {
    return COST;
}

//////

CTower* CFactoryMoving::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerMoving());
    tower->AddComponent(new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD));
    tower->AddComponent(new CComponentActiveSkillMoving(SKILL_CD));

    return tower;
}

const int CFactoryMoving::GetCD() {
    return CD;
}

const int CFactoryMoving::GetCOST() {
    return COST;
}

///////

CTower* CFactoryHealer::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentPassiveSkillHeal(RADIUS, HEAL_SPEED));

    return tower;
}

const int CFactoryHealer::GetCD() {
    return CD;
}

const int CFactoryHealer::GetCOST() {
    return COST;
}

/////////

CTower* CFactoryEnlarger::Create(CPoint* point, CPlayer* player) { 
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerUsual());
    tower->AddComponent(new CComponentPassiveSkillEnlarger(ENLARGE_SPEED));


    return tower;
}

const int CFactoryEnlarger::GetCD() {
    return CD;
}

const int CFactoryEnlarger::GetCOST() {
    return COST;
}

//////

CTower* CFactoryGenerator::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
    tower->AddComponent(new CComponentGraphic());
    tower->AddComponent(new CComponentPowerGenerate());
	tower->AddComponent(new CComponentPassiveSkillEnlarger(ENLARGE_SPEED));

    return tower;
}

const int CFactoryGenerator::GetCD() {
    return CD;
}

const int CFactoryGenerator::GetCOST() {
    return COST;
}

///////

CTower* CFactoryBase::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    tower->AddComponent(new CComponentHealth(HP));
    tower->AddComponent(new CComponentAccessory(player));
    tower->AddComponent(new CComponentPosition(point));
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
