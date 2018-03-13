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
	CComponentHealth * health;
	CComponentAccessory* accessory;
	CComponentPosition* position;
	CComponentGraphic* graphic;
	CComponentPower* power;
	CComponentTargetAttack* attack;
};

ITower* CFactoryNormal::Create() {
	CTowerNormal* tower = new CTowerNormal;
	tower->health = new CComponentHealth(HP);
	tower->accessory = new CComponentAccessory(PLAYER);
	tower->position = new CComponentPosition(POINT);
	tower->graphic = new CComponentGraphic();
	tower->power = new CComponentPower();
	tower->attack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD);

	tower->components.resize(6, nullptr);
	tower->components[0] = tower->health;
	tower->components[1] = tower->accessory;
	tower->components[2] = tower->power;
	tower->components[3] = tower->position;
	tower->components[4] = tower->attack;
	tower->components[5] = tower->graphic;

	return tower;
}