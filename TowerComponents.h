#pragma once
#include "Tower.h"
#include "AllClasses.h"

/**
 * \brief Интерфейс компоненты
 */

class IComponent : public IComposite {
private:
    CTower* _tower;

public:
	virtual CTypeOfComponent GetType() = 0;
	virtual ~IComponent() = default;
	void Update(double dt) override;
	virtual void Die();
	void SetTower(CTower*);
};

//************************************************************8

/**
 * \brief Интерфейс компоненты позиции
 */

class IComponentPosition : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты графики
 */

class IComponentGraphic : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты принадлежности
 */

class IComponentAccessory : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты здоровья
 */

class IComponentHealth : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты эненргии
 */

class IComponentPower : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты направленной способности
 */

class IComponentTargetSkill : public IComponent {
public:
    CTypeOfComponent GetType() override ;

};

/**
 * \brief Интерфейс компоненты активной способности
 */

class IComponentActiveSkill : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};

/**
 * \brief Интерфейс компоненты пассивной способности
 */

class IComponentPassiveSkill : public IComponent {
public:
    CTypeOfComponent GetType() override ;
};


//------------------------------------------------------------------------

/**
 * \brief Реализация интерфейса компоненты здоровья
 */

class CComponentHealth : public IComponentHealth{
private:
    int _MAX_HP;
    int _hp;
public:

	/**
	 * \brief Конструктор задающий максимальное здоровье
	 * @param max_hp
	 */

    explicit CComponentHealth(int max_hp);


};

/**
 * \brief Реализация интерфейса компоненты позиции
 */

class CComponentPosition : public IComponentPosition{
private:
    CPoint * _position;
public:

	/**
	 * \brief Конструктор, задающий позицию
	 * @param position - указатель на точку
	 */

    explicit CComponentPosition(CPoint* position);
};

/**
 * \brief Реализация интерфейса компоненты принадлежности
 */

class CComponentAccessory : public IComponentAccessory{
private:
    CPlayer * _player;
public:

	/**
	 * \brief Конструктор, задающий игрока
	 * @param player - указатель на игрока
	 */

    explicit CComponentAccessory(CPlayer* player);
};

/**
 * \brief Реализация интерфейса компоненты графики
 */

class CComponentGraphic : public IComponentGraphic{
private:

public:

};

/**
 * \brief Реализация интерфейса компоненты атаки
 */

class CComponentTargetAttack : public IComponentTargetSkill{
private:
    int _DAMAGE;
    int _RADIUS;
    double _MAX_KD;

    double kd;
public:

	/**
	 * \brief Конструктор, задающий урон, радиус и перезарядку атаки
	 * @param damage
	 * @param radius
	 * @param max_kd
	 */

    CComponentTargetAttack(int damage, int radius, double max_kd);
};

/**
 * \brief Реализация интерфейса компоненты энергии в общем случае
 */

class CComponentPowerUsual : public IComponentPower{

};

/**
 * \brief Реализация интерфейса компоненты энергии для передвигающейся башни
 */

class CComponentPowerMoving : public IComponentPower{

};

/**
 * \brief Реализация интерфейса компоненты энергии для генерирующей башни
 */

class CComponentPowerGenerate : public IComponentPower{

};

/**
 * \brief Реализация интерфейса компоненты пассивной способности лечения
 */

class CComponentPassiveSkillHeal : public IComponentPassiveSkill{
private:
	int _RADIUS;
	int _HEAL_PER_SEC;
public:

	/**
	 * \brief Констурктор, задающий параметры лечения
	 * @param radius
	 * @param heal_speed
	 */

	CComponentPassiveSkillHeal(int radius, int heal_speed);
};

/**
 * \brief Реализация интерфейса компоненты направленной способности поддержка
 */

class CComponentTargetSkillSupport : public IComponentTargetSkill{
private:
	int _RADIUS;
	double _MULTIPLY;
public:

	/**
	 * \brief Конструктор, задающий параметры помощи
	 * @param radius
	 * @param multiply
	 */

	CComponentTargetSkillSupport(int radius, double multiply);
};

/**
 * \brief Реализация интерфейса компоненты пассивной способности добычи ресурсов
 */

class CComponentPassiveSkillEnlarger : public IComponentPassiveSkill{
private:
	int _SPEED;
public:

	/**
	 * \brief Конструктор, задающий скорость добычи ресурсов
	 * @param speed
	 */

    explicit CComponentPassiveSkillEnlarger(int speed);
};

/**
 * \brief Реализация интерфейса компоненты активной способности передвижение
 */

class CComponentActiveSkillMoving : public IComponentActiveSkill{
private:
	int _KD;
public:

	/**
	 * \brief Конструктор, задающий перезарядку перемещения
	 * @param kd
	 */

    explicit CComponentActiveSkillMoving(int kd);
};

/**
 * \brief Реализация интерфейса компоненты активной способности, являющийся ракетой
 */

class CComponentActiveSkillMissile : public IComponentActiveSkill{
private:
	int _KD;
public:

	/**
	 * \brief Конструктор, задающий перезарядку ракеты
	 * @param kd
	 */

    explicit CComponentActiveSkillMissile(int kd);
};

/**
 * \brief Компонента, отвечающая за то, что если эта башня умрет - игрок проиграет
 */
class CComponentShoudNotDie : public IComponent {
public:
    CTypeOfComponent  GetType() override;
};