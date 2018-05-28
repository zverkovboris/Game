#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <fstream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::OnKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::OnKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    Time = 0;
    Timer = 0;
    std::ifstream fin("position.txt");
    size_t size;
    fin >> size;
    fin.get();
    for (size_t i = 0; i < size; ++i)
    {
        size_t x1, y1, x2, y2;
        fin >> x1;
        fin.get();
        fin >> y1;
        fin.get();
        fin >> x2;
        fin.get();
        fin >> y2;
        fin.get();
        labirint.push_back(std::make_shared<Labirint>(x1, y1, x2, y2));
        this->addChild(labirint.back()->Node());
    }

    Pack = std::make_shared<Player>("packman.png", labirint);
    this->addChild(Pack->Sprite());
    GameOver = cocos2d::Label::createWithTTF("GameOver", "fonts/Arial.ttf", 100);
    GameOver->setAnchorPoint(cocos2d::Vec2(0, 0));
    GameOver->setPosition(cocos2d::Vec2(200, 400));
    GameOver->setColor(cocos2d::Color3B::RED);
    GameOver->setVisible(false);
    this->addChild(GameOver);
    Score = 20;
    Sc = cocos2d::Label::createWithTTF(std::to_string(Score), "fonts/Arial.ttf", 50);
    Sc->setAnchorPoint(cocos2d::Vec2(0, 0));
    Sc->setPosition(cocos2d::Vec2(150, 60));
    this->addChild(Sc);

    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
    if (GameOver->isVisible())
    {
        return;
    }
    if (Time >= Timer)
    {
        AddEnemies();
        Time -= Timer;
        Timer = rand() % 10 + 1;
    }
    Time += delta;
    Pack->Update(delta);
    std::vector<size_t> Places;
    for (size_t i = 0; i < Patr.size(); ++i)
    {
        if (Patr[i]->Update())
            Places.push_back(i);
    }
    Delete<Shooting>(Patr, Places);
    for (size_t i = 0; i < EnemyPatr.size(); ++i)
    {
        if (GameObject::Collision(Pack->Sprite(), EnemyPatr[i]->Sprite()))
        {
            End();
            return;
        }
        else 
            if (EnemyPatr[i]->Update())
            Places.push_back(i);
            else
            {
                for (size_t j = 0; j < Patr.size(); ++j)
                {
                    if (GameObject::Collision(EnemyPatr[i]->Sprite(), Patr[j]->Sprite()))
                    {
                        Places.push_back(i);
                        this->removeChild(Patr[j]->Sprite());
                        Patr.erase(Patr.begin() + j);
                    }
                }
            }
    }
    Delete<Shooting>(EnemyPatr, Places);
    for (size_t j = 0; j < En.size(); ++j)
    {
        int size = Patr.size();
        int h = 0;
        if (GameObject::Collision(En[j]->Sprite(), Pack->Sprite()))
        {
            End();
            return;
        }
        for (int i = 0; i < size; ++i)
        {
            if (GameObject::Collision(Patr[i - h]->Sprite(), En[j]->Sprite()))
            {
                this->removeChild(Patr[i - h]->Sprite());
                Patr.erase(Patr.begin() + i - h);
                --size;
                ++h;
                --En[j]->GetLifes();
            }
        }
        if (En[j]->GetLifes() <= 0)
        {
            Score += 5;
            Places.push_back(j);
        }
        if (En[j]->Reached())
        {
            En[j]->ChangeGoal(Pack->Sprite()->getPosition());
        }
        cocos2d::Vec2 pos = En[j]->Sprite()->getPosition();
        En[j]->Update(delta);
        if (En[j]->Kill())
        {
            AddEn(En[j]->Sprite());
        }
        En[j]->ChangeMove(pos);
    }
    Delete<EnemyGeneral>(En, Places);
    ChangeScore();
}

void HelloWorld::OnKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    Pack->RemoveUserAction(key);
    return;
}

void HelloWorld::OnKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    if (key == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
    {
        GameOver->setVisible(false);
        Score = 20;
        Pack = std::make_shared<Player>("packman.png", labirint);
        this->addChild(Pack->Sprite());
    }
    else if (key == cocos2d::EventKeyboard::KeyCode::KEY_SPACE && !GameOver->isVisible())
    {
        --Score;
        Patr.push_back(std::make_shared<Shooting>("packman.png", labirint, Pack->Sprite()->getPosition(), Pack->Keyboard()));
        this->addChild(Patr.back()->Sprite());
    }
    else if (!GameOver->isVisible())
    {
        Pack->AddUserAction(key);
    }
}

void HelloWorld::AddEnemies()
{
    En.push_back(std::make_shared<EnemyGeneral>("packman.png", labirint, Pack->Sprite()->getPosition()));
    CheckCollision();
    En.push_back(std::make_shared<Enemy2>("packman.png", labirint, Pack->Sprite()->getPosition()));
    CheckCollision();
    En.push_back(std::make_shared<Enemy3>("packman.png", labirint, Pack->Sprite()->getPosition()));
    CheckCollision();
    En.push_back(std::make_shared<Enemy4>("packman.png", labirint, Pack->Sprite()->getPosition()));
    CheckCollision();
}

void HelloWorld::ChangeScore()
{
    Sc->setString(std::to_string(Score));
    if (Score < 0)
    {
        End();
    }
}
void HelloWorld::AddEn(cocos2d::Sprite * sprite)
{
    EnemyPatr.push_back(std::make_shared<Shooting>("packman.png", labirint, sprite->getPosition()));
    EnemyPatr.back()->Sprite()->setColor(cocos2d::Color3B::GREEN);
    this->addChild(EnemyPatr.back()->Sprite());
}

void HelloWorld::End()
{
    this->removeChild(Pack->Sprite());
    for (const auto& s : Patr)
    {
        this->removeChild(s->Sprite());
    }
    Patr.clear();
    for (const auto& s : En)
    {
        this->removeChild(s->Sprite());
    }
    En.clear();
    for (const auto& s : EnemyPatr)
    {
        this->removeChild(s->Sprite());
    }
    EnemyPatr.clear();
    GameOver->setVisible(true);
}

void HelloWorld::CheckCollision()
{
    if (GameObject::Collision(En.back()->Sprite(), Pack->Sprite()))
        En.erase(En.end() - 1);
    else
        this->addChild(En.back()->Sprite());
}
template <typename T>
void HelloWorld::Delete(std::vector<std::shared_ptr<T>>& vec, std::vector<size_t>& pos)
{
    size_t i = 0;
    for (size_t j = 0; j < pos.size(); ++j, ++i)
    {
        this->removeChild(vec[pos[j] - i]->Sprite());
        vec.erase(vec.begin() + pos[j] - i);
    }
    pos.clear();
}
