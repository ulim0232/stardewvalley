#pragma once
#include "GameObject.h"
class RectangleGo :
    public GameObject
{
public:
	sf::RectangleShape rectangle;

	RectangleGo(sf::Vector2f& size, const string& n = "");
	virtual ~RectangleGo() override;

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() override; //���� �Ҵ�(������)
	virtual void Release() override; //���� �Ҵ� ����(�Ҹ���)
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

