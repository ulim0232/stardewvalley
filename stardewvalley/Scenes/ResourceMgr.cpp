#include "stdafx.h"
#include "ResourceMgr.h"

ResourceMgr::~ResourceMgr()
{
	UnLoadAll();
}
void ResourceMgr::Load(ResourceTypes t, const string path)
{
	switch (t)
	{
	case ResourceTypes::Texture:
	{
		auto it = mapTexture.find(path);
		if (mapTexture.end() == it)
		{
			auto texture = new sf::Texture;
			texture->loadFromFile(path);
			mapTexture.insert({ path, texture });
		}
	}
	break;
	case ResourceTypes::Font:
	{
		auto it = mapFont.find(path);
		if (mapFont.end() == it)
		{
			auto font = new sf::Font;
			font->loadFromFile(path);
			mapFont.insert({ path, font });
		}
	}
	break;
	case ResourceTypes::SoundBuffer:
	{
		auto it = mapSoundBuffer.find(path);
		if (mapSoundBuffer.end() == it)
		{
			auto soundBuffer = new sf::SoundBuffer;
			soundBuffer->loadFromFile(path);
			mapSoundBuffer.insert({ path, soundBuffer });
		}
	}
	break;
	}
}

void ResourceMgr::Load(const vector<tuple<ResourceTypes, string>>& array)
{
	for (const auto& tuple : array)
	{
		Load(get<0>(tuple), get<1>(tuple));//tuple�� ����ִ� ���ҽ� Ÿ��, 2���� string
	}
}

void ResourceMgr::UnLoad(ResourceTypes t, const string path)
{
	switch (t)
	{
	case ResourceTypes::Texture:
	{
		auto it = mapTexture.find(path); //���ͷ����͸� �޾ƿ�
		if (it != mapTexture.end())
		{
			delete it->second; //���ͷ������� �� ����ϴ� ���
			mapTexture.erase(it);
		}
	}
	case ResourceTypes::Font:
	{
		auto it = mapFont.find(path);
		if (it != mapFont.end())
		{
			delete it->second;
			mapFont.erase(it);
		}
	}
	case ResourceTypes::SoundBuffer:
	{
		auto it = mapSoundBuffer.find(path);
		if (it != mapSoundBuffer.end())
		{
			delete it->second;
			mapSoundBuffer.erase(it);
		}
	}
	}
}

void ResourceMgr::UnLoad(const vector<tuple<ResourceTypes, string>>& array)
{
	for (const auto& tuple : array)
	{
		UnLoad(get<0>(tuple), get<1>(tuple));//tuple�� ����ִ� ���ҽ� Ÿ��, 2���� string
	}
}

void ResourceMgr::UnLoadAll()
{
	//map ��ȸ ���
	for (auto pair : mapTexture)
	{
		delete pair.second;  //value ����, first: key, second: value
	}
	mapTexture.clear();
	for (auto pair : mapFont)
	{
		delete pair.second;
	}
	mapFont.clear();
	for (auto pair : mapSoundBuffer)
	{
		delete pair.second;
	}
	mapSoundBuffer.clear();
}

sf::Texture* ResourceMgr::GetTexture(const string& id)
{
	auto it = mapTexture.find(id);
	if (it != mapTexture.end()) 
	//mapTexture.end()�� �������� ���� ��, �� ���� ��
	{
		return it->second;
	}
	return nullptr;
}

sf::Font* ResourceMgr::GetFont(const string& id)
{
	auto it = mapFont.find(id);
	if (it != mapFont.end())
	{
		return it->second;
	}
	return nullptr;
}

sf::SoundBuffer* ResourceMgr::GetSoundBuffer(const string& id)
{
	auto it = mapSoundBuffer.find(id);
	if (it != mapSoundBuffer.end())
	{
		return it->second;
	}
	return nullptr;
}
