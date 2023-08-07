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
//		//go->Release(); GeamObjects의 소멸자에서 release 하는 것으로 변경
//		delete go;
//	}
//	gameObjects.clear();
//}

void Scene::Enter()
{
	RESOURCE_MGR.Load(resources);
	//시작할 때마다 초기 상태로 변경
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
		if (go->GetActive()) //활성화 된 것 만 업데이트
		{
			go->Update(dt);
		}
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	SortGos(); //draw 전에 정렬 한 번 하기
	for (auto go : gameObjects)
	{
		if (go->GetActive()) //활성화 된 것 만 업데이트
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

	/*위의 람다 표현식을 사용한 것 과 택1
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
	//list.clear(); //리스트에 기존에 담긴 것 삭제, 선택옵션
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
	if (!Exist(go)) //존재하지 않는 경우에만 넣기
	{
		gameObjects.push_back(go);
	}
}

void Scene::RemoveGo(GameObject* go)
{
	gameObjects.remove(go); //remove는 go가 없으면 아무일도 하지 않음
	//delete go; 바깥에서 하는 것으로 수정
}

void Scene::SortGos()
{
	gameObjects.sort([](GameObject* lhs, GameObject* rhs) {
		if (lhs->sortLayer != rhs->sortLayer)
			return lhs->sortLayer < rhs->sortLayer;
		return lhs->sortOrder< rhs->sortOrder; 
		});
	//람다표현식을 사용해서 정렬
}
