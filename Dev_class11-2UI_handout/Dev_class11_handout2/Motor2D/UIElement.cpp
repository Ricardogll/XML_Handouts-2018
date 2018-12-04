#include "UIElement.h"
#include "j1App.h"
#include "j1Textures.h"
//#include "p2Log.h"

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

	bool mouse_inside_rect = false;

	if (rect.x <= mouse_x && mouse_x <= rect.x + rect.w && rect.y <= mouse_y && mouse_y <= rect.y + rect.h) {
		//mouse inside rect
		mouse_inside_rect = true;
	

		switch (mouse_click)
		{
		case MouseState::DOWN_CLICK:
			mouse_state = MouseState::DOWN_CLICK;
			//LOG("DOWNCLICK");
			break;

		case MouseState::REPEAT_CLICK:
			mouse_state = MouseState::REPEAT_CLICK;
			//LOG("REPEATCLICK");
			break;

		case MouseState::UP_CLICK:
			mouse_state = MouseState::UP_CLICK;
			//LOG("UPCLICK");
			break;

		default:
			mouse_state = MouseState::HOVERING;
			//LOG("HOVERING");
			break;
		}


		if (prev_mouse_state == MouseState::ON_ENTER) {
			mouse_state = MouseState::HOVERING;
			//LOG("HOVERING AFTER ON ENTER");
		}

		if (prev_mouse_state == MouseState::NONE) {
			mouse_state = MouseState::ON_ENTER;
			//LOG("ON ENTER");
		}
	}


	if ((prev_mouse_state == MouseState::HOVERING || prev_mouse_state == MouseState::ON_ENTER) && !mouse_inside_rect) {
		mouse_state = MouseState::ON_LEAVE;
		//LOG("ON LEAVE");
	}
	
	prev_mouse_state = mouse_state;

	return mouse_state;
}

void UIElement::SetText(const char * text)
{
	
}