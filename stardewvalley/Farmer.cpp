#include "stdafx.h"
#include "Farmer.h"
#include "InputMgr.h"
#include "Framework.h"
#include "ResourceMgr.h"

Farmer::Farmer(const std::string name)
	:GameObject(name)
{
}

void Farmer::Init()
{
	bodyAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/player_Idle.csv"));
	bodyAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/player_Move.csv"));

	bodyAnimation.SetTarget(&body);

	shirtAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/playershirt_Idle.csv"));
	shirtAnimation.SetTarget(&shirt);

	pentsAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/playerpents_Move.csv"));
	pentsAnimation.SetTarget(&pents);

	armAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/playerarm_Idle.csv"));
	armAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/playerarm_Move.csv"));
	armAnimation.SetTarget(&arm);

	heirAnimation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/playerheir_Idle.csv"));
	heirAnimation.SetTarget(&heir);

	SetOrigin(Origins::BC);

}

void Farmer::Reset()
{
	bodyAnimation.Play("Move");
	armAnimation.Play("Move");
	shirtAnimation.Play("Idle");
	pentsAnimation.Play("Move");
	heirAnimation.Play("Idle");

	SetPosition(0.0f, 0.0f);
	SetOrigin(origin);
	body.setScale(5.f, 5.f);
	shirt.setScale(5.f, 5.f);
	arm.setScale(5.f, 5.f);
	heir.setScale(5.f, 5.f);
	pents.setScale(5.f, 5.f);
}

void Farmer::Update(float dt)
{
	bodyAnimation.Update(dt);
	shirtAnimation.Update(dt);
	armAnimation.Update(dt);
	heirAnimation.Update(dt);
	pentsAnimation.Update(dt);
}

void Farmer::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(shirt);
	window.draw(pents);
	window.draw(arm);
	window.draw(heir);
}

void Farmer::Release()
{
}

void Farmer::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	body.setPosition(position);
	shirt.setPosition(position);
	arm.setPosition(position);
	heir.setPosition(position);
	pents.setPosition(position);
}

void Farmer::SetPosition(float x, float y)
{
	GameObject::SetPosition(x, y);
	body.setPosition(x, y);
	shirt.setPosition(x, y);
	arm.setPosition(x, y);
	heir.setPosition(x, y);
	pents.setPosition(x,y);
}

void Farmer::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(body, Origins::BC); 
		Utils::SetOrigin(shirt, Origins::BC);
		Utils::SetOrigin(arm, Origins::BC); 
		Utils::SetOrigin(heir, Origins::BC);
		Utils::SetOrigin(pents, Origins::BC);
	}
}

void Farmer::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	body.setOrigin(x, y);
	shirt.setOrigin(x, y);
	arm.setOrigin(x,y);
	heir.setOrigin(x, y);
	pents.setOrigin(x, y);
}
