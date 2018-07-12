//
// Created by jii on 10/07/18.
//

#include "gtest/gtest.h"
#include "../Player.h"
#include "../Enemy.h"



TEST(Player, Test_Player_InitialValues)
{
    std::vector<Texture> testTextures;
    testTextures.push_back (Texture());


    Player testPlayer(testTextures, 0, 0, 0);

    float initialPositionX = 300.f;
    float initialPositionY = 200.f;
    float initialScore = 0.f;
    float initialVelocity = 0.f;
    int   initialHp = 50;
    bool  currentWeaponBullet = true;


    ASSERT_EQ (testPlayer.getPositionX (), initialPositionX);
    ASSERT_EQ (testPlayer.getPosition().y, initialPositionY);
    ASSERT_EQ (testPlayer.getScore (), initialScore);
    ASSERT_EQ (testPlayer.getHp (), initialHp);
    ASSERT_EQ (testPlayer.getCurrentVelocity ().x, initialVelocity);
   // ASSERT_TRUE (testPlayer.checkBullet () == currentWeaponBullet);


}

TEST(Player, Test_Player_Ach)
{
    std::vector<Texture> testTextures;
    testTextures.push_back (Texture());


    Player testPlayer(testTextures, 0, 0, 0);

    ASSERT_EQ (1, testPlayer.SetKillUfo ());
    ASSERT_EQ (1, testPlayer.SetKillSoldier ());

}

TEST(Player, Test_Player_Position)
{
    std::vector<Texture> testTextures;
    testTextures.push_back (Texture());
    Sprite testsprite;
    testTextures[0].loadFromFile("Textures/TarmaPlayer.png");
    testsprite.setTexture(testTextures[0]);



    Player testPlayer(testTextures, 0, 0, 0);
    testPlayer.setPosition (0.f, 600.f);
    testPlayer.sprite = testsprite;
    testPlayer.sprite.move(-20.f,0.0f);

    if (testPlayer.getPosition().x <= -300.f)
    {

        ASSERT_EQ (0.f, testPlayer.getCurrentVelocity ().x);
    }

}

TEST(Player, Test_Collision)
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

    StrategyMove* move = nullptr;

    Enemy testEnemy(testBodyTextures, testBulletTextures,Vector2u(1000,1000), Vector2f(1000.f,600.f),
                    Vector2f(-1.f, 0.f), Vector2f(1.3f, 1.3f), 0, 2, 5, 5, 0, move);
    testEnemy.sprite = testsprite1;


    Player testPlayer(testTextures, 0, 0, 0);
    testPlayer.setPosition (1000.f, 600.f);
    testPlayer.sprite = testsprite;
    testPlayer.setHp(4);

    if(testPlayer.sprite.getGlobalBounds().intersects(testEnemy.sprite.getGlobalBounds()))
    {
        testPlayer.takeDamage (testEnemy.getDamage ());
        if (testPlayer.getHp () <= 0)
        {
            ASSERT_TRUE(testPlayer.chechGameOver());
        }
    }

}
