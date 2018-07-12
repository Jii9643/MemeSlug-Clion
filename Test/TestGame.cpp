//
// Created by jii on 11/07/18.
//

#include "gtest/gtest.h"
#include "../Player.h"
#include "../Enemy.h"
#include "../Platform.h"
#include "../Game.h"

TEST(Game, Test_Game)
{
    dArr<Texture> testBodyTextures;
    testBodyTextures.add(Texture());
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
    testBodyTextures[1].loadFromFile("Textures/Platform.png");
    testsprite2.setTexture((testBodyTextures[1]));

    StrategyMove* move = nullptr;

    Enemy testEnemy(testBodyTextures, testBulletTextures,Vector2u(1000,1000), Vector2f(1000.f,600.f),
                    Vector2f(-1.f, 0.f), Vector2f(1.3f, 1.3f), 0, 2, 5, 5, 0, move);
    testEnemy.sprite = testsprite1;

    Player testPlayer(testTextures, 0, 0, 0);
    testPlayer.sprite = testsprite;
    testPlayer.setPosition(400.f, 400.f);

    Platform testPlatform(testBodyTextures,Vector2f(400.f,400.f), Vector2f(0.2f,0.2f), Vector2u(1000,1000),1);
    testPlatform.block = testsprite2;

    testPlatform.block.setPosition(400.f,400.f);

    ASSERT_EQ( 1, testPlatform.getType());
    ASSERT_TRUE(testPlatform.getPosition().x < 1000);

 //   std::cout<<"\n"<<testPlatform.block.getGlobalBounds().width;

    if (testPlatform.block.getGlobalBounds().intersects(testPlayer.sprite.getGlobalBounds()))
    {
        testPlayer.sprite.setPosition(testPlayer.sprite.getPosition().x, testPlatform.block.getPosition().y - 140);
        ASSERT_EQ(260, testPlayer.sprite.getPosition().y);
    }

    testEnemy.sprite.setPosition(400.f,400.f);

    if (testPlatform.block.getGlobalBounds().intersects(testEnemy.sprite.getGlobalBounds()))
    {
        testEnemy.sprite.setPosition(testEnemy.sprite.getPosition().x, testPlatform.block.getPosition().y - 30);
        ASSERT_EQ(370, testEnemy.sprite.getPosition().y);
    }


}
