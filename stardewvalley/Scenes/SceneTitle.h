#pragma once
#include "Scene.h"
class SceneTitle :public Scene
{
protected:
public:
	SceneTitle();
	virtual ~SceneTitle() override = default;
	virtual void Init() override;
	virtual void Release() override;

	//���� ����ϰ� ������ �� ȣ���� �Լ�
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

