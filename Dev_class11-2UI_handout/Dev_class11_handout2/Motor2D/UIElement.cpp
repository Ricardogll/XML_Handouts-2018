#include "UIElement.h"
#include "j1App.h"
#include "j1Textures.h"

UIElement::UIElement(int x, int y, UIType type) : pos_x(x), pos_y(y), type(type)
{

}

UIElement::~UIElement()
{
	App->tex->UnLoad(texture);
}

void UIElement::Start()
{
}

void UIElement::Draw(SDL_Texture* texture)
{
}

void UIElement::Update()
{
}

MouseState UIElement::CheckMouseState(int mouse_x, int mouse_y, MouseState mouse_click)
{
	mouse_state = MouseState::NONE;

	if (rect.x <= mouse_x && mouse_x <= rect.x + rect.w && rect.y <= mouse_y && mouse_y <= rect.y + rect.h) {
		//mouse inside rect

	

		switch (mouse_click)
		{
		case MouseState::DOWN_CLICK:
			mouse_state = MouseState::DOWN_CLICK;
			break;

		case MouseState::REPEAT_CLICK:
			mouse_state = MouseState::REPEAT_CLICK;
			break;

		case MouseState::UP_CLICK:
			mouse_state = MouseState::UP_CLICK;
			break;

		default:
			mouse_state = MouseState::HOVERING;
			break;
		}

		if (prev_mouse_state == MouseState::ON_ENTER)
			mouse_state = MouseState::HOVERING;

		if (prev_mouse_state != MouseState::HOVERING)
			mouse_state = MouseState::ON_ENTER;
	}


	if (prev_mouse_state == MouseState::HOVERING || prev_mouse_state == MouseState::ON_ENTER)
		mouse_state = MouseState::ON_LEAVE;
	
	prev_mouse_state = mouse_state;

	return mouse_state;
}

void UIElement::SetText(const char * text)
{
	
}