#pragma once
#include "Singleton.h"

class ResourceMgr : public Singleton<ResourceMgr>
{
	friend Singleton<ResourceMgr>;

protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr() override;

	map<string, sf::Texture*> mapTexture;
	map<string, sf::Font*> mapFont;
	map<string, sf::SoundBuffer*> mapSoundBuffer;

public:
	//loadm unload�� Ÿ�Ժ��� �ٸ� �Լ��� ����� ���� ����
	void Load(ResourceTypes t, const string path); //map�� �����͸� �ִ� �Լ�
	void Load(const vector<tuple<ResourceTypes, string >>& array);


	void UnLoad(ResourceTypes t, const string path); //��� path�� id�� ���
	void UnLoad(const vector<tuple<ResourceTypes, string >>& array);

	void UnLoadAll();

	sf::Texture* GetTexture(const string& id);
	sf::Font* GetFont(const string& id);
	sf::SoundBuffer* GetSoundBuffer(const string& id);
};

#define RESOURCE_MGR (ResourceMgr::Instance())
