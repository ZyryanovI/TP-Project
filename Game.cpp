#include "Game.h"

/**
 * \brief Реализация конструктора, деструктора класса Игра
 */

CGame* CGame::_obj = nullptr;

CGame::~CGame() {
    for (int i = 0; i < points.size(); ++i) {
        delete points[i];
    }
}

/**
 * \brief Реализация функции Instance
 *
 */

CGame* CGame::Instance() {
    if (_obj == nullptr)
        _obj = new CGame;

    return _obj;
}

/**
 * \brief Реализация функции DeleteInstance
 *
 */

void CGame::DeleteInstance() {
    if (_obj != nullptr) {
        delete _obj;
        _obj = nullptr;
    }
}

void CGame::Update(double dtime) {

}