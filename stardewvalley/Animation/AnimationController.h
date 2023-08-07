#pragma once
/**/
class AnimationController
{
protected:
	std::unordered_map<std::string, AnimationClip> clips; //Ŭ���� id, Ŭ��
	std::queue<std::string> queue;
	
	float speed = 1.f; //�ִϸ��̼� ��� �ӵ�, 2�� 2�� ������

	AnimationClip* currentClip = nullptr; //���� ����ϰ� �ִ� Ŭ���� ������
	int currentFrame = -1; //���� ����ϴ� Ŭ���� ������� �� ��° �������� 
	int totalFrame = 0;
	float clipDuration = 0.f; //Ŭ���� ����� �ð�
	float accumTime = 0.f;
	
	bool isPlaying = false;

	sf::Sprite* target = nullptr; //�ִϸ��̼��� ����� ��������Ʈ ��ü

public:
	void AddClip(const AnimationClip& newClip);
	void SetTarget(sf::Sprite* sprite) { target = sprite; }
	sf::Sprite* GetTarget() const { return target; }
	bool IsPlaying() { return isPlaying; }
	void SetSpeed(float s) { speed = s; }
	float GetSpeed() { return speed;  }

	void Update(float dt);

	void Play(const std::string& clipid, bool clearQueue = true);
	void PlayQueue(const std::string& clipid); //queue�� ��� �뵵�� ���
	void Stop();
	
	string GetCurrentClipId();
	void SetFrame(const AnimationFrame& frame);
};

