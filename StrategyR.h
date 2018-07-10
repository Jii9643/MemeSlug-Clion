//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_STRATEGYR_H
#define MEMESLUG_STRATEGYR_H

#pragma once

#include"StrategyMove.h"

using namespace sf;

class StrategyR : public StrategyMove
{
public:
    StrategyR(float moveX,float moveY) : StrategyMove (moveX, moveY){}

    Vector2f StrategyEnemy() override
    {
        Vector2f movement;
        movement.x = moveX;
        movement.y = moveY;
        return movement;
    }
};

#endif //MEMESLUG_STRATEGYR_H
