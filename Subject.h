//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_SUBJECT_H
#define MEMESLUG_SUBJECT_H

#pragma once

#include <vector>
#include "Observer.h"

class Subject {
public:
    virtual void Attach(Observer*o) = 0;
    virtual void Detach(Observer*o) = 0;
    virtual void Notify() const = 0;
    virtual ~Subject() {};
};

#endif //MEMESLUG_SUBJECT_H
