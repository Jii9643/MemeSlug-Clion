//
// Created by jii on 03/07/18.
//

#include "Game.h"

enum textures { player = 0, bullet1, missile, laser };

Game::Game(RenderWindow *window)

{
    this->InitTextures();

    //Inizializzazione del gioco
    this->window = window;
    this->window->setFramerateLimit(10000000);
    this->dtMultiplier = 60.0f;
    this->runGame = true;
    this->scoreMultiplier = 1;
    this->score = 0;
    this->scoreTimer.restart();
    this->scoreTime = 0;
    this->multiplierAdderMax = 10;
    this->multiplierAdder = 0;
    this->multiplierTimerMax = 400.f;
    this->multiplierTimer = this->multiplierTimerMax;
    this->paused = true;
    this->endGame = false;
    this->bossIsAlive = false;


    //Inizializzazione dei fonts (UI ancora da implementare)
    this->font.loadFromFile("Fonts/Flighter_PERSONAL_USE_ONLY.ttf");
    this->font1.loadFromFile("Fonts/Fipps-Regular.otf");

    //Creazione del player
    this->players.add(Player(this->textures, 0, 0 ,0));


    //Associazione degli achievements al player
    this->achievements.push_back(Achievements(&players[0]));


    this->enemiesAlive = 0;
    this->enemySpawnTimerMax = 300;
    this->enemySpawnTimer = this->enemySpawnTimerMax;



    this->soldierKilled = 0;
    this->ufoKilled = 0;
    this->AchievementTimerMax = 30000;
    this->AchievementTimer = 0;


    //Creazione mappa
    this->CreateMap();
    this->InitUI();
    this->InitMap();
}


Game::~Game()
{

}

void Game::initView()
{
    this->mainView.setSize(Vector2f(1280.f,720.f));
    this->mainView.setCenter(Vector2f(this->window->getSize().x,
                                      this->window->getSize().y ));
}

void Game::InitTextures()
{
    //Inizializzazione delle textures
    this->textures.push_back(Texture());
    this->textures[player].loadFromFile("Textures/TarmaPlayer.png");
    this->textures.push_back(Texture());
    this->textures[bullet1].loadFromFile("Textures/bullet1.png");
    this->textures.push_back(Texture());
    this->textures[missile].loadFromFile("Textures/missile.png");
    this->textures.push_back(Texture());
    this->textures[laser].loadFromFile("Textures/Laser.png");


    Texture temp;

    //Nemici
    temp.loadFromFile("Textures/SimpleSoldier.png");
    this->enemyTextures.add(Texture(temp));
    temp.loadFromFile("Textures/Ufo.png");
    this->enemyTextures.add(Texture(temp));
    temp.loadFromFile("Textures/soldierMSL.png");
    this->enemyTextures.add(Texture(temp));
    temp.loadFromFile("Textures/Boss.png");
    this->enemyTextures.add(Texture(temp));

    //Proiettili dei nemici
    temp.loadFromFile("Textures/eBullet.png");
    this->enemyBulletTextures.add(Texture(temp));
    temp.loadFromFile("Textures/BossBullet.png");
    this->enemyBulletTextures.add(Texture(temp));

    //Pickups
    temp.loadFromFile("Textures/Box.png");
    this->pickupTextures.add(Texture(temp));
    temp.loadFromFile("Textures/Box1.png");
    this->pickupTextures.add(Texture(temp));

    //Mappa
    temp.loadFromFile("Textures/GrassMap.png");
    this->mapTextures.add(Texture(temp));
    temp.loadFromFile("Textures/Platform.png");
    this->mapTextures.add(Texture(temp));

    this->EndTexture.loadFromFile("Textures/Sign.png");
    this->EndSprite.setTexture(EndTexture);
    this->EndSprite.setPosition(12600.f, 580.f);
    this->EndSprite.setScale(-1.5f, 1.5f);

}

void Game:: InitUI()
{

    for (size_t i = 0; i < this->players.size(); i++)
    {

        this->staticPlayerText.setFont(font);
        this->staticPlayerText.setCharacterSize(12);
        this->staticPlayerText.setColor(Color::White);
        this->staticPlayerText.setString("");


    }
    //Game Over
    this->gameOverText.setFont(this->font);
    this->gameOverText.setColor(Color(153,0,0,255));
    this->gameOverText.setCharacterSize(40);
    this->gameOverText.setString(
            std::string("YOU DIED!"));
    this->gameOverText.setPosition(this->window->getSize().x / 2 , this->window->getSize().y / 2 );

    //End Game
    this->endGameText.setFont(this->font1);
    this->endGameText.setColor(Color::Green);
    this->endGameText.setCharacterSize(60);
    this->endGameText.setString(
            std::string("YOU WON!"));
    this->endGameText.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);


    //Score
    this->scoreText.setFont(this->font1);
    this->scoreText.setColor(Color(200, 200, 200, 150));
    this->scoreText.setCharacterSize(25);
    this->scoreText.setString("Score : 0");
    this->scoreText.setPosition(20.f, 20.f);

    //Men�/Pausa
    this->controlsText.setFont(this->font);
    this->controlsText.setColor(Color::White);
    this->controlsText.setCharacterSize(25);
    this->controlsText.setString(
            "A: SHOOT\nRIGHT ARROW: RIGHT\nLEFT ARROW: LEFT \nUP ARROW: JUMP \nP: PAUSE/CONTROLS (START GAME)\nESC: QUIT\nWARNING, SCORE-TIMER DOES NOT STOP WHEN PAUSED!"
    );
    this->controlsText.setPosition(50.f, 400.f);

    //Achievements

    //Achievement per aver ucciso i soldati
    this->killSoldierText.setFont(this->font1);
    this->killSoldierText.setColor(Color(220, 110, 24, 255));
    this->killSoldierText.setCharacterSize(20);
    this->killSoldierText.setString("");
    this->killSoldierText.setPosition(1500.f, 20.f);

    //Achievement per aver ucciso gli ufo
    this->killUfoText.setFont(this->font1);
    this->killUfoText.setColor(Color(220, 110, 24, 255));
    this->killUfoText.setCharacterSize(20);
    this->killUfoText.setString("");
    this->killUfoText.setPosition(1500.f, 20.f);

    //Achievement per lo score
    this->pointsText.setFont(this->font1);
    this->pointsText.setColor(Color(220, 110, 24,255));
    this->pointsText.setCharacterSize(20);
    this->pointsText.setString("");
    this->pointsText.setPosition(1500.f, 40.f);

}

void Game::InitMap()
{



    //Background
    if (!backgroundTexture.loadFromFile("Textures/Background.png"))
    { }
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setScale(4.5f, 4.5f);
    this->backgroundSprite.setPosition(-600.f, -50.f);
    this->backgroundSprite.setColor(Color(255, 255, 255, 150));


    if (!backgroundTexture1.loadFromFile("Textures/Background1.png"))
    { }
    this->backgroundSprite1.setTexture(this->backgroundTexture);
    this->backgroundSprite1.setScale(-4.5f, 4.5f);
    this->backgroundSprite1.setPosition(8615.f, -50.f);
    this->backgroundSprite1.setColor(Color(255, 255, 255, 150));

    if (!backgroundTexture1.loadFromFile("Textures/Background2.png"))
    {
    }
    this->backgroundSprite2.setTexture(this->backgroundTexture);
    this->backgroundSprite2.setScale(4.5f, 4.5f);
    this->backgroundSprite2.setPosition(8615.f, -50.f);
    this->backgroundSprite2.setColor(Color(255, 255, 255, 150));
}

void Game:: UpdateUI()
{
    //STATIC TEXT
}

void Game::DrawUI()
{
    //STATIC TEXT

    if (this->runGame == false)
    {
        this->window->draw(this->gameOverText);
    }

    if (this->endGame == true)
    {
        this->window->draw(this->endGameText);
    }

    //Score
    this->window->draw(this->scoreText);


    //Men�
    if (this->paused)
        this->window->draw(this->controlsText);


    //Achievements
    if (this->soldierKilled == 3)
    {
        this->killSoldierText.setString(std::string("Morirete tutti!"));
        this->window->draw(this->killSoldierText);

        if (this->AchievementTimer < this->AchievementTimerMax)
        {
            this->AchievementTimer += 1.f*this->dtMultiplier;
        }
        else
        {
            this->killSoldierText.setColor(Color::Transparent);
        }
    }

    if (this->ufoKilled == 1)
    {
        this->killUfoText.setString(std::string("Giro sull'ottovolante"));
        this->window->draw(this->killUfoText);

        if (this->AchievementTimer < this->AchievementTimerMax)
        {
            this->AchievementTimer += 1.f*this->dtMultiplier;
        }
        else
        {
            this->killUfoText.setColor(Color::Transparent);
        }

    }

    if (this->score >= 20 && this->score <= 30)
    {
        this->pointsText.setString(std::string("Vacci piano"));
        this->window->draw(this->pointsText);

        if (this->AchievementTimer < this->AchievementTimerMax)
        {
            this->AchievementTimer += 1.f*this->dtMultiplier;
        }
        else
        {
            this->pointsText.setColor(Color::Transparent);
        }
    }


}


//Update del game, si occupa di aggiornare le posizioni di players e bullets.
void Game::Update(const float &dt)
{

    //Keytime update
    if (this->keyTime < this->keyTimeMax)
        this->keyTime += 1.f * dt * this->dtMultiplier;


    //Pausa
    if (Keyboard::isKeyPressed(Keyboard::P) && this->keyTime >= this->keyTimeMax)
    {
        if (this->paused)
            this->paused = false;
        else
            this->paused = true;

        this->keyTime = 0.f;
    }

    //Inizio Game
    if (this->players.size() > 0 && !this->paused)
    {


        //Update timers
        if (this->enemySpawnTimer < this->enemySpawnTimerMax)
            this->enemySpawnTimer += 1.f* dt * this->dtMultiplier;

        //Score timer e moltiplicatori di score.
        if (this->multiplierTimer > 0.f)
        {
            this->multiplierTimer -= 1.f* dt * this->dtMultiplier;

            if (this->multiplierTimer <= 0.f)
            {
                this->multiplierTimer = 0.f;
                this->multiplierAdder = 0;
                this->scoreMultiplier = 1;
            }

        }


        this->scoreMultiplier = this->multiplierAdder / this->multiplierAdderMax + 1;


        //Enemies spawn
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax && this->enemiesAlive <=15)
        {
            this->enemies.add(Enemy(this->enemyTextures, this->enemyBulletTextures,
                                    this->window->getSize(), Vector2f(this->players[0].getPosition().x + rand() % 800, rand() % 600),
                                    Vector2f(-1.f, 0.f), Vector2f(1.3f, 1.3f),
                                    0, 5, 3, 1, 0, move));
            this->enemiesAlive++;


            this->enemies.add(Enemy(this->enemyTextures, this->enemyBulletTextures,
                                    this->window->getSize(), Vector2f(this->players[0].getPosition().x + rand() % 800, rand() % 200),
                                    Vector2f(-1.f, 0.f), Vector2f(0.15f, 0.20f),
                                    1, 5, 3, 3, 0, move));
            this->enemiesAlive++;

            this->enemies.add(Enemy(this->enemyTextures, this->enemyBulletTextures,
                                    this->window->getSize(), Vector2f(this->players[0].getPosition().x + rand() % 800, rand () % 600),
                                    Vector2f(-1.f, 0.f), Vector2f(0.28f, 0.28f),
                                    2, 5, 3, 2, 0, move));
            this->enemiesAlive++;


            this->enemySpawnTimer = 0;

        }

        //Final Boss
        if (this->players[0].getPosition().x >= 10000 && this->bossIsAlive == false)
        {
            this->enemies.add(Enemy(this->enemyTextures, this->enemyBulletTextures,
                                    this->window->getSize(), Vector2f(12000, 580),
                                    Vector2f(-1.f, 0.f), Vector2f(0.88f, 0.88f),
                                    3, 50, 5, 5, 0, move));
            this->bossIsAlive = true;
        }

        for (size_t i = 0; i < players.size(); i++)
        {
            if (this->players[i].isAlive())
            {
                //Update player.
                this->players[i].Player::Update(this->window->getSize(), dt);

                if (this->players[i].getPosition().x >= 12500.f)
                {

                    this->endGame = true;
                    this->DrawUI();
                }

                //Collisione  del player con la mappa
                for (size_t p = 0; p < this->blocks.size(); p++)
                {
                    if (this->blocks[p].getType() == 1)
                    {
                        this->players[i].CheckMapCollision(dt, this->blocks[p].getPosition(), this->blocks[p].getGlobalBounds());
                    }
                }

                //Spostamento Mappa con player
                if (this->endGame == false)
                {
                    if (Keyboard::isKeyPressed(Keyboard::Left) && this->players[i].getPosition().x > this->LeftScreenBounds)
                    {
                        this->mainView.move(this->players[i].getCurrentVelocity().x * dt * this->dtMultiplier, 0.f);
                    }
                    else
                    {
                        this->mainView.move(0.f, 0.f);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Right) && this->players[i].getPosition().x < this->RightScreenBounds)
                    {
                        this->mainView.move(this->players[i].getCurrentVelocity().x * dt * this->dtMultiplier, 0.f);
                    }
                    else
                    {
                        this->mainView.move(0.f, 0.f);
                    }
                }
                else
                {
                    this->mainView.move(0.f, 0.f);
                    this->players[i].move(4.f, 0.f);
                    if (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::Right)))
                    {
                        this->mainView.move(0.f, 0.f);
                        this->players[i].move(4.f, 0.f);
                    }
                }



                //Update Bullets
                for (size_t k = 0; k < this->players[i].getBulletsSize(); k++)
                {
                    this->players[i].getBullet(k).Bullet::Update(dt);

                    //Collisione tra bullet e enemies.
                    for (size_t j = 0; j < this->enemies.size(); j++)
                    {
                        if (this->players[i].getBullet(k).getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()))
                        {
                            //Controllo del piercing shot.
                            if (!this->players[i].getPiercingShot())
                            {
                                this->players[i].removeBullet(k);
                            }
                            else
                            {
                                this->players[i].getBullet(k).setPosition(Vector2f(this->enemies[j].getPosition().x + this->enemies[j].getGlobalBounds().width + this->players[i].getBullet(k).getGlobalBounds().width / 2 + 1.f,
                                                                                   +this->players[i].getBullet(k).getPosition().y));
                            }

                            if (this->enemies[j].getHP() > 0)
                                this->enemies[j].takeDamage(this->players[i].getDamage());

                            //Morte del nemico.
                            if (this->enemies[j].getHP() <= 0)
                            {
                                //Aggiunta score & Reset del multiplier timer
                                this->multiplierTimer = this->multiplierTimerMax;
                                int score = this->enemies[j].getHPMax() * this->scoreMultiplier;
                                this->multiplierAdder++;
                                this->players[i].gainScore(score);

                                //Spawn del pickup
                                int dropChance = rand() % 10 + 1;

                                if (dropChance > 1)
                                {
                                    dropChance = rand() % 10 + 1;

                                    if (dropChance > 8)
                                    {
                                        this->pickups.add(Pickup(this->pickupTextures,
                                                                 Vector2f(this->enemies[j].getPosition().x, this->enemies[j].getPosition().y), Vector2f(0.3f, 0.3f),
                                                                 0, 800.f));
                                    }
                                    else if (dropChance > 5)
                                    {
                                        this->pickups.add(Pickup(this->pickupTextures,
                                                                 Vector2f(this->enemies[j].getPosition().x, this->enemies[j].getPosition().y), Vector2f(0.12f, 0.12f),
                                                                 1, 800.f));

                                    }
                                }

                                switch (enemies[j].getType())
                                {
                                    case 0:

                                        this->soldierKilled++;
                                        this->enemies.remove(j);
                                        this->enemiesAlive--;


                                        DrawUI();

                                        break;

                                    case 1:

                                        this->enemies.remove(j);
                                        this->ufoKilled++;
                                        this->enemiesAlive--;


                                        DrawUI();

                                        break;

                                    case 2:

                                        this->soldierKilled++;
                                        this->enemies.remove(j);
                                        this->enemiesAlive--;



                                        DrawUI();

                                        break;

                                    case 3:
                                        this->enemies.remove(j);
                                        this->enemiesAlive--;

                                    default:
                                        break;

                                }

                                this->players[i].SetKillSoldier();



                            }
                            return;

                        }
                    }

                    //Per cancellare i bullet dopo la size della window.
                    if (this->players[i].getBullet(k).getPosition().x >this->players[i].getPosition().x + this->window->getSize().x)
                    {
                        this->players[i].removeBullet(k);
                        return;
                    }
                }
            }
            else
            {

                this->runGame = false;
            }

            //Update score
            this->score = 0;
            this->score += players[i].getScore();
            this->scoreText.setString("Score : " + std::to_string(score) +
                                      "\nMultiplier : " + std::to_string(this->scoreMultiplier) +
                                      "\nMultiplier Timer : " + std::to_string((int)this->multiplierTimer) +
                                      "\nNew Multiplier : " + std::to_string(this->multiplierAdder) + " / " +
                                      std::to_string(this->multiplierAdderMax));

            DrawUI();



        }

        if (this->runGame == true)
        {
            //Update enemies.
            for (size_t i = 0; i < this->enemies.size(); i++)
            {

                this->enemies[i].Update(dt, this->players[this->enemies[i].getPlayerFollowNr()].getPosition());

                //Collisione enemy con platform
                for (size_t p = 0; p < this->blocks.size(); p++)
                {

                    if (this->blocks[p].getType() == 1)
                    {
                        this->enemies[i].CheckMapCollision(dt, this->blocks[p].getPosition(), this->blocks[p].getGlobalBounds());
                    }
                }

                //Update dei proiettili del nemico.
                for (size_t k = 0; k < this->enemies[i].getBullets().size(); k++)
                {
                    this->enemies[i].getBullets()[k].Update(dt);
                }
                //Gestione collisione tra player e enemies.
                for (size_t k = 0; k < this->players.size(); k++)
                {
                    if (this->players[k].isAlive())
                    {

                        if (this->players[k].getGlobalBounds().intersects(this->enemies[i].getGlobalBounds())
                            && !this->players[k].isDamagedCooldown())
                        {
                            this->players[k].takeDamage(this->enemies[i].getDamage());

                            return;
                        }
                        // Intersezione tra i proiettili del nemico e il player.
                        for (size_t t = 0; t < this->enemies[i].getBullets().size(); t++)
                        {
                            if (this->enemies[i].getBullets()[t].getGlobalBounds().intersects(this->players[k].getGlobalBounds())
                                && !this->players[k].isDamagedCooldown())
                            {
                                this->players[k].takeDamage(this->enemies[i].getDamage());
                                this->enemies[i].removeBullet(t);
                                return;
                            }
                            //Per cancellare i bullet dopo la size della window.
                            if (this->enemies[i].getBullets()[t].getPosition().x >this->enemies[i].getPosition().x + this->window->getSize().x)
                            {
                                this->enemies[i].removeBullet(k);
                                return;
                            }
                            if (this->enemies[i].getBullets()[t].getPosition().x <this->enemies[i].getPosition().x - this->window->getSize().x)
                            {
                                this->enemies[i].removeBullet(k);
                                return;
                            }
                        }
                    }
                }


                if (this->enemies[i].getPosition().x < this->players[0].getPosition().x - 1000)
                {
                    this->enemies.remove(i);
                    return;
                }
            }

            //Update pickups
            for (size_t i = 0; i < this->pickups.size(); i++)
            {
                this->pickups[i].Update(dt);

                for (size_t k = 0; k < this->players.size(); k++)
                {
                    if (this->pickups[i].checkCollision(this->players[k].getGlobalBounds()))
                    {

                        switch (this->pickups[i].getType())
                        {

                            case 0:
                                this->players[k].disablePiercingShot();
                                this->players[k].enableMissile();
                                this->players[k].setMissileAmmo();

                                break;

                            case 1:

                                this->players[k].enablePiercingShot();
                                this->players[k].enableLaser();
                                this->players[k].setLaserAmmo();

                                break;

                            default:
                                break;

                        }

                        this->pickups.remove(i);
                        return;
                    }
                }

                if (this->pickups[i].canDelete())
                {
                    this->pickups.remove(i);
                    break;
                }

            }

        }

        else
        {
            this->scoreTime = (int)this->scoreTimer.getElapsedTime().asSeconds();

            if (this->scoreTime == 0)
                this->scoreTime = 1;

            this->gameOverText.setString
                    (
                            std::string("GAME OVER\nScore: " +
                                        std::to_string(this->score) +
                                        "\n" + "\n Press F1 to RESTART")
                    );




            //Restart
            if (Keyboard::isKeyPressed(Keyboard::F1))
            {
                for (size_t i = 0; i < this->players.size(); i++)
                {
                    this->players[i].Reset();
                }

                this->runGame = true;
                this->endGame = false;
                this->score = 0;
                this->scoreMultiplier = 1;
                this->multiplierAdder = 0;
                this->scoreTime = 0;
                this->enemySpawnTimerMax = 200.f;
                this->enemiesAlive = 0;
                this->scoreTimer.restart();
                this->enemies.clear();
                this->pickups.clear();
                this->mainView.setCenter(players[0].getPosition().x + 200, players[0].getPosition().y - 83);
            }
            this->enemySpawnTimer = 0;
        }
    }
    this->UpdateUI();

}




//Disegnare a schermo players, boxes e bullets.
void Game::Draw(const float dt)
{

    this->window->clear();

    this->window->setView(this->mainView);

    this->window->draw(backgroundSprite);
    this->window->draw(backgroundSprite1);
    this->window->draw(backgroundSprite2);
    this->window->draw(EndSprite);

    //Draw players.
    for (size_t i = 0; i < this->players.size(); i++)
    {
        this->players[i].Player::Draw(*this->window);
    }

    //Draw enemies.
    for (size_t i = 0; i < this->enemies.size(); i++)
    {
        this->enemies[i].Draw(*this->window);
    }

    //Map
    for (size_t i = 0; i < this->blocks.size(); i++)
    {
        this->blocks[i].Draw(*this->window);
    }

    //Draw pickups.
    for (size_t i = 0; i < this->pickups.size(); i++)
    {
        this->pickups[i].Draw(*this->window);

    }

    this->window->setView(this->window->getDefaultView());


    this->DrawUI();
    this->window->display();

}


void Game::CreateMap()
{
    for (float i = 0.f; i < 270000.f; i +=150.f)
    {
        this->blocks.add(Platform(this->mapTextures, Vector2f(i-800, 850.f),
                             Vector2f(0.5f, 0.5f), this->window->getSize(), 0));
    }

    for (float j = 0; j < 270000; j += 1000 + rand()%3000)
    {
        this->blocks.add(Platform(this->mapTextures, Vector2f(j , 550.f),
                             Vector2f(0.5f, 0.35f), this->window->getSize(), 1));
    }

    for (float j = 0; j < 270000; j += 100 + rand() % 3000)
    {
        this->blocks.add(Platform(this->mapTextures, Vector2f(j, 150.f),
                             Vector2f(0.5f, 0.35f), this->window->getSize(), 1));
    }

}