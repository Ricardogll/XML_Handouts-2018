#ifndef __UIIMAGE__
#define __UIIMAGE__

#include "UIElement.h"


class UIImage : public UIElement {

public:
	UIImage(int x, int y, SDL_Rect rect);
	~UIImage();
	void Draw(SDL_Texture* atlas);

private:
	//SDL_Rect img_rect;
};

#endif // !_UILABEL__
