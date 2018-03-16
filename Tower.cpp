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

	return tower;
}