#pragma once
#include "AllClasses.h"
#include "Player.h"
#include <vector>

/**
 * \brief Класс Игра
 *
 * Класс Игра выполнен с применением паттерна singleton
 * В ней хранится вектор указателей на точки, 2 объекта класса Игрок
 *
 *
 */


class CGame {
private:
    static CGame* _obj;
    CGame();
    
public:

    std::vector<CPoint*> points;
    CPlayer player1;
    CPlayer player2;
    ~CGame();

    CGame(const CGame&) = delete;
    const CGame& operator=(const CGame&) = delete;

    /**
     * \brief Функция, создающая игру
     * @return Указатель на объект класса CGame
     */

    static CGame* Instance();

    /**
     * \brief Функция, удаляющая объект класса игра
     */

    static void DeleteInstance();
};