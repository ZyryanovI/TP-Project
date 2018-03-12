#include <vector>

#include "AllClasses.h"
#include "Tower.h"
#include "TowerComponents.h"

ITower::~ITower() {}
IComponent::~IComponent() {}
IFactory::~IFactory() {}

//-----------------------------------------------------------------------



//-----------------------------------------------------------------------

class CTowerNormal : public ITower {
public:
	CComponentHealth* health;
	CComponentMain* main;
	CComponentPower* power;
	CComponentTargetAttack* attack;
};

ITower* CFactoryNormal::Create() {
	CTowerNormal* tower = new CTowerNormal;
	tower->health = new CComponentHealth(HP);
	tower->main = new CComponentMain(nullptr, nullptr);
	tower->power = new CComponentPower();
	tower->attack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD);

	tower->components.resize(4, nullptr);
	tower->components[0] = tower->health;
	tower->components[1] = tower->main;
	tower->components[2] = tower->power;
	tower->components[3] = tower->health;

	return tower;
}