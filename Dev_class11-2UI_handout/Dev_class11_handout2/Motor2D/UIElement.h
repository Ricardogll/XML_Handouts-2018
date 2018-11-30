#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "j1Gui.h"
//#include "SDL/include/SDL_rect.h"
#include "SDL/include/SDL.h"



struct SDL_Texture;


enum class MouseState {

	DOWN_CLICK,
	UP_CLICK,
	REPEAT_CLICK,
	HOVERING,
	ON_ENTER,
	ON_LEAVE,
	NONE

};

class UIElement {

public:

	//SDL_Rect rect;
	UIType type = NONE_UI;
	SDL_Rect rect = { 0,0,0,0 };
	bool clickable=false;
	MouseState mouse_state = MouseState::NONE;
	MouseState prev_mouse_state = MouseState::NONE;
	int pos_x = 0;
	int pos_y = 0;
	SDL_Texture* texture;
	SDL_Rect img_rect = { 0,0,0,0 };
	const char* text;
	_TTF_Font* current_font;




public:
	UIElement() {};
	UIElement(int x, int y, UIType type);

	virtual ~UIElement();

	virtual void Start();
	virtual void Draw(SDL_Texture* texture);
	virtual void Update();
	MouseState CheckMouseState(int mouse_x, int mouse_y, MouseState mouse_click);//change this for a general method on gui that checks if there is an element under the mouse?
	virtual void SetText(const char * text);

};

#endif // !__UIELEMENT_H__
