#pragma once
#include <vector>
#include "AllClasses.h"
#include <ctime>
#include "Player.h"

enum CTypeOfComponent {
	COMP_CD,
	COMP_COST,
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
	std::vector<IComponent*> components;
public:
	void AddComponent(IComponent* comp);
};

class IFactory {
public:
	virtual ~IFactory();
	virtual CTower* Create() = 0;
	virtual const int GetCD() = 0;  //added that
	virtual const int GetCOST() = 0; //added that
};

//------------------------------------------------------

class CFactoryNormal : public IFactory {
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
	const int CD = 10;
	const int COST = 10;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryLongRange : public IFactory {
private:
	const int HP = 50;
	const int DMG = 5;
	const int RADIUS = 200;
	const double ATTACK_KD = 0.5;
	const int CD = 10;
	const int COST = 15;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryProtective : public IFactory { //еще ничего не менял, решить по поводу того как делать, с компонентами(новая компанента и как со старой взаимодействовать
private:
	const int HP = 200;
	const int DMG = 5;
	const int RADIUS = 200;
	const double ATTACK_KD = 0.5;
	const int CD = 10;
	const int COST = 15;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};



class CFactoryMissile : public IFactory { //сделать
private:
	const int HP = 100;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
	const int CD = 30;
	const int COST = 25;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactorySupport : public IFactory {
private:
	const int HP = 100;
	const int CD = 20;
	const int COST = 15;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};



class CFactoryMoving : public IFactory {
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
	const int CD = 40;
	const int COST = 25;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryHealer : public IFactory {
private:
	const int HP = 100;
	const int RADIUS = 200;
	const double Heal_KD = 0.5;
	const int CD = 20;
	const int COST = 20;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryEnlarger : public IFactory {
private:
	const int HP = 100;
	const int RADIUS = 200;
	const double Heal_KD = 0.5;
	const int CD = 20;
	const int COST = 20;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryGenerator : public IFactory { //посмотреть что с генерированием
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
	const int CD = 10;
	const int COST = 10;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};


class CFactoryBase : public IFactory { //посмотреть что с генерированием
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;
	const int CD = 10;
	const int COST = 10;

	CPoint* POINT = nullptr;
	CPlayer* PLAYER = nullptr;

public:
	const int GetCD();
	const int GetCOST();

	virtual CTower* Create();
};
//****************************************************

class IProducer {
public:
	virtual ~IProducer();
	virtual void SetFactoryAndPlayer(CPlayer* player, IFactory* produser) = 0;
	virtual bool IsAbleToCreate() = 0;
	virtual CTower* Create() = 0;
};


//***************************************

class CProducer : public IProducer{
public:
	CProducer();
	~CProducer();

	void SetFactoryAndPlayer(CPlayer* player, IFactory* produser); 

	bool IsAbleToCreate(); 

	CTower* Create();


private:
	void ChangeMoney();
	void ChangeCD();
	IFactory* _factory;
	CPlayer* _player;
	int _cd_finish;
};

