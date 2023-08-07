#pragma once
#include "RectangleGo.h"
class Ground :public RectangleGo
{
protected:

public:
	Ground(sf::Vector2f& size, const string& n = "");
	virtual ~Ground() override;

	virtual void Init() override; //���� �Ҵ�(������)
	virtual void Reset() override;
	virtual void Update(float dt) override;
};

