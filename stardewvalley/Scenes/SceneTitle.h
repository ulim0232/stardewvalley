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

	//씬을 재생하고 종료할 때 호출할 함수
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

