//
// Created by jii on 10/07/18.
//

#include "gtest/gtest.h"
#include "../Player.h"
#include "../Game.h"
#include "../Enemy.h"
#include "../Map.h"
#include "../dArr.h"

TEST(Player, Test_Player)
{
    std::vector<Texture> testTextures;
    testTextures.push_back(Texture());
    testTextures.push_back(Texture());
    dArr<Texture> testTextures1;

    RenderWindow * window;

    Player testPlayer(testTextures,0,0,0);
    Game game(window);
    Map(testTextures1, Vector2f(300.f, 200.f), Vector2f(0.1f, 0.1f), Vector2u(1000, 1000), 0);


    float initialPositionX = 300.f;

    ASSERT_EQ(testPlayer.getPositionX(), initialPositionX);
}