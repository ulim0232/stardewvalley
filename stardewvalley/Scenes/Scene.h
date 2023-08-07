#pragma once

class GameObject;
class Scene
{
protected:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	SceneId sceneId;

	vector<tuple<ResourceTypes, string>> resources;
	list<GameObject*> gameObjects; 
	//�ߺ��� ���� �ʵ��� ���� -> �Լ��� ���ؼ� �ְ� ����

public:
	Scene(SceneId id = SceneId::None);
	virtual ~Scene();

	//���� �����ϰ� ������ �� ȣ���� �Լ�
	//��� ���� ������ ���� �ϱ�� ����
	virtual void Init() = 0;
	virtual void Release() {};

	//���� ����ϰ� ������ �� ȣ���� �Լ�
	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	GameObject* FindGo(const string& name); 
	//�̸��� �ߺ��Ǹ� ���� ó���� �� ����

	void FindGo(list<GameObject*>& list, const string& name);
	//�̸��� �ش��ϴ� ��� ���ӿ�����Ʈ�� ����Ʈ�� ���

	bool Exist(GameObject* go);
	void AddGo(GameObject* go);
	void RemoveGo(GameObject* go);
	void SortGos(); //����
};

