#include <vector>

#include "AllClasses.h"

enum CTypeOfComponent {COMP_MAIN, COMP_HEALTH, COMP_POWER,COMP_ACTIVE_SKILL,
		COMP_PASSIVE_SKILL, COMP_TARGET_SKILL};

class ITower {
public:
	std::vector<IComponent*> components;
	virtual ~ITower() {}
};

class IComponent {
public:
	virtual CTypeOfComponent GetType() = 0;
	virtual ~IComponent() {}
	//virtual void Update(double dt) = 0;
};

class IFactory {
public:
	virtual ~IFactory() {}
	virtual ITower* Create() = 0;
};

//-----------------------------------------------------------------------

class IComponentMain : IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_MAIN; }
};

class IComponentHealth : IComponent{
public:
	virtual CTypeOfComponent GetType() { return COMP_HEALTH; }
	//virtual void TakeDamage(int dmg) = 0;
};

class IComponentPower : IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_POWER; }
	virtual bool IsPowered() = 0;
};

class IComponentTargetSkill : IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_TARGET_SKILL; }

};

class IComponentActiveSkill : IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_ACTIVE_SKILL; }

};

class IComponentPassiveSkill : IComponent {
public:
	virtual CTypeOfComponent GetType() { return COMP_PASSIVE_SKILL; }

};

//-----------------------------------------------------------------------

class CComponentHealth : IComponentHealth {
private:
	int _MAX_HP;
	int _hp;
public:
	CComponentHealth(int max_hp) {
		_MAX_HP = max_hp;
		_hp = max_hp;
	}

};

class CComponentMain : IComponentMain {
private:
	CPoint* _point;
	CPlayer* _player;
public:
	CComponentMain(CPoint* point, CPlayer* player) {
		_player = player;
		_point = point;
	}
};

class CComponentTargetAttack : IComponentTargetSkill {
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

class CComponentPower : IComponentPower {
public:
	bool IsPowered() { return true; }
};

//-----------------------------------------------------------------------

class CTowerNormal : ITower {
public:
	CComponentHealth* health;
	CComponentMain* main;
	CComponentPower* power;
	CComponentTargetAttack* attack;
};

class FactoryNormal : IFactory {
private:
	int HP = 100;
	int DMG = 5;
	int RADIUS = 100;
	double ATTACK_KD = 0.5;

public:
	ITower* Create() {
		CTowerNormal tower;
		tower.health = new CComponentHealth(HP);
		tower.main = new CComponentMain(nullptr, nullptr);
		tower.power = new CComponentPower();
		tower.attack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_KD);

		tower.components.push_back(&tower.health);
	}
};