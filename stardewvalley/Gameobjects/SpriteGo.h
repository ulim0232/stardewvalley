#pragma once
#include "GameObject.h"
class SpriteGo : public GameObject
{
protected:
	//sf::Sprite sprite; public으로 이동 in 수업버전
public:
	sf::Sprite sprite;

	SpriteGo(const string n = "");
	virtual ~SpriteGo() override;

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() override; //동적 할당(생성자)
	virtual void Release() override; //동적 할당 해제(소멸자)
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

