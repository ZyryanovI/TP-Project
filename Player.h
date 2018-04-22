#pragma once

#include "Tower.h"

/**
 * \brief Класс Player
 * Содержит сумму денежных единиц, которыми владеет игрок, ...
 *
 */

class CPlayer : public IComposite {
public:

    int money;

    void Update(double dtime) override;

private:

};