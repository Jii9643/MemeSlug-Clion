//
// Created by jii on 10/07/18.
//

#include "gtest/gtest.h"
#include "../Enemy.h"
#include "../Player.h"
#include "../Game.h"
#include "../Bullet.h"


using namespace sf;

TEST(Enemy, Test_Enemy_InitialValues)
{
    dArr<Texture> testBodyTextures;
    testBodyTextures.add(Texture());
    dArr<Texture> testBulletTextures;
    testBulletTextures.add(Texture());
    std::vector<Texture> testTextures;
    testTextures.push_back (Texture());
    Sprite testsprite;
    testTextures[0].loadFromFile("Textures/TarmaPlayer.png");
    testsprite.setTexture(testTextures[0]);

    Sprite testsprite1;
    testBodyTextures[0].loadFromFile("Textures/SimpleSoldier.png");
    testsprite1.setTexture((testBodyTextures[0]));


    Sprite testsprite2;
    testBodyTextures[0].loadFromFile("Textures/Laser.png");
    testsprite1.setTexture((testBodyTextures[0]));



    StrategyMove* move = nullptr;

    Enemy testEnemy(testBodyTextures, testBulletTextures,Vector2u(1000,1000), Vector2f(1000.f,600.f),
    Vector2f(-1.f, 0.f), Vector2f(1.3f, 1.3f), 0, 2, 3, 1, 0, move);
    testEnemy.sprite = testsprite1;


    Player testPlayer(testTextures, 0, 0, 0);
    testPlayer.setPosition (1000.f, 600.f);
    testPlayer.sprite = testsprite;


    ASSERT_EQ (0, testEnemy.getType ());
    ASSERT_EQ (2, testEnemy.getHPMax ());
    ASSERT_FALSE ( testEnemy.isDead ());
    ASSERT_EQ (1, testEnemy.getDamage ());


    // std::cout<<"\n"<<testEnemy.sprite.getGlobalBounds().height;

    if(testEnemy.sprite.getGlobalBounds().intersects(testPlayer.sprite.getGlobalBounds()))
    {
        testEnemy.takeDamage (testPlayer.getDamage ());
        if (testEnemy.getHP () <= 0)
        {
            ASSERT_TRUE (testEnemy.isDead ());
        }
    }


    testPlayer.enableLaser();

    if(testEnemy.sprite.getGlobalBounds().intersects(testPlayer.sprite.getGlobalBounds()))
    {
        testEnemy.takeDamage (testPlayer.getDamage ());
        if (testEnemy.getHP () <= 0)
        {
            ASSERT_TRUE (testEnemy.isDead ());
        }

        ASSERT_TRUE(testPlayer.checkPiercingShot());
    }

    testEnemy.sprite.setPosition(1500, 600);
    testPlayer.sprite.setPosition(0, 600);

    if(testEnemy.sprite.getPosition().x > testPlayer.sprite.getPosition().x)
    {
        move = new StrategyL(0.5f,0.0f);
        testEnemy.sprite.move(move->StrategyEnemy());
        ASSERT_TRUE(testEnemy.sprite.getPosition().x < 1500);
        delete move;
    }
    else if (testEnemy.sprite.getPosition().x < testPlayer.sprite.getPosition().x)
    {
        move = new StrategyR(0.5f,0.0f);
        testEnemy.sprite.move(move->StrategyEnemy());
        ASSERT_TRUE(testEnemy.sprite.getPosition().x > 1500);
        delete move;
    }



}

