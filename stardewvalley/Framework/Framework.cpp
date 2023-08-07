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
	window.create(sf::VideoMode(width, height), title); //window ����

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
    Init(screenWidth, screenHeight, title); //�ʱ�ȭ

    clock.restart(); //init�� �ɸ� �ð� �ʱ�ȭ
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart(); //������� �ɸ� �ð� ����
        float dt = deltaTime.asSeconds();

        INPUT_MGR.Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            INPUT_MGR.Update(event);
        }

        Update(dt); //framework�� update ȣ��

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
