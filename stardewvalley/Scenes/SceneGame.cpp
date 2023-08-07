#include "stdafx.h"
#include "SceneGame.h"
#include "InputMgr.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"
#include "GameObject.h"

SceneGame::SceneGame() : Scene(SceneId::Game)
{
	Release();
	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneGame::Init()
{
	for (auto go : gameObjects)
	{
		//go->Release(); �Ҹ��ڿ��� ȣ��
		delete go;
	}
}

void SceneGame::Release()
{
	
}

void SceneGame::Enter()
{
	Scene::Enter();
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Title);
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
