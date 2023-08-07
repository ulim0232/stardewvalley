#pragma once
#include "SpriteGo.h"
class UiButton : public SpriteGo
{
protected:
	bool isHover = false;

public:
	sf::Text text;

	UiButton(const std::string& textureId, const std::string& n);
	virtual ~UiButton() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;


	function<void()> OnClick;
	function<void()> OnEnter; //Ŀ���� ������ ���� ��
	function<void()> OnExit; //�������� ������

};

