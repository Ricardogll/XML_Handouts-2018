#ifndef __UIIMAGE_NO_ATLAS__
#define __UIIMAGE_NO_ATLAS__

#include "UIElement.h"


class UIImageNoAtlas : public UIElement {

public:
	UIImageNoAtlas(int x, int y, SDL_Rect rect, SDL_Texture* tex);
	~UIImageNoAtlas();
	void Draw(SDL_Texture* atlas);

private:
	//SDL_Rect img_rect;
};

#endif // !_UILABEL__
