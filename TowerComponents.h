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


//------------------------------------------------------------------------



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

class CComponentPowerUsual : public IComponentPower {

};

class CComponentPowerMoving : public IComponentPower{

};

class CComponentPowerGenerate : public IComponentPower {

};

class CComponentPassiveSkillHeal : public IComponentPassiveSkill {
private:
	int _RADIUS;
	int _HEAL_PER_SEC;
public:
	CComponentPassiveSkillHeal(int radius, int heal_speed);
};

class CComponentTargetSkillSupport : public IComponentTargetSkill {
private:
	int _RADIUS;
	double _MULTIPLY;
public:
	CComponentTargetSkillSupport(int radius, double multiply);
};

class CComponentPassiveSkillEnlarger : public IComponentPassiveSkill {
private:
	int _SPEED;
public:
	CComponentPassiveSkillEnlarger(int speed);
};


class CComponentActiveSkillMoving : public IComponentActiveSkill{
private:
	int _KD;
public:
	CComponentActiveSkillMoving(int kd);
};

class CComponentActiveSkillMissile : public IComponentActiveSkill{
private:
	int _KD;
public:
	CComponentActiveSkillMissile(int kd);
};