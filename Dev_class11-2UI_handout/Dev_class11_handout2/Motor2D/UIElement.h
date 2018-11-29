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
	HOVER,
	NONE

};

class UIElement {

public:

	//SDL_Rect rect;
	UIType type = NONE_UI;
	bool clickable=false;
	MouseState mouse_state = MouseState::NONE;
	int pos_x = 0;
	int pos_y = 0;
	SDL_Texture* texture;
	const char* text;




public:
	UIElement() {};
	UIElement(int x, int y, UIType type);

	virtual ~UIElement();

	virtual void Start();
	virtual void Draw(SDL_Texture* texture);
	virtual void Update();
	virtual void CheckMouseState();//change this for a general method on gui that checks if there is an element under the mouse?


};

#endif // !__UIELEMENT_H__
