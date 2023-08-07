#pragma once
#include "GameObject.h"
#include "AnimationController.h"
class Farmer : public GameObject
{
protected:
	AnimationController bodyAnimation;
	AnimationController shirtAnimation; 
	AnimationController armAnimation;
	AnimationController heirAnimation;
	AnimationController pentsAnimation;
	

public:
	sf::Sprite body;
	sf::Sprite shirt;
	sf::Sprite arm;
	sf::Sprite heir;
	sf::Sprite pents;

	Farmer(const std::string name = "");
	virtual void Init() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Release() override;

	virtual void SetPosition(const sf::Vector2f& position);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);
};

