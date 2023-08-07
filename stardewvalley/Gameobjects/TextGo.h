#pragma once
#include "GameObject.h"
class TextGo :
    public GameObject
{
	
public:
	sf::Text text;
	std::string resourceId;
	TextGo(const string& n = "", const std::string& rId = "");
	virtual ~TextGo() override;

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);
	virtual void SetSize(float w, float h);

	virtual void Init() override; //���� �Ҵ�(������)
	virtual void Release() override; //���� �Ҵ� ����(�Ҹ���)
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	void SetString(const string& str);
	void SetText(const std::string& ss, const int& size, sf::Color color, Origins origin, int soltLayer, float x, float y);
	void SetText(const std::wstring& ss, const int& size, sf::Color color, Origins origin, int soltLayer, float x, float y);
};

