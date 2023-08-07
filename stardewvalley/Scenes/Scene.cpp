#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"
#include "ResourceMgr.h"

Scene::Scene(SceneId id) : sceneId(id)
{
}

Scene::~Scene()
{
	Release();
}

//void Scene::Init()
//{
//	Release();
//
//	for (auto go : gameObjects)
//	{
//		go->Init();
//	}
//}
//
//void Scene::Release()
//{
//	for (auto go : gameObjects)
//	{
//		//go->Release(); GeamObjects�� �Ҹ��ڿ��� release �ϴ� ������ ����
//		delete go;
//	}
//	gameObjects.clear();
//}

void Scene::Enter()
{
	RESOURCE_MGR.Load(resources);
	//������ ������ �ʱ� ���·� ����
	for (auto go : gameObjects)
	{
		go->Reset();
	}
}

void Scene::Exit()
{
	RESOURCE_MGR.UnLoad(resources);
}

void Scene::Update(float dt)
{
	for (auto go : gameObjects)
	{
		if (go->GetActive()) //Ȱ��ȭ �� �� �� ������Ʈ
		{
			go->Update(dt);
		}
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	SortGos(); //draw ���� ���� �� �� �ϱ�
	for (auto go : gameObjects)
	{
		if (go->GetActive()) //Ȱ��ȭ �� �� �� ������Ʈ
		{
			go->Draw(window);
		}
	}
}

GameObject* Scene::FindGo(const string& name)
{
	auto compare = [name](GameObject* go) {return go->GetName() == name; };
	auto it = find_if(gameObjects.begin(), gameObjects.end(), compare);
	if (it == gameObjects.end())
		return nullptr;
	return *it;

	/*���� ���� ǥ������ ����� �� �� ��1
	for (auto go : gameObjects)
	{
		if (go->GetName() == name)
		{
			return go;
		}
	}
	return nullptr;*/
}

void Scene::FindGo(list<GameObject*>& list, const string& name)
{
	//list.clear(); //����Ʈ�� ������ ��� �� ����, ���ÿɼ�
	for (auto go : gameObjects)
	{
		if (go->GetName() == name)
		{
			list.push_back(go);
		}
	}
}

bool Scene::Exist(GameObject* go)
{
	return find(gameObjects.begin(), gameObjects.end(), go) != gameObjects.end();
}

void Scene::AddGo(GameObject* go)
{
	if (!Exist(go)) //�������� �ʴ� ��쿡�� �ֱ�
	{
		gameObjects.push_back(go);
	}
}

void Scene::RemoveGo(GameObject* go)
{
	gameObjects.remove(go); //remove�� go�� ������ �ƹ��ϵ� ���� ����
	//delete go; �ٱ����� �ϴ� ������ ����
}

void Scene::SortGos()
{
	gameObjects.sort([](GameObject* lhs, GameObject* rhs) {
		if (lhs->sortLayer != rhs->sortLayer)
			return lhs->sortLayer < rhs->sortLayer;
		return lhs->sortOrder< rhs->sortOrder; 
		});
	//����ǥ������ ����ؼ� ����
}
