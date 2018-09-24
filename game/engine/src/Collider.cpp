#include "Collider.hpp"
#include "GameObject.hpp"

#ifdef DEBUG
#include "Camera.hpp"
#include "Game.hpp"

#include "EngineSDL.hpp"
#endif // DEBUG

Collider::Collider(GameObject& associated, Vec2 scale, Vec2 offset) : Component(associated), scale(scale), offset(offset)
{

}

void Collider::Start()
{

}

void Collider::Update(float dt)
{
    box.w = associated.box.w * scale.x;
	box.h = associated.box.h * scale.y;

	offset.Rotate(associated.angleDeg * (180 / M_PI));
	box.x = associated.box.Center().x + offset.x - box.w / 2;
    box.y = associated.box.Center().y + offset.y - box.h / 2;    
}

void Collider::Render()
{
#ifdef DEBUG
	Vec2 center(box.Center());
	SDL_Point points[5];

    Vec2 angle = (Vec2(box.x, box.y) - center);
    angle.Rotate(associated.angleDeg/(180/M_PI));
	Vec2 point = angle + center - Camera::pos;
	points[0] = {(int)point.x, (int)point.y};
	points[4] = {(int)point.x, (int)point.y};
	
    angle = (Vec2(box.x + box.w, box.y) - center);
    angle.Rotate(associated.angleDeg/(180/M_PI));
	point = angle + center - Camera::pos;
	points[1] = {(int)point.x, (int)point.y};
	
    angle = (Vec2(box.x + box.w, box.y + box.h) - center);
    angle.Rotate(associated.angleDeg/(180/M_PI));
	point = angle + center - Camera::pos;
	points[2] = {(int)point.x, (int)point.y};
	
    angle = (Vec2(box.x, box.y + box.h) - center);
    angle.Rotate(associated.angleDeg/(180/M_PI));
	point = angle + center - Camera::pos;
	points[3] = {(int)point.x, (int)point.y};

	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLines(Game::GetInstance().GetRenderer(), points, 5);
#endif // DEBUG
}

bool Collider::Is(std::string type)
{
    return type == "Collider";
}

void Collider::SetScale(Vec2 scale)
{
    this->scale = scale;
}
        
void Collider::SetOffset(Vec2 offset)
{
    this->offset = offset;
}