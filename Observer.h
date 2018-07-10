//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_OBSERVER_H
#define MEMESLUG_OBSERVER_H

#pragma once



class Observer {
public:

    virtual void Modify(int killSoldier, int killUfo, int points) = 0;
    virtual~Observer() {};


};

#endif //MEMESLUG_OBSERVER_H
