#include "TowerComponents.h"

CTypeOfComponent IComponentMain::GetType() {
	return COMP_MAIN;
}

CTypeOfComponent IComponentHealth::GetType() {
	return COMP_HEALTH;
}

CTypeOfComponent IComponentPower::GetType() {
	return COMP_POWER;
}

CTypeOfComponent IComponentTargetSkill::GetType() {
	return COMP_TARGET_SKILL;
}

CTypeOfComponent IComponentActiveSkill::GetType() {
	return COMP_ACTIVE_SKILL;
}

CTypeOfComponent IComponentPassiveSkill::GetType() {
	return COMP_PASSIVE_SKILL;
}

//---------------------------------------------------------------------------

CComponentHealth::CComponentHealth(int max_hp) {
	_MAX_HP = max_hp;
	_hp = max_hp;
}

CComponentMain::CComponentMain(CPoint* point, CPlayer* player) {
	_player = player;
	_point = point;
}

CComponentTargetAttack::CComponentTargetAttack(int damage, int radius, double max_kd) {
	_DAMAGE = damage;
	_RADIUS = radius;
	_MAX_KD = max_kd;
}

