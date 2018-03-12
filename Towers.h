#pragma once
#include <vector>

enum CTypeOfComponent {
	COMP_MAIN,
	COMP_HEALTH,
	COMP_POWER,
	COMP_ACTIVE_SKILL,
	COMP_PASSIVE_SKILL,
	COMP_TARGET_SKILL
};

class IComponent {
public:
	virtual CTypeOfComponent GetType() = 0;
	virtual ~IComponent();
	//virtual void Update(double dt) = 0;
};

class ITower {
public:
	std::vector<IComponent*> components;
	virtual ~ITower();
};

class IFactory {
public:
	virtual ~IFactory();
	virtual ITower* Create() = 0;
};

//------------------------------------------------------

class CFactoryNormal : public IFactory {
private:
	const int HP = 100;
	const int DMG = 5;
	const int RADIUS = 100;
	const double ATTACK_KD = 0.5;

public:
	ITower * Create();
};