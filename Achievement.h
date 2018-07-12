//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_ACHIEVEMENT_H
#define MEMESLUG_ACHIEVEMENT_H


#pragma once
#include "Platform.h"

class Achievements : public Observer, private DisplayElement
{
public:
    explicit Achievements(Subject *playerach);
    ~Achievements()override;
    virtual void Modify(int ks, int ku, int ptns) override;
    void Display();




protected:
    char string [30] [255];
    Subject *playerach;
    int killSoldier;
    int killUfo;
    int points;
    bool Ach1, Ach2, Ach3;
    Text text;
};

#endif //MEMESLUG_ACHIEVEMENT_H
