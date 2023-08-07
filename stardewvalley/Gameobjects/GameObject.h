#pragma once
#include "Utils.h"

/*utils, gameobjects std::���� �ʿ�*/
class GameObject
{
protected:
	std::string name;
	sf::Vector2f position;
	bool isActive = true; //true�̸� Ȱ��ȭ�� GameObject
	Origins origin;

public:

	int sortLayer = 0;
	int sortOrder = 0;

	GameObject(const string n = "");
	virtual ~GameObject();

	bool GetActive() const;
	void SetActive(bool active);

	std::string GetName();
	virtual void SetName(const std::string& n);

	sf::Vector2f GetPosition();

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() = 0; //���� �Ҵ�(������)
	virtual void Release() {}; //���� �Ҵ� ����(�Ҹ���)

	virtual void Reset() = 0; //�ʱ�ȭ, �����Ҵ� ����X

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

