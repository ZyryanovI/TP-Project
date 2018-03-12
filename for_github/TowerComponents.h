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

class CComponentGraphic : public IComponentGraphic { //надо cделать нормально
private:
	
public:
	int Messege() {
		return 1;
	}
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
