#include <vector>

#include "AllClasses.h"
#include "Tower.h"
#include "TowerComponents.h"

void CTower::AddComponent(IComponent* comp) {
    components.push_back(unique_ptr<IComponent>(comp));
    comp->SetTower(this);
}

void CTower::Update(double dtime) {
    for(int i =0; i<components.size(); ++i){
        components[i]->Update(dtime);
    }
}

void CTower::Die(){
    for(int i =0; i<components.size(); ++i){
        components[i]->Die();
    }
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

int CFactoryNormal::GetCD() const{
    return CD;
}

int CFactoryNormal::GetCOST() const{
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

int CFactoryLongRange::GetCD() const{
    return CD;
}

int CFactoryLongRange::GetCOST() const{
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

int CFactoryProtective::GetCD() const{
    return CD;
}

int CFactoryProtective::GetCOST() const{
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

int CFactoryMissile::GetCD() const{
    return CD;
}

int CFactoryMissile::GetCOST() const{
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

int CFactorySupport::GetCD() const{
    return CD;
}

int CFactorySupport::GetCOST() const{
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

int CFactoryMoving::GetCD() const{
    return CD;
}

int CFactoryMoving::GetCOST() const{
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

int CFactoryHealer::GetCD() const{
    return CD;
}

int CFactoryHealer::GetCOST() const{
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

int CFactoryEnlarger::GetCD() const{
    return CD;
}

int CFactoryEnlarger::GetCOST() const{
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

int CFactoryGenerator::GetCD() const{
    return CD;
}

int CFactoryGenerator::GetCOST() const{
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
    tower->AddComponent(new CComponentShoudNotDie());

    return tower;
}

int CFactoryBase::GetCD() const{
    return CD;
}

int CFactoryBase::GetCOST() const{
    return COST;
}

//*************************************************
