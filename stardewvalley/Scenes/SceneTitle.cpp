#include "stdafx.h"
#include "SceneTitle.h"
#include "InputMgr.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "Framework.h"

SceneTitle::SceneTitle() : Scene(SceneId::Title)
{
	//resources.push_back(make_tuple(ResourceTypes::Texture, "graphics/bee.png"));
	resources.push_back(make_tuple(ResourceTypes::Font, "fonts/KOMIKAP_.ttf "));
	resources.push_back(make_tuple(ResourceTypes::Texture, "graphics/cloud.png"));
}

void SceneTitle::Init()
{
	Release();
	AddGo(new SpriteGo("cloud"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneTitle::Release()
{
	//Scene::Release();
	for (auto go : gameObjects)
	{
		//go->Release(); 소멸자에서 호출
		delete go;
	}
}

void SceneTitle::Enter()
{
	Scene::Enter();

	SpriteGo* findGo = (SpriteGo*)FindGo("cloud");
	findGo->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/cloud.png")); 
	//리소스, 경로를 Id로 사용함

	sf::Vector2f centerPos = FRAMEWORK.GetWindowSize(); //윈도우의 크기
	centerPos.x *= 0.5f;
	centerPos.y *= 0.5f;
	findGo->SetPosition(centerPos);

	findGo->SetOrigin(Origins::MC);
	findGo->sortOrder = 1;
}

void SceneTitle::Exit()
{
	Scene::Exit();
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Game);
	}
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
