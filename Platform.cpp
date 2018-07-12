//
// Created by jii on 03/07/18.
//

#include "Platform.h"

enum bTypes {Grass = 0, Platform};

Platform::Platform(dArr<Texture> &textures, Vector2f position, Vector2f scale, Vector2u windowBounds, int type)
{
    this->dtMultiplier = 60.f;

    this->textures = &textures;
    this->type = type;
    this->block.setTexture((*this->textures)[this->type]);
    this->block.setScale(scale);
    this->block.setPosition(position);

    this->block.setOrigin(
            this->block.getGlobalBounds().width / 2,
            this->block.getGlobalBounds().height / 2
    );

    this->windowBounds = windowBounds;
    this->block.setColor(Color(255, 255, 255, 210));
}


Platform::~Platform()
{
}

void Platform::Draw(RenderTarget &target)
{
    target.draw(this->block);
}