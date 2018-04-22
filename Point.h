#pragma once
#include "AllClasses.h"
#include "Tower.h"

/**
 * \brief Класс Point
 */

class CPoint : public IComposite{
public:
    void Update(double dtime) override;
    int x, y;

private:
    unique_ptr<CTower> tower;
};