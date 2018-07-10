//
// Created by jii on 10/07/18.
//

#include "gtest/gtest.h"
#include "../Player.h"

TEST(Player, Test_Player)
{
    std::vector<Texture> testTextures;
    testTextures.push_back(Texture());
    Player testPlayer(testTextures,0,0,0);
}