#include "TowerComponents.h"

CTypeOfComponent IComponentPosition::GetType()
{
    return COMP_POSITION;
}

CTypeOfComponent IComponentGraphic::GetType()
{
    return COMP_GRAPHIC;
}

CTypeOfComponent IComponentAccessory::GetType()
{
    return COMP_ACCESSORY;
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

CComponentPosition::CComponentPosition(CPoint* position) {
    _position = position;
}

CComponentAccessory::CComponentAccessory(CPlayer* player)
{
    _player = player;
}

CComponentTargetAttack::CComponentTargetAttack(int damage, int radius, double max_kd) {
    _DAMAGE = damage;
    _RADIUS = radius;
    _MAX_KD = max_kd;
}
