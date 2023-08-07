#include "stdafx.h"
#include "Player2.h"
#include "InputMgr.h"
#include "Framework.h"
#include "ResourceMgr.h"

void Player2::Init()
{
	SpriteGo::Init();
	/*std::string textureId = "graphics/RubySheet.png";*/
	std::string textureId = "graphics/farmer_base.png";

	animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/player_Idle.csv"));

	/*animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/IdleFront.csv"));
	animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/IdleLeft.csv"));
	animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/MoveLeft.csv"));
	animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/MoveBack.csv"));
	animation.AddClip(*RESOURCE_MGR.GetAnimationClip("tables/MoveFront.csv"));*/
	sprite.setScale(5.f, 5.f);
	animation.SetTarget(&sprite);

	SetOrigin(Origins::BC);
	
	/*clipInfos.push_back({ "IdleLeft", "MoveLeft", false, Utils::Normalize({ -1.f, -1.f }) });
	clipInfos.push_back({ "IdleBack", "MoveBack", true, {0.f, -1.f} });
	clipInfos.push_back({ "IdleLeft", "MoveLeft", true, Utils::Normalize({ 1.f, -1.f }) });

	clipInfos.push_back({ "IdleLeft", "MoveLeft", false, {-1.f, 0.f} });
	clipInfos.push_back({ "IdleLeft", "MoveLeft", true, {1.f, 0.f} });

	clipInfos.push_back({ "IdleLeft", "MoveLeft", false, Utils::Normalize({ -1.f, 1.f }) });
	clipInfos.push_back({ "IdleFront", "MoveFront", true,{0.f, 1.f} });
	clipInfos.push_back({ "IdleLeft", "MoveLeft", true, Utils::Normalize({ 1.f, 1.f }) });*/

}

void Player2::Reset()
{
	animation.Play("Idle");
	SetOrigin(origin);
	SetPosition({ 0, 0 });
	
	SetFlipX(false);

	//currentClipInfo = clipInfos[6];
}

void Player2::Update(float dt)
{
	//ÀÌµ¿
	/*direction.x = INPUT_MGR.GetAxis(Axis::Horizontal);
	direction.y = INPUT_MGR.GetAxis(Axis::Vertical);
	float magnitude = Utils::Magnitude(direction);
	if (magnitude > 1.f)
	{
		direction /= magnitude;
	}

	position += direction * speed * dt;
	SetPosition(position);

	if (direction.x != 0.f || direction.y != 0.f)
	{
		auto min = std::min_element(clipInfos.begin(), clipInfos.end(),
			[this](const ClipInfo& lhs, const ClipInfo& rhs) {
				return Utils::Distance(lhs.point, direction) < Utils::Distance(rhs.point, direction);
			});
		currentClipInfo = *min;
	}

	std::string clipId = magnitude == 0.f ? currentClipInfo.idle : currentClipInfo.move;
	if (GetFlipX() != currentClipInfo.flipX)
	{
		SetFlipX(currentClipInfo.flipX);
	}

	if (animation.GetCurrentClipId() != clipId)
	{
		animation.Play(clipId);
	}*/

	 
	animation.Update(dt);
}

bool Player2::GetFlipX() const
{
	return filpX;
}

void Player2::SetFlipX(bool filp)
{
	filpX = filp;

	sf::Vector2f scale = sprite.getScale();
	scale.x = !filpX ? abs(scale.x) : -abs(scale.x);
	sprite.setScale(scale);
}