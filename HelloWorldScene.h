#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameObject.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Player.h"
#include "Labirint.h"
#include "Shoot.h"
#include <vector>
#include <memory>

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    bool init() override;
    void update(float delta) override;
    
    // a selector callback
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    cocos2d::Label * GameOver;
    int Score;
    cocos2d::Label * Sc;
    void ChangeScore();
    float Time;
    int Timer;
    std::vector<std::shared_ptr<EnemyGeneral>> En;
    std::shared_ptr<Player> Pack;
    std::vector<std::shared_ptr<Labirint>> labirint;
    std::vector<std::shared_ptr<Shooting>> Patr;
    std::vector<std::shared_ptr<Shooting>> EnemyPatr;
    void OnKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    void AddEnemies();
    void End();
    void CheckCollision();
    void AddEn(cocos2d::Sprite * sprite);
    void OnKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    template <typename T>
    void Delete(std::vector<std::shared_ptr<T>>& vec, std::vector<size_t>& pos);
};

#endif // __HELLOWORLD_SCENE_H__
