#pragma once
#include "Singleton.h"

//������ ���� �̵� ����

class Scene;

class SceneMgr : public Singleton<SceneMgr>
{
	friend Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	virtual ~SceneMgr() override = default;

	std::vector<Scene*> scenes; //������ ������ ���� �����̳�
	SceneId currentSceneId = SceneId::None; //���� ��Id ����
	SceneId startSceneId = SceneId::Title; //���� ó���� ����� ���� Id

	Scene* currentScene = nullptr;

	//����� ���ÿ� �ʱ�ȭ�� ���, ��� �̴ϼȶ������� ���ؼ��� �ʱ�ȭ �Ѵٸ� ��� �̴ϼȶ������� �ʱ�ȭ�ȴ�.
public:

	void ChangeScene(SceneId id); //���� �����ϴ� �Լ�

	void Init();
	void Release();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())

