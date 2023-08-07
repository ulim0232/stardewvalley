#include "stdafx.h"
#include "Framework.h"
#include "InputMgr.h"
#include "SceneMgr.h"

Framework::Framework(int w, int h, const string& t)
    :screenWidth(w), screenHeight(h), title(t)
{

}

void Framework::Init(int width, int height, const string& title)
{
	window.create(sf::VideoMode(width, height), title); //window 생성

    SCENE_MGR.Init();
}

void Framework::Release()
{
    SCENE_MGR.Release();
}

void Framework::Update(float dt)
{
    SCENE_MGR.Update(dt);
}

void Framework::Draw()
{
    SCENE_MGR.Draw(window);
}

void Framework::Run()
{
    Init(screenWidth, screenHeight, title); //초기화

    clock.restart(); //init에 걸린 시간 초기화
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart(); //현재까지 걸린 시간 리턴
        float dt = deltaTime.asSeconds();

        INPUT_MGR.Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            INPUT_MGR.Update(event);
        }

        Update(dt); //framework의 update 호출

        window.clear();
        Draw();
        window.display();
    }
    Release();
}

sf::Vector2f Framework::GetWindowSize()
{
    return sf::Vector2f(screenWidth, screenHeight);
}
