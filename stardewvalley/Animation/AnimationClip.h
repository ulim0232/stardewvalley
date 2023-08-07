#pragma once

enum class AnimationLoopTypes
{
	Single,
	Loop,
};

struct AnimationFrame
{
	std::string textureId;
	sf::IntRect texCoord;
	std::function<void()> action;// = nullptr; //Ư���� �������� ������ �� ȣ���� �Լ�
};

struct AnimationClip
{
	std::string id; //�ִϸ��̼� Ŭ���� id
	std::vector<AnimationFrame> frames;
	enum class AnimationLoopTypes loopType;
	int fps; //frame�� �ٲٴ� �ӵ�

	bool LoadFromFile(const string& path);
};