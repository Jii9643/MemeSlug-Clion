//
// Created by jii on 03/07/18.
//

#include "Bullet.h"


Bullet::Bullet(Texture *texture, Vector2f position, Vector2f scale,
               Vector2f direction, float initialVelocity, float maxVelocity, float acceleration)
{

    this->dtMultiplier = 60.f;

    //Inizializzazione del bullet.
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->initialVelocity = initialVelocity;
    this->maxVelocity = maxVelocity;
    this->acceleration = acceleration;
    this->direction = direction;
    this->currentVelocity = Vector2f(
            initialVelocity * this->direction.x,
            initialVelocity * this->direction.y);



    this->sprite.setOrigin(
            this->sprite.getGlobalBounds().width / 2,
            this->sprite.getGlobalBounds().height / 2
    );

    this->sprite.setScale(scale);
    this->sprite.setPosition(position);
}


Bullet::~Bullet()
{
}

//Traiettoria del proiettile.
void Bullet::Movement(const float &dt)
{
    if (this->acceleration > 0.0f)
    {
        if (this->currentVelocity.x < this->maxVelocity)
            this->currentVelocity.x += this->acceleration * this->direction.x*dt*this->dtMultiplier;

        if (this->currentVelocity.y < this->maxVelocity)
            this->currentVelocity.y += this->acceleration * this->direction.y*dt*this->dtMultiplier;
    }
    else
    {
        this->currentVelocity = Vector2f(
                this->maxVelocity * this->direction.x,
                this->maxVelocity * this->direction.y);
    }
    this->sprite.move(this->currentVelocity*dt*this->dtMultiplier);
}


void Bullet::Update(const float &dt)
{
    this->Movement(dt);
}


void Bullet::Draw(RenderTarget &target)
{
    target.draw(this->sprite);
}