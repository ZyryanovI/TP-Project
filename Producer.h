#pragma once
#include "Tower.h"

/**
 * \brief Интерфейс класса Producer
 */

class IProducer {
public:
	virtual ~IProducer();
	virtual void SetFactoryAndPlayer(CPlayer* player, shared_ptr<IFactory> factory) = 0;
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
	~CProducer();

	/**
	 * \brief Функция, задающая игрока и фабрику
	 * @param player
	 * @param factory
	 */

	void SetFactoryAndPlayer(CPlayer* player, shared_ptr<IFactory> factory);

	/**
	 * \brief Функция, проверяющая, можно ли создать башню
	 * Проверяет, достаточно ли у игрока средств и нет ли
	 */

	bool IsAbleToCreate();

	/**
	 * \brief Функция, непосредственно создающая башню
	 * @param point - указатель на точку на поле
	 * @return указатель на башню
	 */

	CTower* Create(CPoint* point);


private:
	void ChangeMoney();
	void ChangeCD();
	shared_ptr<IFactory> _factory;
	CPlayer* _player;
	double _cd;
};