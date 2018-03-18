#pragma once
#include <vector>
#include "AllClasses.h"
#include <ctime>
#include "Player.h"
#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

enum CTypeOfComponent {
    COMP_POSITION,
    COMP_GRAPHIC,
    COMP_ACCESSORY,
    COMP_HEALTH,
    COMP_POWER,
    COMP_ACTIVE_SKILL,
    COMP_PASSIVE_SKILL,
    COMP_TARGET_SKILL,
};

class IComponent {
public:
    virtual CTypeOfComponent GetType() = 0;
    virtual ~IComponent();
    //virtual void Update(double dt) = 0;
};

class CTower {
private:
    std::vector<unique_ptr<IComponent> > components;
public:
    void AddComponent(IComponent* comp);
};

class IFactory {
public:
    virtual ~IFactory();
    virtual CTower* Create(CPoint*, CPlayer*) = 0;
    virtual const int GetCD() = 0;  //added that
    virtual const int GetCOST() = 0; //added that
};

//------------------------------------------------------

class CFactoryNormal : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 10;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryLongRange : public IFactory {
private:
    const int HP = 50;
    const int DMG = 5;
    const int RADIUS = 200;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 15;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryProtective : public IFactory { //what to do with that?
private:
    const int HP = 200;
    const int CD = 10;
    const int COST = 15;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};



class CFactoryMissile : public IFactory {
private:
    const int HP = 100;
	const int SKILL_CD = 30;
    const int CD = 30;
    const int COST = 25;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactorySupport : public IFactory {
private:
    const int HP = 100;
	const int RADIUS = 100;
	const double MULTIPLY = 2;

	const int CD = 10;
    const int COST = 15;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};



class CFactoryMoving : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
	const int SKILL_CD = 20;

    const int CD = 40;
    const int COST = 25;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryHealer : public IFactory {
private:
    const int HP = 100;
    const int RADIUS = 200;
    const int HEAL_SPEED = 5;
    const int CD = 20;
    const int COST = 20;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryEnlarger : public IFactory {
private:
    const int HP = 100;
	const int ENLARGE_SPEED = 10;
    const int CD = 20;
    const int COST = 20;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryGenerator : public IFactory { //do something with generating
private:
    const int HP = 100;
	const int ENLARGE_SPEED = 5;
    const int CD = 10;
    const int COST = 10;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};


class CFactoryBase : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 10;

public:
    const int GetCD();
    const int GetCOST();

    virtual CTower* Create(CPoint*, CPlayer*);
};
//****************************************************
