#include "stdafx.h"
#include "AnimationController.h"
#include "ResourceMgr.h"

void AnimationController::AddClip(const AnimationClip& newClip)
{
	if (clips.find(newClip.id) == clips.end()) //���� ��� end ������
	{
		clips.insert({ newClip.id, newClip });
	}
}

void AnimationController::Update(float dt)
{
	if (!isPlaying)
		return;

	accumTime += dt * speed; //speed�� ���� ��� �ӵ� ���� ����
	if (accumTime < clipDuration)
		return;

	//clip ����
	accumTime = 0;
	currentFrame++;

	if (currentFrame == totalFrame) //������ �����ӱ��� ����Ǿ��� ��
	{
		if (!queue.empty())
		{
			std::string id = queue.front(); //���� ���� ��� ��
			queue.pop();
			Play(id, false); //true�̸� queue�� ���� ������ false
			return;
		}
		else
		{
			switch (currentClip->loopType)
			{
			case AnimationLoopTypes::Single:
				currentFrame = totalFrame - 1; //������ ������ ����
				return;
			case AnimationLoopTypes::Loop:
				currentFrame = 0; //ù ���������� ���ư���
				break;
			}
		}
	}
	
	if (currentClip->frames[currentFrame].action != nullptr) 
		//�����ϰ� ���� ������ nullptr������
	{
		currentClip->frames[currentFrame].action(); 
		//����, ��ü�� �Լ�ó�� ����� �� �ִ�
	}

	if (target != nullptr)
	{
		//texture ��ü
		SetFrame(currentClip->frames[currentFrame]);
	}
}

void AnimationController::Play(const std::string& clipid, bool clearQueue)
{
	if (clearQueue)
	{
		while(!queue.empty())
		{
			queue.pop();
		}
	}
	auto find = clips.find(clipid);
	if (find == clips.end()) //����, ���� ���� ���� ��� find �Լ��� end����
	{
		Stop();
		std::cout << "ERR:: NOT EXIST CLIP" << std::endl;
		return;
	}

	isPlaying = true;
	currentClip = &find->second;
	currentFrame = 0;
	totalFrame = (int)currentClip->frames.size();
	clipDuration = 1.f / currentClip->fps;
	accumTime = 0.f;

	SetFrame(currentClip->frames[currentFrame]);
}

void AnimationController::PlayQueue(const std::string& clipid)
{
	queue.push(clipid);
}

void AnimationController::Stop()
{
	isPlaying = false;
}

string AnimationController::GetCurrentClipId()
{
	if (currentClip == nullptr)
	{
		return "";
	}
	return currentClip->id;
}

void AnimationController::SetFrame(const AnimationFrame& frame)
{
	sf::Texture* tex = RESOURCE_MGR.GetTexture(frame.textureId);

	target->setTexture(*tex);
	target->setTextureRect(frame.texCoord);
}
