#pragma once
#include "Tower.h"
#include "Player.h"
/**
 * \brief Интерфейс класса Producer
 */

class IProducer {
public:
	virtual ~IProducer() = default;
	virtual void SetFactoryAndPlayer(CPlayer* player, IFactory* factory) = 0;
	virtual bool IsAbleToCreate() = 0;
	virtual CTower* Create(CPoint*) = 0;
};

/**
 * \brief Реализация интерфейса класса Producer
 * При помощи фабрики создает башню и делает все побочные действия
 *
 */

class CProducer : public IProducer {
public:
	CProducer();
	~CProducer() override = default;

	/**
	 * \brief Функция, задающая игрока и фабрику
	 * @param player
	 * @param factory
	 */

	void SetFactoryAndPlayer(CPlayer* player, IFactory* factory) override;

	/**
	 * \brief Функция, проверяющая, можно ли создать башню
	 * Проверяет, достаточно ли у игрока средств и не находится ли она на перезарядке
	 */

	bool IsAbleToCreate() override ;

	/**
	 * \brief Функция, непосредственно создающая башню
	 * @param point - указатель на точку на поле
	 * @return указатель на башню
	 */

	CTower* Create(CPoint* point) override;

private:
	void ChangeMoney();
	void ChangeCD();
	IFactory* _factory;
	CPlayer* _player;
	double _cd;
};