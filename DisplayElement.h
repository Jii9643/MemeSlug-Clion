//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_DISPLAYELEMENT_H
#define MEMESLUG_DISPLAYELEMENT_H

#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class DisplayElement {
public:
    virtual void Display() = 0;


    virtual  ~DisplayElement() {};

};

#endif //MEMESLUG_DISPLAYELEMENT_H
