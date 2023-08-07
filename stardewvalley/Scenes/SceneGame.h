#pragma once
#include "Scene.h"
class SceneGame :public Scene
{
protected:
public:
	SceneGame();
	virtual ~SceneGame() override = default;
	virtual void Init() override;
	virtual void Release() override;

	//���� ����ϰ� ������ �� ȣ���� �Լ�
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

