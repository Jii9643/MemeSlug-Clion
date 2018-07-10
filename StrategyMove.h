//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_STRATEGYMOVE_H
#define MEMESLUG_STRATEGYMOVE_H

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StrategyMove
{
public:
    StrategyMove(float x, float y) : moveX(x), moveY(y) {}

    virtual Vector2f StrategyEnemy() = 0;

protected:

    float moveX;
    float moveY;
};

#endif //MEMESLUG_STRATEGYMOVE_H
