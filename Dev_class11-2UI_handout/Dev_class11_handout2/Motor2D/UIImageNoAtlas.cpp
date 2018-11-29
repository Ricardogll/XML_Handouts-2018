#include "UIImageNoAtlas.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"

UIImageNoAtlas::UIImageNoAtlas(int x, int y, SDL_Rect rect, SDL_Texture* tex) :UIElement(x, y, IMAGE_NO_ATLAS)
{
	texture = tex;
	img_rect = rect;

}

UIImageNoAtlas::~UIImageNoAtlas()
{
}

void UIImageNoAtlas::Draw(SDL_Texture* atlas) {

	App->render->Blit(texture, pos_x, pos_y);

}