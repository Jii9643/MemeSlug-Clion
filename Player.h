//
// Created by jii on 03/07/18.
//

#ifndef MEMESLUG_PLAYER_H
#define MEMESLUG_PLAYER_H

#pragma once
#include "Achievement.h"
#include"Bullet.h"
#include"Subject.h"
#include <list>

class Player : public Subject
{

public:

    float dtMultiplier;

    Player(std::vector<Texture> &textures, int ks, int ku, int pnts);
    virtual ~Player();

    //Bullets del player.
    Bullet& getBullet(unsigned index);
    void removeBullet(unsigned index);
    inline const int getBulletsSize() const { return this->bullets.size(); }

    //Funzioni inline
    inline const float& getPositionX() const { return this->sprite.getPosition().x; }
    inline const Vector2f& getPosition() const { return this->sprite.getPosition(); }
    int getDamage() const;
    inline FloatRect getGlobalBounds() const { return this->sprite.getGlobalBounds(); }
    inline const int& getHp() const { return this->hp; }
    inline const int& getHpMax() const { return this->hpMax; }
    void takeDamage(int damage);
    inline bool isAlive() const { return this->hp > 0; }
    inline void gainScore(int score) { this->score += score; }
    inline const int getScore() { return this->score; }
    inline bool isDamagedCooldown() { return this->damageTimer < this->damageTimerMax; }
    inline void enableMissile() { this->currentWeapon = 1; }
    inline void disableMissile() { this->currentWeapon = 0; }
    inline void enableLaser() { this->currentWeapon = 2; }
    inline void disableLaser() { this->currentWeapon = 0; }
    inline void enablePiercingShot() { this->piercingShot = true; }
    inline void disablePiercingShot() { this->piercingShot = false; }
    inline bool getPiercingShot() const { return this->piercingShot; }
    inline const Vector2f& getNormDir()const { return this->normDir; }
    inline void move(float x, float y) { this->sprite.move(x, y);}
    inline const Vector2f& getCurrentVelocity() {return this->currentVelocity; }
    inline void setGravity() { this->sprite.move(0.f, gravitySpeed); }
    inline void setMissileAmmo() { this->missileAmmo = 10; }
    inline void setLaserAmmo() { this->laserAmmo = 5; }



    //Funzioni 
    void Reset();
    void Draw(RenderTarget &target);
    void Update(Vector2u windowBounds, const float &dt);
    void Movement(Vector2u windowBounds,const float &dt);
    void CheckMapCollision(const float &dt, Vector2f platformPosition, FloatRect platformBounds);
    void Combat(const float &dt);
    void CheckAmmo();

    //Funzioni Achievements
    virtual void Notify()const;
    virtual void Attach(Observer*o)override;
    virtual void Detach(Observer*o)override;
    void Changed() { Notify(); };
    void SetKillSoldier();
    void SetKillUfo();
    void SetPoints(int pnts);


    FloatRect playerBounds;

    //Membri statici
    static unsigned players;

    //Funzioni regolari
    float vectorLength(Vector2f v)
    {
        return sqrt(pow(v.x, 2) + pow(v.y, 2));
    }

    Vector2f normalize(Vector2f v, float length)
    {
        if (length == 0)
            return Vector2f(0.f, 0.f);
        else
            return v / length;
    }


private:

    //Membri riguardanti player.
    Sprite sprite;
    RectangleShape hitBox;
    Vector2f playerCenter;
    Vector2f direction;
    Vector2f currentVelocity;

    bool faceRight;

    //Pickups
    bool piercingShot;


    float maxVelocity;
    float acceleration;
    int speed;
    float stabilizerForce;
    Vector2f movementDirection;
    Vector2f normDir;

    unsigned playerNr;

    //Puntatori a texture per i diversi tipi di bullet.
    Texture *bulletTexture;
    Texture *missileTexture;
    Texture *laserTexture;
    dArr<Bullet> bullets;


    //Observer 
    std::list<Observer*>observer;
    int killSoldier;
    int killUfo;
    int points;

    //Attributi mappa
    const float ground = 600.0f;
    float gravitySpeed = 10.0;
    const float LeftScreenBounds = 0.f;
    const float RightScreenBounds = 15000.f;


    //Timing riguardante il rate dei bullets.
    float shootTimer;
    float shootTimerMax;
    float damageTimer;
    float damageTimerMax;
    int missileAmmo;
    int laserAmmo;

    float jumpTimer;
    float jumpTimerMax;


    //UI interface 
    int score;
    int hp;
    int hpMax;
    int damage;

    //Membro che indica l'arma corrente.
    int currentWeapon;

};

#endif //MEMESLUG_PLAYER_H
