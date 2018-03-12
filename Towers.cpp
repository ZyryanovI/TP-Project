#include <vector>

#include "AllClasses.h"
#include "Towers.h"

ITower::~ITower() {}
IComponent::~IComponent() {}
IFactory::~IFactory() {}

//-----------------------------------------------------------------------

class IComponentMain : public IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_MAIN; }
};

class IComponentHealth : public IComponent{
public:
	virtual CTypeOfComponent GetType() { return COMP_HEALTH; }
	//virtual void TakeDamage(int dmg) = 0;
};

class IComponentPower : public IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_POWER; }
	virtual bool IsPowered() = 0;
};

class IComponentTargetSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_TARGET_SKILL; }

};

class IComponentActiveSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_ACTIVE_SKILL; }

};

class IComponentPassiveSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_PASSIVE_SKILL; }

};

//-----------------------------------------------------------------------

class CComponentHealth : public IComponentHealth {
private:
	int _MAX_HP;
	int _hp;
public:
	CComponentHealth(int max_hp) {
		_MAX_HP = max_hp;
		_hp = max_hp;
	}

};

class CComponentMain : public IComponentMain {
private:
	CPoint* _point;
	CPlayer* _player;
public:
	CComponentMain(CPoint* point, CPlayer* player) {
		_player = player;
		_point = point;
	}
};

class CComponentTargetAttack : public IComponentTargetSkill {
private:
	int _DAMAGE;
	int _RADIUS;
	double _MAX_KD;

	double kd;
public:
	CComponentTargetAttack(int damage, int radius, double max_kd) {
		_DAMAGE = damage;
		_RADIUS = radius;
		_MAX_KD = max_kd;
	}
};

class CComponentPower : public IComponentPower {
public:
	bool IsPowered() { return true; }
};

//-----------------------------------------------------------------------

class CTowerNormal : public ITower {
public:
	CComponentHealth* health;
	CComponentMain* main;
	CComponentPower* power;
	CComponentTargetAttack* attack;
};

/*class CFactoryNormal : public IFactory {
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
};*/

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