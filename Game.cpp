#include "Game.h"

CGame* CGame::_obj = nullptr;

CGame::CGame() {}
CGame::~CGame() {}

CGame* CGame::Instance() {
    if (_obj == nullptr)
        _obj = new CGame;

    return _obj;
}

void CGame::DeleteInstance() {
    if (_obj != nullptr) {
        delete _obj;
        _obj = nullptr;
    }
}
