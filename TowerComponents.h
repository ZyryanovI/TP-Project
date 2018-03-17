#pragma once
#include "Tower.h"
#include "AllClasses.h"

class IComponentPosition : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class IComponentGraphic : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class IComponentAccessory : public IComponent {
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

//////
class IComponentCD : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

class IComponentCost : public IComponent {
public:
	virtual CTypeOfComponent GetType();

};

//------------------------------------------------------------------------

class CComponentCD : public IComponentCD {
private:
	int _CD;
public:
	CComponentCD(int cd);
};

class CComponentCost : public IComponentCost {
private:
	int _COST;
public:
	CComponentCost(int cost);
};

///////

class CComponentHealth : public IComponentHealth {
private:
	int _MAX_HP;
	int _hp;
public:
	CComponentHealth(int max_hp);
};

class CComponentPosition : public IComponentPosition {
private:
	CPoint * _position;
public:
	CComponentPosition(CPoint* position);
};

class CComponentAccessory : public IComponentAccessory {
private:
	CPlayer * _player;
public:
	CComponentAccessory(CPlayer* player);
};

class CComponentGraphic : public IComponentGraphic {
private:

public:

};

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

class CComponentPassiveSkill : public IComponentPassiveSkill { //to divide on healer, support, enlarger



};

class CComponentActiveSkill : public IComponentActiveSkill { //to divide on moving and Missile



};