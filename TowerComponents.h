#pragma once
#include "Tower.h"
#include "AllClasses.h"

class IComponentMain : public IComponent {
public:
	virtual CTypeOfComponent GetType();
};

class IComponentHealth : public IComponent {
public:
	virtual CTypeOfComponent GetType();
};

class IComponentPower : public IComponent {
public:
	virtual CTypeOfComponent GetType();
};

class IComponentTargetSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class IComponentActiveSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class IComponentPassiveSkill : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class CComponentHealth : public IComponentHealth {
private:
	int _MAX_HP;
	int _hp;
public:
	CComponentHealth(int max_hp);
};

class CComponentMain : public IComponentMain {
private:
	CPoint * _point;
	CPlayer* _player;
public:
	CComponentMain(CPoint* point, CPlayer* player);
};

//------------------------------------------------------------------------

class CComponentTargetAttack : public IComponentTargetSkill {
private:
	int _DAMAGE;
	int _RADIUS;
	double _MAX_KD;

	double kd;
public:
	CComponentTargetAttack(int damage, int radius, double max_kd);
};

class CComponentPower : public IComponentPower {

};